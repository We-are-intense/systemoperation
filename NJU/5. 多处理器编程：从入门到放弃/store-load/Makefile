
object := store-load

cc := gcc

store-load.out: $(object).o
	$(cc) $(opt) -o $(object).out $(object).o

store-load.o: $(object).c thread.h
	$(cc) $(opt) -c $(object).c

.PHONY : clean
clean :
	rm -rf *.out *.o