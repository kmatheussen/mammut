//#include "ceres.h"

#include <stdio.h>
#include <stdbool.h>

/*

*/


bool InitPlay(void){
  printf("No real soundlib compiled into Ceres. No play.\n");
  return false;
}

void *OpenPlay(void){

  return NULL;
}

void WritePlay(
	       void *something,
	       void *port,double **buffer,int size
	       ){
}


void ClosePlay(void *port){
}
