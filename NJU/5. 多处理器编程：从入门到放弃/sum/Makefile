sum.out: sum.o
	cc $(opt) -o sum.out sum.o

sum.o: sum.c thread.h
	cc $(opt) -c sum.c

.PHONY : clean
clean :
	rm -rf *.out *.o