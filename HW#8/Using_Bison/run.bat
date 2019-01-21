@echo off
make
set /p str=< input.txt
echo %str%
a.exe < input.txt
set /p str=< input2.txt
echo %str%
a.exe < input2.txt
pause