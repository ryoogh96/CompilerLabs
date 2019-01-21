Purpose : Using Attributes in Bison

run.bat : auto run compile and execute

simple.exe : compiled windows executable file

plusexp.l : flex source file

plusexp.y : bison source file

lex.yy.c : flex plusexp.l -> flex file

y.tab.c : bison --verbose -dy plusexp.y -> yacc file

y.tab.h : -dy command option from above

y.output : made by --verbose command option with inputs from Grammer Rules execute flow

input.txt : 10 + 20 test case

input2.txt : 100/4 + 37 * (42-29) test case

input3.txt : (1+2)-(3+4)+(5-6) test case