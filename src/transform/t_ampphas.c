
#include "mammut.h"

double amplitudephase_amplitude_multiplier_default=50.0;
double amplitudephase_amplitude_multiplier=50.0;

void amplitude_phase_ok(void)
{
  long i;
  double mul, real, imag, amp, phase;
  int ch,chN;
  int_progval();

  GUI_startprogressbar(0,progval,samps_per_frame*N/2);

  mul=(double)amplitudephase_amplitude_multiplier*1000.;

  for(ch=0;ch<samps_per_frame;ch++){
    chN=ch*N;
    for (i=0; i<N/2; i++) {
      *progval=chN/2+i;

      real=lyd[i+i+chN]; imag=lyd[i+i+1+chN];

#if 0
      phase=2*3.14*((double)random())/((double)RAND_MAX);
      amp=sqrt(imag*imag+real*real);
      //phase+=amp;
#else
      phase=atan2(imag, real); amp=sqrt(imag*imag+real*real);
      phase+=amp*mul;
#endif
      lyd[i+i+chN]=amp*cos(phase); lyd[i+i+1+chN]=amp*sin(phase);
    }
  }

  GUI_stopprogressbar();
}
#if 0
  int progval=0;

  GUI_startprogressbar(0,&progval,samps_per_frame*N/2);

  GUI_stopprogressbar();
#endif
