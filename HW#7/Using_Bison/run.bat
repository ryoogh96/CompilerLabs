@echo off
flex plusexp.l
bison --verbose -dy plusexp.y
gcc -w -o simple lex.yy.c y.tab.c
set /p str=< input.txt
echo %str%
simple.exe < input.txt
set /p str=< input2.txt
echo %str%
simple.exe < input2.txt
set /p str=< input3.txt
echo %str%
simple.exe < input3.txt
pause