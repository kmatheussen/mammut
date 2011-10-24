
#include "mammut.h"

double stretch_exponent_default=1.3;
double stretch_exponent=1.3;

void stretch_ok(void){
  int i, tnum;
  double scal;
  int ch,chN;

  int_progval();

  GUI_startprogressbar(0,progval,samps_per_frame*3);


  scal=(N/2)/pow(N/2,stretch_exponent);


  for(ch=0;ch<samps_per_frame;ch++){
    chN=ch*N;

    for (i=0; i<N; i++)
      lyd2[i+chN]=0.;

    *progval=ch*3+1;

    for (i=0; i<N/2; i++) {
      tnum=(int)(pow(i,stretch_exponent)*scal);
      if (tnum>=N/2) tnum=N/2-1;
      *(lyd2+chN+tnum+tnum)=*(lyd+chN+i+i);
      *(lyd2+chN+tnum+tnum+1)=*(lyd+chN+i+i+1);
    }

    *progval=ch*3+2;

    for (i=0; i<N; i++)
      lyd[i+chN]=lyd2[i+chN];

    *progval=ch*3+3;
  }

  GUI_stopprogressbar();

}


