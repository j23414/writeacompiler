#include "global.h"
#include "init.h"
#include "parser.h"
#include <stdlib.h>

int main(){
  init();
  parse();
  exit(0); /* successful termination */
}
