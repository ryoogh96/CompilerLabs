%{  #include <stdio.h>
    #include <ctype.h>
    #include "ast.hpp"
	Tree *Node;
    int yyerror(const char *msg), yylex();
%}
%union {
    Tree *pVal;
    int   iVal;
    char *sVal;
}
%type  <pVal> Exp Exp2 Term
%token <iVal> NUM
%token <sVal> ID
%left '*' '/'	// specifies priority of operators
%left '+' '-'	// specifies priority of operator
%nonassoc UMINUS
%%
Line    : Exp 		 { $1->printtree($1,0); }
        ;
Exp     : Exp '+' Exp2   { $$ = new Tree(PLUS, $1, $3);}
		| Exp '-' Exp2   { $$ = new Tree(MINUS, $1, $3);}
		| Exp2		 { $$ = $1; }
Exp2    : Exp2 '*' Term   { $$ = new Tree(MUL, $1, $3);}
		| Exp2 '/' Term	 { $$ = new Tree(DIV, $1, $3);}
        | Term 		 { $$ = $1; }
        ;
Term	: '(' Exp ')'	 { $$ = $2; }
	| '-' Term %prec UMINUS	{ $$ = new Tree(UMIN, $2);}
	| NUM		 { $$ = new Tree(TINT, $1); }
	| ID		 { $$ = new Tree(TID, $1);  }
	;
%%
int main() { yyparse(); return 0; }
int yyerror(const char *msg) { fputs(msg, stderr); }
/*
int yylex() { int c = getchar();
    return (c == '\n')? 0: (isdigit(c))? yylval=c-'0', NUMBER: c;
}
*/

