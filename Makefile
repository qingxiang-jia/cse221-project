# Makefile for CSE 221 project

test0:	test0.o
	clang -O0 -o test0 test0.o

test0.o:	test0.c
	clang -O0 -c test0.c count.h

op1: op1.o
	clang -O0 -o op1 op1.o

op1.o: op1.c
	clang -O0 -c op1.c count.h
	
op2: op2.o
	clang -O0 -o op2 op2.o

op2.o: op2.c
	clang -O0 -c op2.c count.h

clean:
	rm -f *.o *.out test0 *.s *.gch op1