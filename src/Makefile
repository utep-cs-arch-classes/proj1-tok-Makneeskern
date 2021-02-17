main: tokenizer.o gui.o
	gcc -o main tokenizer.o history.o gui.o

tokenizer.o: tokenizer.c tokenizer.h
	gcc -c tokenizer.c

gui.o: gui.c tokenizer.h
	gcc -c gui.c

clean:
	rm *.o *~ *# main
