obj := condition

$(obj).out: $(obj).o
	cc $(opt) -o $(obj).out $(obj).o

$(obj).o: $(obj).c thread.h thread-sync.h
	cc $(opt) -c $(obj).c

.PHONY : clean
clean :
	rm -rf *.out *.o