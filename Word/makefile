word: word.o lettercount.o
	gcc word.o lettercount.o   -lm -o word

word.o: word.c
	gcc word.c -c

lettercount.o: lettercount.c
	gcc lettercount.c -c


clean:
	rm -i *.c~ *.o word
