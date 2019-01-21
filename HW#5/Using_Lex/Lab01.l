%{
	#include <stdio.h>
	int symbolsNum = 0, wordsNum = 0;
%}
symbols	[\!\@\#\$\%\^\&\*\(\,\)\-\_\+\=\|\\\/\<\>\:\:\"\'\`\~\{\,\}\[\,\]\.]
words	[a-zA-Z]+
%%
{symbols}	++symbolsNum;
{words}		++wordsNum;
\n 
\ 
%%
int main() {
	yylex();
	printf("Num. of Symbols: %d\nNum. of Words: %d\n",symbolsNum,wordsNum);
	return 0;
}
int yywrap() {
	return 1;
}
