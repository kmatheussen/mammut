
#include "mammut.h"

double threshold_threshold_level_default=1.0;
bool threshold_remove_above_threshold_default=false;

double threshold_threshold_level=1.0;
bool threshold_remove_above_threshold=false;

void threshold_ok(void)
{
  long i;
  double amp;
  int ch,chN;

  int_progval();

  GUI_startprogressbar(0,progval,samps_per_frame*N/2);



  for(ch=0;ch<samps_per_frame;ch++){
    chN=ch*N;
    for (i=0; i<N/2; i++) {
      *progval=chN/2+i;
      amp=sqrt(lyd[i+i+chN]*lyd[i+i+chN]+lyd[i+i+1+chN]*lyd[i+i+1+chN])*N/350.;
      if (threshold_remove_above_threshold) {
        if (amp>threshold_threshold_level) { lyd[i+i+chN]=0.; lyd[i+i+1+chN]=0.; }
      } else {
        if (amp<threshold_threshold_level) { lyd[i+i+chN]=0.; lyd[i+i+1+chN]=0.; }
      }
    }
  }

  GUI_stopprogressbar();
}
