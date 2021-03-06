#include "global.h"
#include "error.h"
#include "emitter.h"
#include "lexer.h"

int lookahead;


void parse();
void expr();
void factor();
void term();
void match(int t);

/* parses and translates expression list */
void parse(){
  printf("parser:In parse\n");
  lookahead=lexan();
  while(lookahead!=DONE){
    expr();
    match(';');
  }
}

void expr(){
  printf("parser:In expr\n");
  int t;
  term();
  while(1)
    switch(lookahead){
    case '+':
    case '-':
      t=lookahead;
      match(lookahead);
      term();
      emit(t,NONE);
      continue;
    default:
      return;
    }
}

void factor(){
  printf("parser:In factor\n");
  switch(lookahead){
  case '(':
    match('(');
    expr();
    match(')');
    break;
  case NUM:
    emit(NUM,tokenval);
    match(NUM);
    break;
  case ID:
    emit(ID,tokenval);
    match(ID);
    break;
  default:
    error("syntax error");
  }
}


void term(){
  printf("parser:In term\n");
  int t;
  factor();
  while(1)
    switch(lookahead){
    case '*':
    case '/':
    case DIV:
    case MOD:
      t=lookahead;
      match(lookahead);
      factor();
      emit(t,NONE);
      continue;
    default:
      return;
    }
  return;
}

void match(int t){
  printf("parser:In match\n");
  if(lookahead==t)
    lookahead=lexan();
  else
    error("syntax error");
}

