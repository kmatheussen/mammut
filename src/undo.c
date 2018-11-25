
#include "mammut.h"
#include "tempfile.h"

//#include "play.h"

#include "undo.h"

/*
  Undo code copied from ceres.
*/


#define UNDOLYD 0

struct Undo{
  struct Undo *prev;
  struct Undo *next;
  int type;  
  int num;
};

struct Undo_lyd{
  struct Undo undo;
  struct TempFile *lydfile;
};

static struct Undo UndoRoot={};
static struct Undo *CurrUndo=&UndoRoot;
static int num_undos=0;
static int undonum=0;
static int doundo=2;

bool unlimited_undo=false;
bool enable_undo=true;
int max_number_of_undos=300000; // Used when unlimited undo is false.

static int UNDO_getMaxNumUndos(void){
  if(unlimited_undo==true){
    return 0;
  }
  return max_number_of_undos;
}

void UNDO_cleanup(void){
  while(CurrUndo->next!=NULL){
    struct Undo_lyd *ut=(struct Undo_lyd*)CurrUndo->next;
    struct Undo *temp=CurrUndo->next->next;

    TF_delete(ut->lydfile);

    free(ut);

    CurrUndo->next=temp;
  }
}



void UNDO_Reset(void){

  CurrUndo=&UndoRoot;
  num_undos=0;

  UNDO_cleanup();
}

int UNDO_getDoUndo(void){
  return doundo;
}

void UNDO_setDoUndo(int dasdoundo){
  doundo=dasdoundo;
}

bool UNDO_allowedToDoUndo(void){
  if(doundo==0 || (doundo==2 && enable_undo==false)){
    return false;
  }
  return true;
}

bool UNDO_allowedUndo(void){
  if(CurrUndo==&UndoRoot) return false;
  return true;
}

bool UNDO_allowedRedo(void){
  if(CurrUndo->next==NULL) return false;
  return true;
}

char *UNDO_addLyd(void){
  struct Undo_lyd *undo_lyd;
  struct Undo *undo;
  //int len;

  if(doundo==0 || (doundo==2 && enable_undo==false))
    return NULL;

  if(UNDO_allowedToDoUndo()==false)
    return NULL;

  undo_lyd=erroralloc(sizeof(struct Undo_lyd));
  MC_stop();
  undo_lyd->lydfile=TF_new("lyd");
  if(undo_lyd->lydfile==NULL){
    free(undo_lyd);
    return NULL;
  }

  if(TF_write(undo_lyd->lydfile,lyd,N,samps_per_frame*sizeof(float))==false){
    printerror("Could not make undo.\n");
    TF_delete(undo_lyd->lydfile);
    free(undo_lyd);
    return "Could not make undo, problem saving data.";
  }

  undo=&undo_lyd->undo;

  undo->prev=CurrUndo;

  while(CurrUndo->next!=NULL){
    struct Undo_lyd *ut=(struct Undo_lyd*)CurrUndo->next;
    struct Undo *temp=CurrUndo->next->next;

    TF_delete(ut->lydfile);
    free(ut);

    CurrUndo->next=temp;
  }

  CurrUndo->next=undo;
  CurrUndo=undo;

  undo->type=UNDOLYD;
  undo->num=undonum;

  num_undos++;
  undonum++;

  while(num_undos!=0 && num_undos>UNDO_getMaxNumUndos()){
    struct Undo_lyd *ut=(struct Undo_lyd*)UndoRoot.next;
    struct Undo *temp=UndoRoot.next->next;

    TF_delete(ut->lydfile);
    free(ut);

    num_undos--;
    UndoRoot.next=temp;
    UndoRoot.next->prev=&UndoRoot;
  }

  return NULL;
}


static void UNDO_doInternal(void){
  struct Undo *undo;
  struct Undo_lyd *ut;
  struct TempFile *temp;
  //int len;

  undo=CurrUndo;
  ut=(struct Undo_lyd*)undo;

  temp=TF_new("lyd");
  if(temp==NULL)
    return;

  if(TF_write(temp,lyd,N,samps_per_frame*sizeof(float))==false){
    printerror("Problem making redo\n");
  }

  //ut->lydfile->file=fopen(ut->lydfile->name,"rb");
  //fseek(ut->lydfile->file,0,SEEK_SET);

  MC_stop();

  TF_read(ut->lydfile,lyd,N,sizeof(float)*samps_per_frame);

  TF_delete(ut->lydfile);
  ut->lydfile=temp;

  CurrUndo=undo->prev;
  num_undos--;

}

void UNDO_do(void){
  if(UNDO_allowedUndo()==false) return;


  UNDO_doInternal();

  //  RedrawAll(fftsound);
  
  RedrawWin();

  //ResetCursor(topLevel);

  //  EDIT_setUndoRedoMenues();  

}

void UNDO_do_noredraw(void){
  if(UNDO_allowedUndo()==false) return;


  UNDO_doInternal();

  //  RedrawAll(fftsound);
  
  //RedrawWin();

  //ResetCursor(topLevel);

  //  EDIT_setUndoRedoMenues();  

}

void UNDO_redo(void){


  if(UNDO_allowedRedo()==false) return;
  
  CurrUndo=CurrUndo->next;
  UNDO_doInternal();
  CurrUndo=CurrUndo->next;
  
  num_undos+=2;
  
  RedrawWin();
  
  //ResetCursor(topLevel);
  
  //  EDIT_setUndoRedoMenues();
}


void createUndo(void){
  //  fftsound_here=fftsound;
  //  mainpid=getpid();
  //  atexit(UNDO_cleanup);
}

