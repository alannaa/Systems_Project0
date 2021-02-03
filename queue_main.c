#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.c"

//This could be added to queue.c but is very specific to the needs of 
//this main method and not very general, so I kept it here:
void printHelper(char* msg, queue_t* queue, process_t* proc)
{
	printf("%s",msg);
	printProcess(proc);
	printQueue(queue);
}

int main() {

//Process Examples
process_t* procA = makeProcess(0, "A");
process_t* procB = makeProcess(1, "B");
process_t* procC = makeProcess(2, "C");
process_t* proc3A = makeProcess(3, "A");
process_t* procD = makeProcess(4, "D");

//Queue building
queue_t* queue = makeQueue();
printQueue(queue);

//En/De-queue and print
enqueue(queue, procA);
printHelper("Enqueue: ", queue, procA);
enqueue(queue, procB);
printHelper("Enqueue: ", queue, procB);
enqueue(queue, procC);
printHelper("Enqueue: ", queue, procC);

void* deQA = dequeue(queue);
printHelper("Dequeue: ", queue, procA);

enqueue(queue, proc3A);
printHelper("Enqueue: ", queue, proc3A);

void* deQB = dequeue(queue);
printHelper("Dequeue: ", queue, procB);

enqueue(queue, procD);
printHelper("Enqueue: ", queue, procD);

void* deQC = dequeue(queue);
printHelper("Dequeue: ", queue, procC);

void* deQ3A = dequeue(queue);
printHelper("Dequeue: ", queue, proc3A);

void* deQD = dequeue(queue);
printHelper("Dequeue: ", queue, procD);

printQueue(queue);


free(deQA);
free(deQB);
free(deQC);
free(deQD);
free(deQ3A);

freeQueue(queue);



return 0;
}
