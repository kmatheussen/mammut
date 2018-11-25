
/* tempfile.c taken from ceres. */

#include <unistd.h>

#include "mammut.h"

#include "juce.h"

#include "tempfile.h"

/* MS Visual C Hack */
#ifdef _MSC_VER
#define snprintf _snprintf
#endif

#define USE_POSIX_FOR_FILE_OPERATIONS 1

static struct TempFile *tempfiles=NULL;


static bool freezepath=false;

enum{
  TF_NONOPEN=0,
    TF_READOPEN,
    TF_WRITEOPEN,
};

    

void TF_freezePath(void){
  freezepath=true;
}

void TF_unfreezePath(void){
  freezepath=false;
}

static bool TF_closefile(struct TempFile *tf){
  bool ret=true;
  if(tf->status!=TF_NONOPEN)
    ret=fclose(tf->file)==0?true:false;

  if(ret==false)
    printerror("Error. Could not close temporary file %s.",tf->name);

  return ret;
}

static bool TF_openfile(struct TempFile *tf,int mode){
  bool ret=true;

  if(tf->status==mode)
    return ret;

  TF_closefile(tf);

  if(mode==TF_READOPEN)
    tf->file=fopen(tf->name,"rb");
  if(mode==TF_WRITEOPEN)
    tf->file=fopen(tf->name,"wb");
  
  if(tf->file==NULL)
    ret=false;

  if(ret==false){
    printerror("Error. Could not open temporary file %s for %s.",tf->name,mode==TF_READOPEN?"reading":"writing");
    tf->status=TF_NONOPEN;
  }else
    tf->status=mode;

  return ret;
}


static bool TF_deleteFile(char *filename){
  bool ret;
#if(LINUX==1)
  if(USE_POSIX_FOR_FILE_OPERATIONS && SystemStats::getOperatingSystemType()==SystemStats::Linux){
    ret=unlink(filename)==0?true:false;
  }else
#endif
    ret=File(filename).deleteFile();

  if(ret==false)
    printerror("Unable to delete file %s",filename);

  return ret;
}



#if(LINUX==1)

/* The return string should be freed after use. */
static char *TF_getPath(void){
  char *ret=(char*)erroralloc(1000);

#if(LINUX==1)
  if(USE_POSIX_FOR_FILE_OPERATIONS && SystemStats::getOperatingSystemType()==SystemStats::Linux){
    sprintf(ret, "%s/", TEMPDIR );
  }else
#endif
    sprintf(ret,"%s",File::getSpecialLocation(File::tempDirectory).getFullPathName().toRawUTF8());


  return ret;
}
#endif


void TF_delete(struct TempFile *tf){
  struct TempFile *tempfile=tempfiles;
  struct TempFile *prev=NULL;

  while(tempfile!=NULL){
    if(tempfile==tf){
      if(prev==NULL){
	tempfiles=tempfiles->next;
      }else{
	prev->next=tempfile->next;
      }
      TF_closefile(tf);
      TF_deleteFile(tf->name);
      free(tf->name);
      free(tf);
      return;
    }
    prev=tempfile;
    tempfile=tempfile->next;
  }

  printerror("Error in file tempfile.c function TF_delete: Could not find tempfile\n");
}


void TF_cleanup(void){
  //PlayStopHard();
  while(tempfiles!=NULL){
    TF_delete(tempfiles);
  }
}

void TF_cleanup_exit(void){
  fprintf(stderr,"Cleaning up.\n");
  TF_cleanup();
}

bool TF_read(struct TempFile *tf,void *dest,size_t size1,size_t size2){
  size_t numread;

  if(TF_openfile(tf,TF_READOPEN)==false)
    return false;

  numread=fread(
		dest,
		size1,size2,
		tf->file
		);
  
  if(numread!=size2){
    printerror("Serious error.\n\nTrouble reading data from temporary file \"%s\" (%d!=%d)",
	       numread,size2);
    return false;
  }
  return true;
}

bool TF_write(struct TempFile *tf,void *source,size_t size1,size_t size2){
  size_t numread;

  if(TF_openfile(tf,TF_WRITEOPEN)==false)
    return false;

  numread=fwrite(
		 source,
		 size1,size2,
		 tf->file
		 );

  if(numread!=size2){
    printerror("Serious error.\n\nTrouble writing data to temporary file \"%s\" (%d!=%d)",
	       numread,size2);
    return false;
  }
  return true;
}

struct TempFile *TF_new(char *firstname){
  char temp[5000];
  struct TempFile *tf;

#if(LINUX==1)
  if(USE_POSIX_FOR_FILE_OPERATIONS && SystemStats::getOperatingSystemType()==SystemStats::Linux){

    char *dir=TF_getPath();
    
    sprintf(temp,"%smammut_tmp-%s-XXXXXX",dir,firstname);
    free(dir);
    
    mkstemp(temp);
  }else
#endif
    {
      File temptempfile=File::createTempFile("mammut_temp");
      snprintf(temp,4990,"%s",temptempfile.getFullPathName().toRawUTF8());
      printf("Creating new tempfile \"%s\"n",temp);
      //temptempfile.deleteFile();
    }


  tf=(struct TempFile*)erroralloc(sizeof(struct TempFile));

  tf->next=tempfiles;
  tf->name=(char*)erroralloc(strlen(temp)+1);
  sprintf(tf->name,"%s",temp);

  tempfiles=tf;

  return tf;
}


#if 0

// Don't worry about the highly non-portable cp command. This function is not used in mammut. -Kjetil.
struct TempFile *TF_makeCopy(char *firstname,struct TempFile *from){
  struct TempFile *to=TF_new(firstname);
  char temp[1024];

  printerror("Warning! TF_makeCopy will probably not work in Windows.");

  fclose(to->file);

  TF_deleteFile(to->name);

  sprintf(temp,"cp %s %s",from->name,to->name);
  if(system(temp)!=0){
    printerror("Unable to make a copy of undo data. Command failing was: \"%s\"",temp);
    //    from->file=fopen(from->name,"rwb+");
    to->file=fopen(to->name,"rwb+");
    TF_delete(to);
    return NULL;
  }

  //  from->file=fopen(from->name,"rwb+");
  to->file=fopen(to->name,"rwb+");

  return to;
}

#endif



void create_tempfile(void){
  atexit(TF_cleanup_exit);
}

