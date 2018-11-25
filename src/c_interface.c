
#if defined(LINUX) || defined(FOR_MACOSX)
# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
#endif

#include "mammut.h"
#include "undo.h"
//#include "interface.h"
#include "tempfile.h"

//#include <Python.h>

//#include "mammut.xpm"

//#include "play.h"

#include "juceplay.h"


#if 0
typedef struct {
  PyObject_HEAD
  GtkObject *obj;
}tutt;
#endif


float stretch_floats[1];

#if 0
extern GdkColor bluecolor;
#endif

#if 0
PyObject *_wrap_MC_about(PyObject *self, PyObject *args){
  GtkWidget *hbox;
  GdkPixmap *elepixmap;
  GtkWidget *gtkpixmap;
  GdkBitmap *gdkbitmap;

  PyObject *resultobj;

  PyObject *obj1;
  GtkWidget *lab=gtk_label_new(""
			       "Mammut is a program for experimental\n"
			       "audio processing, using mammut FFT.\n"
			       "\n"
			       "Version 0.08, Oyvind Hammer 1998,1999\n"
			       "Version 0.22, Kjetil S. Matheussen / Notam 2002,2005\n"
			       "Please send your comments to\n"
			       "oyvindha@notam.uio.no.\n"
			       ""
			       );


  if(!PyArg_ParseTuple(args,(char *)"O:MC_about",&obj1)){
    return NULL;
  }

  hbox=(GtkWidget*)((tutt *)obj1)->obj;

  elepixmap=gdk_pixmap_create_from_xpm_d(hbox->window,&gdkbitmap,&bluecolor,(gchar **)noname);

  gtkpixmap=gtk_pixmap_new(elepixmap,gdkbitmap);

  gtk_label_set_justify(GTK_LABEL(lab),GTK_JUSTIFY_LEFT);

  gtk_container_add(GTK_CONTAINER(hbox),gtkpixmap);
  gtk_container_add(GTK_CONTAINER(hbox),lab);

  gtk_widget_show(hbox);
  gtk_widget_show(lab);
  gtk_widget_show(gtkpixmap);

  Py_INCREF(Py_None);
  resultobj = Py_None;

  return resultobj;
}
#endif


char *MC_loadAndAnalyze(char *filename){
  return loadana(filename);
}

char *MC_synthAndSave(char *filename){
  return SaveOk(filename);
}

void MC_play(void){
  juceplay_start();
  //Play();
}

void MC_stop(void){
  juceplay_stop();
  //PlayStopHard();
}

void MC_redrawWin(void){
  RedrawWin();
}

void MC_zoom(void){
  MC_stop();
  zoom=zoom==0?1:0;
  RedrawWin();
}

void MC_left(void){
  if(zoom==0 || leftkc==0) return;
  leftkc--;
  RedrawWin();
}

void MC_right(void){
  if(zoom==0 || leftkc==g_samplerate/2000) return;
  leftkc++;
  RedrawWin();
}

bool MC_isStereo(void){
  if (samps_per_frame==2){
    return true;
  }
  return false;
}

char *MC_addUndo(void){
  return UNDO_addLyd();
}

void MC_undo(void){
  UNDO_do();
}

void MC_redo(void){
  UNDO_redo();
}

void MC_resetUndo(void){
  UNDO_Reset();
}

#ifndef _WIN32
static pid_t mainpid;

void finish(int sig){
  if(getpid()==mainpid)
    TF_cleanup_exit();
  exit(0);
}
#endif


void MC_init(void){
#ifndef _WIN32
  mainpid=getpid();
  signal(SIGINT,finish);
#endif
  create_tempfile();

  //juceplay_init();

}

