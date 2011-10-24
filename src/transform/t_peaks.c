
#include "mammut.h"

void keep_peaks_ok(void)
{
  int i;
  double real, imag, amp, amplast, ampnext;
  int ch,chN;

  int_progval();

  GUI_startprogressbar(0,progval,samps_per_frame*(N/2-1));

  for(ch=0;ch<samps_per_frame;ch++){
    chN=ch*N;

    for (i=0; i<N; i++)
      lyd2[i+chN]=lyd[i+chN];

    for (i=1; i<N/2-1; i++) {
      *progval=chN/2+i;

      real=lyd2[i+i+chN]; imag=lyd2[i+i+1+chN]; amp=real*real+imag*imag;

      amplast=lyd2[i+i-2+chN]*lyd2[i+i-2+chN] + lyd2[i+i-1+chN]*lyd2[i+i-1+chN];
      ampnext=lyd2[i+i+2+chN]*lyd2[i+i+2+chN] + lyd2[i+i+3+chN]*lyd2[i+i+3+chN];
      
      if ((amp<amplast) || (amp<ampnext)) {
        lyd[i+i+chN]=lyd[i+i+1+chN]=0.;
      } 

    }
  }

  GUI_stopprogressbar();
}

