# Makefile for CSE 221 project

cpu: cpu.o
	clang -O0 -o cpu cpu.o

cpu.o: cpu.c
	clang -O0 -c cpu.c headers/count.h

mem: mem.o
	clang -O0 -o mem mem.o

mem.o: mem.c
	clang -O0 -c mem.c headers/count.h

net: net.o
	clang -O0 -o net net.o

net.o: net.c
	clang -O0 -c net.c headers/count.h

fs: fs.o
	clang -O0 -o fs fs.o

fs.o: fs.c
	clang -O0 -c fs.c headers/count.h

clean:
	rm -f *.o *.out test0 *.s *.gch cpu mem net fs