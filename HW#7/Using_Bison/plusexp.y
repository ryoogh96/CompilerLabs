%{
#include <stdio.h>
#include <ctype.h>
int yyerror(const char *msg);
%}
%token NUMBER
%left '+' '-'	// specifies priority of operators
%left '*' '/'	// specifies priority of operators
%left UMINUS	// left associative Unary Minus
%%
Line : Exp { printf("= %d \n", $1); }
;
Exp     : Exp '+' Term      { $$ = $1 + $3; }
		| Exp '-' Term		{ $$ = $1 - $3; }
		| '-' Exp %prec UMINUS	{ $$ = -$2; }
        | Term              
        ;
Term    : Term '*' Factor   { $$ = $1 * $3; }
		| Term '/' Factor   { $$ = $1 / $3; }
        | Factor            
        ;
Factor  : '(' Exp ')'       { $$ = $2; }
		| NUMBER			{ $$ = $1; }
        ;
;
%%
int main() { yyparse(); return 0; }
int yyerror(const char *msg) { fputs(msg, stderr); }