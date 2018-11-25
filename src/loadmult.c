
#include "mammut.h"

/* Default values must be set because the buttons arent made with glade. */
bool loadandmultiply_convolve=true;
bool loadandmultiply_correlate=false;
bool loadandmultiply_fun=false;
bool loadandmultiply_a_b=false;
bool loadandmultiply_phase_amp=false;


static char *das_load_and_multiply_ok(char *filename)
{

  int i, N2, framecnt2, method=0, samps_per_frame2,ch;
  float r1, r2, i1, i2, amp,phi;
  //  int progral;
  struct LoadStruct ls={};

  SNDFILE *infile;

  if (N==0) return "Must first load file";

  if (loadandmultiply_convolve) method=1;
  else if (loadandmultiply_correlate) method=2;
  else if (loadandmultiply_fun) method=3;
  else if (loadandmultiply_a_b) method=4;
  else if (loadandmultiply_phase_amp) method=5;

  //  infile=afOpenFile(filename, "rb", in_AFsetup);
  infile=sf_open_read(filename,&ls.sfinfo);
  
  if (infile==NULL) {
    return "Could not read file";
  }

  ls.infile=infile;

  samps_per_frame2   = ls.sfinfo.channels;
  g_samplerate = ls.sfinfo.samplerate;

  framecnt2          = ls.sfinfo.MSF_FRAMENAME;

  if (samps_per_frame!=samps_per_frame2) {
    fprintf(stderr,"Number of channels does not match.\n");
    sf_close(infile);
    return "Number of channels does not match";
  }
  /*
  if (framecnt2 > 32000000) {
    sf_close(infile);
    return;
  }
  */

  N2=1;
  while (N2<framecnt2) N2*=2;
  if (N2<N) N2=N;
  if (lyd2!=NULL) free(lyd2);
  lyd2=NULL;
  fvec(lyd2, N2*samps_per_frame2);

  readsound(&ls, lyd2, samps_per_frame2);
  sf_close(infile);

  for (ch=0; ch<samps_per_frame; ch++) {
    GUI_aboveprogressbar(ch,samps_per_frame);
    rfft(lyd2+N2*ch,  N2/2,  FORWARD);
  }

  
  //GUI_startprogressbar(0,&progval,1000*log(ND*2));

  for (ch=0; ch<samps_per_frame; ch++) {
    for (i=0; i<(N2>N?N:N2)/2; i++) {
      r1=lyd[i+i+ch*N]; r2=lyd2[i+i+ch*N2];
      i1=lyd[i+i+1+ch*N]; i2=lyd2[i+i+1+ch*N2];
      switch (method) {
        case 1:
          lyd[i+i+ch*N]=(r1*r2-i1*i2)*N/1024;
          lyd[i+i+1+ch*N]=(i1*r2+r1*i2)*N/1024;
          break;
        case 2:
          lyd[i+i+ch*N]=(r1*r2+i1*i2)*N/1024;
          lyd[i+i+1+ch*N]=(i1*r2-r1*i2)*N/1024;
          break;
        case 3:
          lyd[i+i+ch*N]=(r1*r2-i1*r1)*N/1024;
          lyd[i+i+1+ch*N]=(i1*r2+r1*i2)*N/1024;
          break;
        case 4:
          amp=sqrt(r2*r2+i2*i2)+1.;
          lyd[i+i+ch*N]=copysign(powf(fabs(lyd[i+i+ch*N]), amp), lyd[i+i+ch*N]);
          lyd[i+i+1+ch*N]=copysign(powf(fabs(lyd[i+i+1+ch*N]), amp), lyd[i+i+1+ch*N]);
          break;
	case 5:
	  amp=sqrt(r1*r1+i1*i1);
	  phi=atan2(i2,r2);
	  lyd[i+i+ch*N]=amp*cos(phi);
	  lyd[i+i+1+ch*N]=amp*sin(phi);
	  break;
      }
    }
  }


  strcpy(playfile, filename);

  free(lyd2);
  lyd2=NULL;
  fvec(lyd2, N*samps_per_frame);

  return NULL;
}

static char *das_filename;
static char *das_ret;

void das_das_load_and_multiply_ok(void){
  das_ret=das_load_and_multiply_ok(das_filename);
}

char *load_and_multiply_ok(char *filename){
  das_filename=filename;
  GUI_newprocess(das_das_load_and_multiply_ok);
  RedrawWin();
  return das_ret;
}

