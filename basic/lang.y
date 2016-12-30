%{

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "myfunctions.h"
  
extern int yylex();
extern int yyparse();
extern FILE* yyin;

void yyerror(const char* s);
%}

%union {
	int ival;
	float fval;
        char* sval;
}

%token<ival> T_INT
%token<fval> T_FLOAT
%token<sval> T_TERM
%token T_PLUS T_MINUS T_MULTIPLY T_DIVIDE T_LEFT T_RIGHT T_SIN T_COS
%token T_NEWLINE T_QUIT
%left T_PLUS T_MINUS
%left T_MULTIPLY T_DIVIDE

%type<ival> expr
%type<fval> mx_expr

%start calculation

%%

calculation: 
	   | calculation line
;

line: T_NEWLINE
    | mx_expr T_NEWLINE { printf("\tME Result: %f\n", $1);}
    | expr T_NEWLINE { printf("\tE Result: %i\n", $1); } 
    | T_QUIT T_NEWLINE { printf("bye!\n"); exit(0); }
    | T_TERM T_NEWLINE { Hello($1);}
//     printf("\tTERM: %s\n",$1) }
;

mx_expr: T_FLOAT                 		 { $$ = $1; }
	  | mx_expr T_PLUS mx_expr	 { $$ = $1 + $3; }
	  | mx_expr T_MINUS mx_expr	 { $$ = $1 - $3; }
	  | mx_expr T_MULTIPLY mx_expr { $$ = $1 * $3; }
	  | mx_expr T_DIVIDE mx_expr	 { $$ = $1 / $3; }
	  | T_LEFT mx_expr T_RIGHT		 { $$ = $2; }
	  | expr T_PLUS mx_expr	 	 { $$ = $1 + $3; }
	  | expr T_MINUS mx_expr	 	 { $$ = $1 - $3; }
	  | expr T_MULTIPLY mx_expr 	 { $$ = $1 * $3; }
	  | expr T_DIVIDE mx_expr	 { $$ = $1 / $3; }
	  | mx_expr T_PLUS expr	 	 { $$ = $1 + $3; }
	  | mx_expr T_MINUS expr	 	 { $$ = $1 - $3; }
	  | mx_expr T_MULTIPLY expr 	 { $$ = $1 * $3; }
	  | mx_expr T_DIVIDE expr	 { $$ = $1 / $3; }
	  | expr T_DIVIDE expr		 { $$ = $1 / (float)$3; }
          | T_SIN T_LEFT mx_expr T_RIGHT        { $$ = sin($3); }
          | T_COS T_LEFT mx_expr T_RIGHT        { $$ = cos($3); }
          | T_SIN T_LEFT expr T_RIGHT        { $$ = sin((float)$3); }
          | T_COS T_LEFT expr T_RIGHT        { $$ = cos((float)$3); }
;

expr: T_INT				{ $$ = $1; }
	  | expr T_PLUS expr	{ $$ = $1 + $3; }
	  | expr T_MINUS expr	{ $$ = $1 - $3; }
	  | expr T_MULTIPLY expr	{ $$ = $1 * $3; }
	  | T_LEFT expr T_RIGHT		{ $$ = $2; }
;

%%

int main() {
	yyin = stdin;

	do { 
		yyparse();
	} while(!feof(yyin));

	return 0;
}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}
