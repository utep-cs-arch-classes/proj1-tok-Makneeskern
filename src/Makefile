main: tokenizer.o gui.o history.o
	gcc -o main tokenizer.o gui.o history.o

tokenizer.o: tokenizer.c tokenizer.h
	gcc -c tokenizer.c

gui.o: gui.c tokenizer.h
	gcc -c gui.c

history.o: history.c history.h
	gcc -c history.c

clean:
	rm *.o *~ *# main
