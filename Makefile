# Makefile for CSE 221 project

test0:	test0.o nano.o
	clang -o test0 test0.o nano.o

test0.o:	test0.c
	clang -c test0.c

nano.o:	nano.c nano.h
	clang -c nano.c nano.h

clean:
	rm -f *.o *.out test0