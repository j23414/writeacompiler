#include "global.h"
#include "error.h"
#include "symbol.h"

char lexbuf[BSIZE];
int lineno = 1;
int tokenval = NONE;

/* lexical analyzer */
int lexan(){
  printf("lexer:In lexan\n");
  int t;
  while(1){
    t=getchar();
    if(t == ' ' || t == '\t') ; /* strip out white space */
    else if (t== '\n')
      lineno++;
    else if (isdigit(t)){
      ungetc(t,stdin);
      scanf("%d",&tokenval);
      return NUM;
    }
    else if(isalpha(t)){
      int p, b = 0;
      while(isalnum(t)){
	lexbuf[b]=t;
	t=getchar();
	b++;
	if(b>=BSIZE)
	  error("compiler error: overrun buffer");
      }
      lexbuf[b]=EOS;
      if(t!=EOF)
	ungetc(t,stdin);
      p=lookup(lexbuf);
      if(p==0)
	p=insert(lexbuf,ID);
      tokenval=p;
      return symtable[p].token;
    }
    else if(t==EOF){
      return DONE;
    }
    else{
      tokenval=NONE;
      return t;
    }
  }
}
