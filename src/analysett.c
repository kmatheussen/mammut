
#include "mammut.h"

int analysis_duration_doubling;

void analysis_ok(void)
{
  dobler=analysis_duration_doubling;

  if (dobler<0) dobler=0;
  if (dobler>4) dobler=4;
}

