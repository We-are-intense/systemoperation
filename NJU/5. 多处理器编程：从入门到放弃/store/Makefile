
object := store


$(object).out: $(object).o
	cc $(opt) -o $(object).out $(object).o

$(object).o: $(object).c thread.h
	cc $(opt) -c $(object).c

.PHONY : clean
clean :
	rm -rf *.out *.o