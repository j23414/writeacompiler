#include <stdio.h>
#include <ctype.h>

/* buffer size */
#define BSIZE 128
#define NONE -1
#define EOS '\0'

#define NUM  256
#define DIV  257
#define MOD  258
#define ID   259
#define DONE 260

extern int tokenval; /* value of token attribute */

extern int lineno;

/* form of symbol table entry */
struct entry{
  char *lexptr;
  int token;
};

/* symbol table */
extern struct entry symtable[]; 
