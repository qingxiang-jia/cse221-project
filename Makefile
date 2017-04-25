# Makefile for CSE 221 project

test0:	test0.o
	clang -O0 -o test0 test0.o

test0.o:	test0.c
	clang -O0 -c test0.c count.h

clean:
	rm -f *.o *.out test0 *.s *.gch