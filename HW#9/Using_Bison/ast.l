%{
    #include "ast.hpp"
    #include "y.tab.h"
    #include <stdlib.h>
%}
%%
[0-9]+  { yylval.iVal = atoi(yytext); return NUM; }
[a-zA-Z]+  { yylval.sVal = strdup(yytext); return ID; }
[ \t]   ;
\n      return 0;
\+		return '+';
\-		return '-';
\*		return '*';
\/		return '/';
\(		return '(';
\)		return ')';
.       { printf("error near %s\n", yytext); exit(-1); }
%%
int yywrap() {
    return 1;
}
