#include "global.h"
#include <cstring>
#include "symbol.h"

struct entry keywords[] = {
  (char*)"div",DIV,
  (char*)"mod",MOD,
  0,0
};

/* loads keywords into symtable */
void init(){
  struct entry *p;
  for(p=keywords; p->token; p++){
    insert(p->lexptr,p->token);
  }
}
