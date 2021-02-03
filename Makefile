.PHONY: all
all:	clean	caesar	queue

caesar:
	gcc -o caesar caesar_main.c

queue:
	gcc -o queue queue_main.c

clean:
	rm -f ./caesar
	rm -f ./queue
