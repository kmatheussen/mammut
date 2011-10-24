
#include "mammut.h"
#include <stdlib.h>
#include <time.h>

int blockswap_number_of_swaps_default=8981;
double blockswap_block_size_default=100;
bool blockswap_old_version_with_error_default=false;

int blockswap_number_of_swaps=8981;
double blockswap_block_size=100;
bool blockswap_old_version_with_error=false;

void block_swap_ok(void)
{
  long i, j, s, num, len, len2, e;
  double size;
  int ch,chN;

  int_progval();

#ifdef _WIN32
  static bool random_run=false;
  if(random_run==false){
    srand(time(NULL));
    random_run=true;
  }
#endif

  num=(long)blockswap_number_of_swaps;
  
  size=blockswap_block_size;
  
  GUI_startprogressbar(0,progval,samps_per_frame*num);  

  if (blockswap_old_version_with_error==true) {

    for(ch=0;ch<samps_per_frame;ch++){
      chN=ch*N;
      for (i=0; i<num; i++) {
	*progval=ch*num+i;
	len=(long)(size*N/200.);
#ifdef _WIN32 
	s=rand()%(N/2);
#else	
	s=random()%(N/2);
#endif
	if (s+len>=N/2) len=N/2-s-1;
	e=s+len;
	for (j=s; j<s+len/2; j++) {
	  lyd2[j+j+chN]=lyd[j+j+chN]; lyd2[j+j+1+chN]=lyd[j+j+1+chN];
	  lyd[j+j+chN]=lyd[j+j+len+chN]; lyd[j+j+1+chN]=lyd[j+j+len+1+chN];
	  lyd[j+j+len+chN]=lyd2[j+j+chN]; lyd[j+j+len+1+chN]=lyd2[j+j+1+chN];
	}
      }
    }



  } else {



    for(ch=0;ch<samps_per_frame;ch++){
      chN=ch*N;
      for (i=0; i<num; i++) {
	*progval=ch*num+i;
	len=(long)(size*N/200.);
#ifdef _WIN32
	s=rand()%(N/2);
#else	
	s=random()%(N/2);
#endif
	if (s+len>=N/2) len=N/2-s-1;
	len2=(len>>1)<<1;
	for (j=s; j<s+len/2; j++) {
	  lyd2[j+j+chN]=lyd[j+j+chN];
	  lyd2[j+j+1+chN]=lyd[j+j+1+chN];
	  
	  lyd[j+j+chN]=lyd[j+j+len2+chN];
	  lyd[j+j+1+chN]=lyd[j+j+len2+1+chN];
	  
	  lyd[j+j+len2+chN]=lyd2[j+j+chN];
	  lyd[j+j+len2+1+chN]=lyd2[j+j+1+chN];
	}
      }
    }

  }

  GUI_stopprogressbar();
  
}


