#include "mammut.h"

double multiplyphase_phase_multiplier_default=1.0;
double multiplyphase_phase_multiplier=1.0;
bool multiplyphase_phase_random_default=false;
bool multiplyphase_phase_random=false;

void multiply_phase_ok(void)
{
  int i;
  double real, imag, amp, phase;
  int ch,chN;

  int_progval();

  GUI_startprogressbar(0,progval,samps_per_frame*N/2);

  for(ch=0;ch<samps_per_frame;ch++){
    chN=ch*N;
    for (i=0; i<N/2; i++) {
      *progval=chN/2+i;
      real=lyd[i+i+chN]; imag=lyd[i+i+1+chN];

      if(multiplyphase_phase_random){
	phase=2*3.14159265*((double)rand())/((double)RAND_MAX);
      }else{
	phase=atan2(imag, real);
	phase*=multiplyphase_phase_multiplier;
      }

      amp=sqrt(imag*imag+real*real);

      lyd[i+i+chN]=amp*cos(phase); lyd[i+i+1+chN]=amp*sin(phase);
    }
  }
  
  GUI_stopprogressbar();
}
