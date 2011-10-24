
#include "mammut.h"

double crossover_switching_probability_default=0.01;
double crossover_switching_probability=0.01;

void crossover_ok(void)
{
  long i;
  int state=0;

  for (i=0; i<N+N; i++) lyd2[i]=lyd[i];
  for (i=0; i<N/2; i++) {
    if (state) {
      lyd[i+i]=lyd2[i+i+N]; lyd[i+i+1]=lyd2[i+i+N+1];
      lyd[i+i+N]=lyd2[i+i]; lyd[i+i+N+1]=lyd2[i+i+1];
    }
    if (rand()/32768.<crossover_switching_probability) {
      if (state==0) state=1; else state=0;
    }
  }

}
