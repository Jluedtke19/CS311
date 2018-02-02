queue: queue.o generate.o average.o
	gcc queue.o generate.o average.o -lm -o queue

queue.o: queue.c
	gcc queue.c -c

generate.o: generate.c
	gcc generate.c -c

average.o: average.c
	gcc average.c -c

clean:
	rm -i *.c~ *.o queue
