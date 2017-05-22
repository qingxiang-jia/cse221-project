# Makefile for CSE 221 project

cpu: cpu.o
	clang -O0 -o cpu cpu.o

cpu.o: cpu.c
	clang -O0 -c cpu.c count.h

mem: mem.o
	clang -O0 -o mem mem.o

mem.o: mem.c
	clang -O0 -c mem.c count.h

clean:
	rm -f *.o *.out test0 *.s *.gch cpu mem