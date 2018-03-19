
#include "mammut.h"

#include <stdint.h>

#ifdef _MSC_VER
#define strcasecmp stricmp
#endif

/* Default must be set because button is not made with glade. */

bool synthandsave_normalize_gain=false;



extern struct LoadStruct loadstruct;


/* Following function copied from Ceres. */

void SaveWaveConsumer(
		      void *outfile,
		      float **samples,
		      int num_samples
		      )
{
  int i,ch;
  
  static float *framebuff=NULL;
  static int framebuffsize=0;
  if( framebuffsize < (num_samples*samps_per_frame)){
    free(framebuff);
    framebuffsize=num_samples*samps_per_frame;
    framebuff = erroralloc (framebuffsize*sizeof(float));
  }

  for (i=0; i<num_samples; i++) {
    for (ch=0; ch<samps_per_frame; ch++)
      *(framebuff+i*samps_per_frame+ch)=(float)(samples[ch][i]);
  }
  if(sf_writef_float(outfile,framebuff,num_samples)!=num_samples){
    printerror("Mammut, error: Could not write to disk completely.\n");
  }
}



float get_normalize_val(void)
{
  int i, ch;
  float max, samp;
  float *l;
  max=-1e+10;
  for (ch=0; ch<samps_per_frame; ch++) {
    l=lyd+ch*N;
    for (i=0; i<N; i++) {
      samp=*(l+i);
      if (samp>max) max=samp;
      if (-samp>max) max=-samp;
    }
  }
  return max=0.9/max;
}

void normalize(){
  int i, ch;
  float *l;
  float max=get_normalize_val();
  for (ch=0; ch<samps_per_frame; ch++) {
    l=lyd+ch*N;
    for (i=0; i<N; i++) *(l+i)*=max;
  }

#if 0
  else if (max>0.99) {
    fprintf(stderr,"Can\'t save properly. Try to check the \"Normalize gain\" box.\n");
    return false;
  }
  return true;
#endif

}




void writesound(
		void (*WaveConsumer)(
				void *pointer,
				float **samples,
				int num_samples
				),
		void *pointer
		)
{
  int i, ch;
  float *l=lyd;

  static float **ly;
  static int lysize=0;
  if(lysize<samps_per_frame){
    lysize=samps_per_frame;
    free(ly);
    ly=erroralloc(sizeof(float*)*lysize);
  }

  if(synthandsave_normalize_gain)
    normalize();

  for(i=0;i<N;i+=1024){
    for(ch=0;ch<samps_per_frame;ch++){
      ly[ch]=l+i+(ch*N);
    }
    (*WaveConsumer)(pointer,ly,mammut_min(N-i,1024));
  }

}




static char *das_SaveOk(char *filename)
{

  long i,ch;

  /*
  out_AFsetup=afNewFileSetup();
  afInitChannels(out_AFsetup, AF_DEFAULT_TRACK, samps_per_frame);
  afInitRate(out_AFsetup, AF_DEFAULT_TRACK, R);
  afInitCompression(out_AFsetup, AF_DEFAULT_TRACK, compression);
  afInitFileFormat(out_AFsetup, filefmt);
  afInitSampleFormat(out_AFsetup, AF_DEFAULT_TRACK, samp_type, bits_per_samp);

  outfile=afOpenFile(filename, "wb", out_AFsetup);
  */

  
  SF_INFO* sfinfo_write=erroralloc(sizeof(SF_INFO));
  memcpy(sfinfo_write,&loadstruct.sfinfo,sizeof(SF_INFO));

  if(strcasecmp(".raw",filename+strlen(filename)-4)==0){
    sfinfo_write->format = 
      (sfinfo_write->format & SF_FORMAT_SUBMASK) 
      | (SF_FORMAT_RAW & SF_FORMAT_TYPEMASK);
  }
  if(strcasecmp(".wav",filename+strlen(filename)-4)==0){
    sfinfo_write->format = 
      (sfinfo_write->format & SF_FORMAT_SUBMASK) 
      | (SF_FORMAT_WAV & SF_FORMAT_TYPEMASK);
  }
  if(strcasecmp(".aif",filename+strlen(filename)-4)==0){
    sfinfo_write->format = 
      (sfinfo_write->format & SF_FORMAT_SUBMASK) 
      | (SF_FORMAT_AIFF & SF_FORMAT_TYPEMASK);
  }
  if(strcasecmp(".aiff",filename+strlen(filename)-5)==0){
    sfinfo_write->format = 
      (sfinfo_write->format & SF_FORMAT_SUBMASK) 
      | (SF_FORMAT_AIFF & SF_FORMAT_TYPEMASK);
  }

  outfile=sf_open_write(filename,sfinfo_write);

  if (outfile==NULL) {
    fprintf(stderr,"Can\'t open file.\n");
    return "Can\'t open file";
  }
  for (i=0; i<samps_per_frame*N; i++) lyd2[i]=lyd[i];

  for (ch=0; ch<samps_per_frame; ch++) {
    GUI_aboveprogressbar(ch,samps_per_frame);
    rfft(lyd+ch*N,  N/2,  INVERSE);
  }

  writesound(SaveWaveConsumer,outfile);
  
  //  afCloseFile(outfile);
  sf_close(outfile);

  for (i=0; i<samps_per_frame*N; i++) lyd[i]=lyd2[i];
  strcpy(playfile, filename);

  free(sfinfo_write);

  return NULL;
}

static char *das_filename;
static char *das_ret;
static void das_das_SaveOk(void){
  das_ret=das_SaveOk(das_filename);
}

char *SaveOk(char *filename){
  das_filename=filename;
  GUI_newprocess(das_das_SaveOk);
  return das_ret;
}

