
#include "mammut.h"


double derivateamp_amp_derivate_multiplier_default=1.0;
double derivateamp_amp_derivate_multiplier=1.0;

void derivate_amp_ok(void)
{
  int i;
  double real, imag, amp, phase, lastamp=0., da;
  int ch,chN;

  int_progval();

  GUI_startprogressbar(0,progval,samps_per_frame*N/2);

  for(ch=0;ch<samps_per_frame;ch++){

    chN=ch*N;

    for (i=1; i<N/2; i++) {
      *progval=chN/2+i;
      real=lyd[i+i+chN]; imag=lyd[i+i+1+chN];
      phase=atan2(imag, real);
      amp=sqrt(imag*imag+real*real);
      da=(amp-lastamp)*derivateamp_amp_derivate_multiplier;
      lyd[i+i+chN]=da*cos(phase); lyd[i+i+1+chN]=da*sin(phase);
      lastamp=amp;
    }
  }

  GUI_stopprogressbar();
}
