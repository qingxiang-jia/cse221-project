# Makefile for CSE 221 project

test0:	test0.o nano.o
	clang -O0 -o test0 test0.o nano.o

test0.o:	test0.c
	clang -O0 -c test0.c

nano.o:	nano.c nano.h
	clang -O0 -c nano.c nano.h

clean:
	rm -f *.o *.out test0