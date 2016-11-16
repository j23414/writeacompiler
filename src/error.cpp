#include "global.h"
#include <stdlib.h>

int error(const char *m){
  fprintf(stderr,"line %d: %s\n",lineno,m);
  exit(1);  /* unsuccessful termination */
}
