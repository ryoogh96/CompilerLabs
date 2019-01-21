%{  #include <stdio.h>
    #include <ctype.h>
    #include "tree.h"
    int yyerror(const char *msg), yylex();
%}
%union {
    Tree  pVal;
    int   iVal;
    char *sVal;
}
%type  <pVal> Exp Exp2 Term
%token <iVal> NUM
%left '*' '/'	// specifies priority of operators
%left '+' '-'	// specifies priority of operator
%nonassoc UMINUS
%%
Line    : Exp 		 { printtree($1,0); }
        ;
Exp     : Exp '+' Exp2   { $$ = mknode(PLUS, 0, NULL, $1);
                           $1->bro = $3; }
		| Exp '-' Exp2   { $$ = mknode(MINUS, 0, NULL, $1);
                           $1->bro = $3; }
		| Exp2		 { $$ = $1; }
Exp2    : Exp2 '*' Term   { $$ = mknode(MUL, 0, NULL, $1);
                           $1->bro = $3; }
		| Exp2 '/' Term	 { $$ = mknode(DIV, 0, NULL, $1);
                           $1->bro = $3; }
        | Term 		 { $$ = $1; }
        ;
Term	: '(' Exp ')'	 { $$ = $2; }
	| '-' Term %prec UMINUS	{ $$ = mknode(UMIN, 0, NULL, $2);}
	| NUM		 { $$ = mkleaf(TINT, $1); }
	;
%%
int main() { yyparse(); return 0; }
int yyerror(const char *msg) { fputs(msg, stderr); }
/*
int yylex() { int c = getchar();
    return (c == '\n')? 0: (isdigit(c))? yylval=c-'0', NUMBER: c;
}
*/

