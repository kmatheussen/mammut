
#include "mammut.h"


/* Following code copied from Ceres. */

struct LoadStruct loadstruct;



/* ly=destination, spf=samples per frame. */

void readsound(struct LoadStruct *ls,float *ly, int channels)
{
  int ch;

  static int lastchannels=0;
  static float *val3 = NULL;
  if(ls->sfinfo.channels>lastchannels){
    free(val3);
    val3 = malloc (sizeof(float)*(ls->sfinfo.channels*8192));
    lastchannels=ls->sfinfo.channels;
  }

  for(ch=0;ch<channels;ch++){
    float *l=ly+(ch*N);
    int sampsread;
    int r=0;
    sf_seek(ls->infile,0,SEEK_SET);
    do{
      int ret,lokke;
      
      ret=sf_readf_float(ls->infile,val3,8192);
      for(lokke=0;lokke<ret;lokke++)
	*(l+r+lokke)=val3[ch+lokke*ls->sfinfo.channels];

      sampsread=ret;

      r+=sampsread;
    }while(sampsread>0);
  }

}



static char *das_loadana(char *filename)
{
  int i,ch;
  SNDFILE *infile;

  SF_INFO *sfinfo=&loadstruct.sfinfo;

  memset(sfinfo,0,sizeof(SF_INFO));

  infile=sf_open_read(filename,sfinfo);

  loadstruct.infile=infile;

  if (infile==NULL) {
    return "Could not open file";
  }

  samps_per_frame   = sfinfo->channels;
  R                 = sfinfo->samplerate;

  framecnt          = sfinfo->MSF_FRAMENAME;

  /*
  if (framecnt >  50000000) {
    fprintf(stderr, "Soundfile too large\n");
    afCloseFile(infile); 
    return false;
  }
  */


  N=1;
  while (N<framecnt)
    N*=2;
  for (i=0; i<dobler; i++)
    N*=2;

  duration = (float)framecnt/R;
  binfreq = (float)R/N;
  if (lyd!=NULL) free(lyd);
  lyd=NULL;

  //printf("N: %d, framecnt: %d, dobler: %d, samps_per_frame: %d, sfinfo->channels: %d, R: %d\n",N,framecnt,dobler,samps_per_frame,sfinfo->channels,R);

  fvec(lyd, N*samps_per_frame);

  if (lyd2!=NULL) free(lyd2);
  lyd2=NULL;
  fvec(lyd2, N*samps_per_frame);

  readsound(&loadstruct,lyd,samps_per_frame);

  sf_close(infile);

  for (ch=0; ch<samps_per_frame; ch++) {
    printf("CH: %d/%d\n",ch,samps_per_frame);
    GUI_aboveprogressbar(ch,samps_per_frame);
    rfft(lyd+ch*N,  N/2,  FORWARD);
  }

  strcpy(playfile, filename);

  //  printf("playfile: -%s-\n",playfile);

  return NULL;
}

static char *das_filename;
static char *das_ret;

void das_das_loadana(void){
  das_ret=das_loadana(das_filename);
}

char *loadana(char *filename){
  das_filename=filename;
  GUI_newprocess(das_das_loadana);
  RedrawWin();
  return das_ret;
}

