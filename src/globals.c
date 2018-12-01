
#include "mammut.h"


void *outfile;

int screen, defdepth;

int samps_per_frame=0;  /* Mono/stereo */
int compression,  filefmt,  bits_per_samp;
int  samp_type;
int  vers;
long framecnt, N=0;

float *lyd=NULL, *lyd2=NULL;

float duration;		    /* Duration in secs */
int numchannels;	    /* Number of FFT channels */
float binfreq;		    /* Frequency pr. bin */
int g_samplerate=44100;

int playing=0, theheight=400, dobler=0, zoom=0, leftkc=0;
char playfile[200];

bool isprocessing=false;

/* Prefs */

bool prefs_soundonoff=false;
bool prefs_picture=true;
bool prefs_animation=true;
bool prefs_movingcamera=true;
bool prefs_loop=true;

