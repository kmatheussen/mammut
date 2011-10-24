
#include "mammut.h"

double gain_amplitude_multiplier_default=10;
double gain_amplitude_multiplier=10;

void gain_ok(void)
{
  long i;
  int ch;

  int_progval();

  GUI_startprogressbar(0,progval,samps_per_frame);

  for (ch=0; ch<samps_per_frame; ch++) {
    *progval=ch;
    for (i=0; i<N/2; i++) {
      lyd[i+i+ch*N]*=gain_amplitude_multiplier;
      lyd[i+i+1+ch*N]*=gain_amplitude_multiplier;
    }
  }
  
  GUI_stopprogressbar();
}
