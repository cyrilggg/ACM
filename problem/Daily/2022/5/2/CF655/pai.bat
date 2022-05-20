
g++ rand.cpp -o rand
g++ B.cpp -o B
g++ blb.cpp -o blb
 
:loop
 rand.exe >1.txt
 B.exe<1.txt>2.txt
 blb.exe<1.txt>3.txt
 fc 2.txt 3.txt
 if %errorlevel%==0 goto loop
pause