stack.out: stack-probe.o
	cc -o stack.out stack-probe.o

stack-probe.o: stack-probe.c thread.h
	cc -c stack-probe.c

.PHONY : clean
clean :
	rm -rf *.out *.o