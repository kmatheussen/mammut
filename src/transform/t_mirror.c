
#include "mammut.h"


double mirror_mirror_frequency_default=400.0;
double mirror_mirror_frequency=19254.9;

void mirror_ok(void)
{
  long i, j, num;
  int ch,chN;

  int_progval();

  num=(long)(mirror_mirror_frequency/binfreq);

  GUI_startprogressbar(0,progval,samps_per_frame*N/2);

  for(ch=0;ch<samps_per_frame;ch++){
    chN=ch*N;
    for (i=0; i<N/2; i++) {
      *progval=chN/2+i;
      j=num+num-i;
      if ((j<N/2) && (j>=0)) {
        lyd2[i+i+chN]=lyd[j+j+chN]; lyd2[i+i+1+chN]=-lyd[j+j+1+chN];
        lyd2[j+j+chN]=lyd[i+i+chN]; lyd2[j+j+1+chN]=-lyd[i+i+1+chN];
      } else { lyd2[i+i+chN]=0.; lyd2[i+i+1+chN]=0.; }
    }
    for (i=0; i<N; i++) lyd[i+chN]=lyd2[i+chN];
  }

  GUI_stopprogressbar();
}
