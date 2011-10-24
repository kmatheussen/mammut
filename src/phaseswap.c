
#include "mammut.h"

void Phaseswap(void)
{
  int i;
  double real1, imag1, real2, imag2, amp1, amp2, phase1, phase2;

  for (i=0; i<N+N; i++) lyd2[i]=lyd[i];
  for (i=1; i<N/2; i++) {
    real1=lyd2[i*2]; imag1=lyd2[i*2+1];
    real2=lyd2[i*2+N]; imag2=lyd2[i*2+1+N];
    amp1=sqrt(real1*real1+imag1*imag1); amp2=sqrt(real2*real2+imag2*imag2);
    phase1=atan2(imag1,real1); phase2=atan2(imag2,real2);
    lyd[i+i]=amp1*cos(phase2); lyd[i+i+1]=amp1*sin(phase2);
    lyd[i+i+N]=amp2*cos(phase1); lyd[i+i+1+N]=amp2*sin(phase1);
  }
}
