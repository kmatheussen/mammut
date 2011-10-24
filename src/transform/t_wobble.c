
#include "mammut.h"

double wobble_frequency_default=10.0;
double wobble_amplitude_default=0.01;

double wobble_frequency=10.0;
double wobble_amplitude=0.01;

void wobble_ok(void)
{
  int i, tnum;
  int ch,chN;

  int_progval();

  GUI_startprogressbar(0,progval,samps_per_frame*N/2);

  for(ch=0;ch<samps_per_frame;ch++){
    chN=ch*N;
    for (i=0; i<N; i++){
      lyd2[i+chN]=0.;
    }
    for (i=0; i<N/2; i++) {
      *progval=chN/2+i;
      tnum=(int)(0.5*(sin(4.*PI*i*wobble_frequency/N)+1.)*wobble_amplitude*N/4.+i);
      if (tnum<0) tnum=0;
      if (tnum>=N/2) tnum=N/2-1;
      *(lyd2+tnum+tnum+chN)=*(lyd+i+i+chN);
      *(lyd2+tnum+tnum+1+chN)=*(lyd+i+i+1+chN);
    }
    for (i=0; i<N; i++) lyd[i+chN]=lyd2[i+chN];
  }

  GUI_stopprogressbar();
}
