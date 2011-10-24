
#include "mammut.h"

double filter_lower_cutoff_default=0.0;
double filter_upper_cutoff_default=1000.0;
double filter_sharpness_default=10.0;

double filter_lower_cutoff=9868.4;
double filter_upper_cutoff=22050.0;
double filter_sharpness=10.0;

void filter_ok(void)
{
  int i, low, up, mid, ch;
  double fact,sharp;

  int_progval();

  GUI_startprogressbar(0,progval,samps_per_frame*2);

  sharp=filter_sharpness;
  if (sharp==11.) sharp=0.; else sharp=1./sharp;

  low=filter_lower_cutoff/binfreq;
  up=filter_upper_cutoff/binfreq;
  if (low<0) low=0; if (low>=N/2) low=N/2-1;
  if (up>=N/2) up=N/2-1;
  mid=(low+up)/2;

  for (ch=0; ch<samps_per_frame; ch++) {
    fact=sharp;
    for (i=low; i<=mid; i++) {
      *(lyd+i+i+ch*N)*=fact; *(lyd+i+i+1+ch*N)*=fact;
      fact*=sharp;
    }
    *progval=ch*2;
    fact=sharp;
    for (i=up; i>mid; i--) {
      *(lyd+i+i+ch*N)*=fact; *(lyd+i+i+1+ch*N)*=fact;
      fact*=sharp;
    }
    *progval=ch*2+1;
  }


  GUI_stopprogressbar();
}
