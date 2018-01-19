truncate: truncate.o print.o length.o
	gcc truncate.o print.o \
		length.o -lm -o truncate

truncate.o: truncate.c
	gcc truncate.c -c

print.o: print.c
	gcc print.c -c

length.o: length.c
	gcc length.c -c

clean:
	rm -i *.c~ *.o
