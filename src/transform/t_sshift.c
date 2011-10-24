
#include "mammut.h"

double spectrumshift_shift_value_default=50;
double spectrumshift_shift_value=50;

void spectrum_shift_ok(void)
{
  int i, tnum, bins;
  int ch,chN;

  int_progval();

  GUI_startprogressbar(0,progval,samps_per_frame*3);


  bins=spectrumshift_shift_value/binfreq;

  for(ch=0;ch<samps_per_frame;ch++){
    *progval=ch*3;
    chN=ch*N;
    for (i=0; i<N; i++) lyd2[i+chN]=0.;
    *progval=ch*3+1;
    for (i=0; i<N/2; i++) {
      tnum=(int)(i+bins);
      if (tnum<0) tnum=0; if (tnum>=N/2) tnum=N/2-1;
      *(lyd2+tnum+tnum+chN)=*(lyd+i+i+chN); *(lyd2+tnum+tnum+1+chN)=*(lyd+i+i+1+chN);
    }
    *progval=ch*3+2;
    for (i=0; i<N; i++) lyd[i+chN]=lyd2[i+chN];
  }

  
  GUI_stopprogressbar();
}
