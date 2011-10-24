
#include "mammut.h"
#include <stdarg.h>

#include "juce.h"



void printerror(const char *fmt, ...){
  char temp[5000];

  va_list argp;
  
  va_start(argp,fmt);
  
  vsprintf(temp,fmt,argp);
  fprintf(stderr,"Mammut, error: %s\n",temp);

  AlertWindow::showMessageBox (AlertWindow::WarningIcon,
			       T("Mammut"),
			       String(temp));
  
  va_end(argp);
}

void *erroralloc(size_t size){
  void *ret=calloc(1,size);
  if(ret==NULL)
    printerror("Could not allocate %d bytes\n",size);

  return ret;
}
