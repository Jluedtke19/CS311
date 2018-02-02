average: average.o arithmeticmean.o geometricmean.o harmonicmean.o
	gcc averages.o arithmeticmean.o \
		geometicmean.o harmonicmean.o -lm -o averages

averages.o: averages.c
	gcc averages.c -c

arithmeticmean.o: arithmeticmean.c
	gcc arithmeticmean.c -c

geometricmean.o: geometricmean.c
	gcc harmonicmean.c -c

clean:
	rm -i *.c~ *.o averages
