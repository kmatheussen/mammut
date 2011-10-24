
#include "mammut.h"

double invert_inversion_block_size_default=1.0;
double invert_inversion_block_size=1.0;

void invert_ok(void)
{
  long i, j, s, e, num, len;
  double size;
  int ch,chN;

  int_progval();

  size=invert_inversion_block_size;
  len=(long)(size*N/200.);
  num=(long)(100./size);

  s=0;

  GUI_startprogressbar(0,progval,samps_per_frame*num);

  for(ch=0;ch<samps_per_frame;ch++){
    chN=ch*N;
    s=0;
    for (i=0; i<num; i++) {
      *progval=ch*num + i;
      for (j=s; j<s+len/2; j++) {
        e=s+s+len-j-1;
        lyd2[j+j+chN]=lyd[j+j+chN]; lyd2[j+j+1+chN]=lyd[j+j+1+chN];
        lyd[j+j+chN]=lyd[e+e+chN]; lyd[j+j+1+chN]=-lyd[e+e+1+chN];
        lyd[e+e+chN]=lyd2[j+j+chN]; lyd[e+e+1+chN]=-lyd2[j+j+1+chN];
      }
      s+=len;
    }
  }

  GUI_stopprogressbar();
}

