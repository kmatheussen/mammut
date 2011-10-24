
#ifndef MAMMUTHt
#define MAMMUTHt

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#ifdef __cplusplus
#  define LANGSPEC "C"
#else
#  define LANGSPEC
#endif

extern LANGSPEC int theheight;


//#include <audiofile.h>

#include "mysndfile.h"

#include "c_interface.h"

#ifdef min
#undef min
#endif
#define min(a,b) (((a)<(b))?(a):(b))


/* Following code copied from Ceres. */

struct LoadStruct{
  SNDFILE *infile;
  SF_INFO sfinfo;  
};




#undef MIN
#define MIN(a,b) ((a)<(b)?(a):(b))
#undef M_MAX
#define M_MAX(a,b) ((a)>(b)?(a):(b))

#define FORWARD 1
#define INVERSE 0


#define PI 3.141592654
#define TWOPI 6.2831853

/*
void gdk_draw_segments	 (GdkDrawable  *drawable,
			  GdkGC	       *gc,
			  GdkSegment   *segs,
			  gint		nsegs);

          XDrawSegments(theDisplay,bitmap,thGC,list,count);   \
*/

#define LSIZE 100
#define FLUSH_LIST(list, count, shoGC, thGC)        \
        gdk_draw_segments(pixmap,thGC,list,count); \
        gdk_draw_segments(drawing_area->window,thGC,list,count); \
        count=0

#define ADD_LINE(xx1, yy1, xx2, yy2, list, count, shoGC, thGC) \
      list[count].x1 = xx1;     \
      list[count].y1 = yy1;     \
      list[count].x2 = xx2;     \
      list[count++].y2 = yy2;     \
      if (count==LSIZE) { \
              FLUSH_LIST(list,count,shoGC, thGC);    \
      }

#define elephant_width 110
#define elephant_height 100

extern LANGSPEC void *outfile;

extern LANGSPEC int screen, defdepth;


extern LANGSPEC int samps_per_frame;  /* Mono/stereo */
extern LANGSPEC int compression,  filefmt,  bits_per_samp,  samp_type;
extern LANGSPEC int vers;
extern LANGSPEC long framecnt, N;

extern LANGSPEC float *lyd, *lyd2;

extern LANGSPEC float duration;		    /* Duration in secs */
extern LANGSPEC int numchannels;	    /* Number of FFT channels */
extern LANGSPEC float binfreq;		    /* Frequency pr. bin */
extern LANGSPEC int R;

extern LANGSPEC int playing, dobler, zoom, leftkc;
extern LANGSPEC char playfile[200];

extern LANGSPEC bool prefs_soundonoff;
extern LANGSPEC bool prefs_picture;
extern LANGSPEC bool prefs_animation;
extern LANGSPEC bool prefs_movingcamera;
extern LANGSPEC bool prefs_loop;

extern LANGSPEC bool isprocessing;

extern LANGSPEC void rfft(float x[], int N, int forward);
void bitreverse(float x[], int N);
char *loadana(char *filename);

void SaveWaveConsumer(
		      void *outfile,
		      float **samples,
		      int num_samples
		      );

void writesound(
		void (*WaveConsumer)(
				void *pointer,
				float **samples,
				int num_samples
				),
		void *pointer
		);
		
void PlayStopHard(void);
void Play(void);

void readsound(struct LoadStruct *ls,float *ly, int spf);


char *SaveOk(char *filename);

extern LANGSPEC float get_normalize_val(void);
extern LANGSPEC void normalize(void);


#define int_progval() int progvalval=0;int *volatile progval=&progvalval


//#ifdef __cplusplus
extern LANGSPEC void GUI_aboveprogressbar(int curr,int maxvalue);
extern LANGSPEC void GUI_progressbar(int minvalue,int newvalue,int maxvalue);
extern LANGSPEC void GUI_startprogressbar(int minvalue,int *valtocheck,int maxvalue);
extern LANGSPEC void GUI_stopprogressbar(void);
extern LANGSPEC void GUI_newprocess(void das_func(void));

extern LANGSPEC void GUI_addUndo(void);
extern LANGSPEC void RedrawWin(void);
//#endif
extern LANGSPEC void Transformit(void func(void));
extern LANGSPEC void ReTransformit(void das_func(void));

extern LANGSPEC void printerror(const char *fmt, ...);
extern LANGSPEC void *erroralloc(size_t size);

#define fvec(name, size)\
if ((name=(float *)erroralloc(size*sizeof(float)))==NULL) {\
  fprintf(stderr,"Insufficient memory. Tried to allocate %d * %d bytes. Exiting.\n",(int)size,(int)sizeof(float)); \
  exit(-10);								\
 }

#ifdef _MSC_VER
#define copysign(a,b) ((b)>0? fabs(a) : -fabs(a))
#define powf(a,b)    ((float)(pow((a),(b))))
#endif

#endif

