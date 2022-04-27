g++ AA.cpp -o AA - g
g++ BB.cpp -o BB -g

:loop
	AA.exe>1.txt
	BB.exe<1.txt>2.txt
	fc 1.txt 2.txt
if not errorlevel 1 goto loop
pause
goto loop	