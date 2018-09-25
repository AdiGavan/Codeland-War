# Gavan Adrian George - 314CA

build: codewar

codewar: codewar.o
	gcc -Wall codewar.o -o codewar

codewar.o: codewar.c
	gcc -Wall -c codewar.c

clean: 
	rm -f *.o codewar
