.PHONY: all
all:	clean	caesar	queue ciphered_queue

caesar:
	gcc -o caesar caesar_main.c

queue:
	gcc -o queue queue_main.c

ciphered_queue:
	gcc -o ciphered_queue ciphered_queue_main.c
clean:
	rm -f ./caesar
	rm -f ./queue
	rm -f ./ciphered_queue
