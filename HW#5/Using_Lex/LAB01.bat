@echo off
flex Lab01.l
gcc lex.yy.c
a.exe < input.txt
pause