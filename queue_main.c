#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.c"

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


//Constuct a small queue with elements to test if freeQueue frees all elements of a queue
//(succeeds using valgrind)
queue_t* testFree = makeQueue();
enqueue(testFree, makeProcess(1, "x"));
enqueue(testFree, makeProcess(1, "y"));
enqueue(testFree, makeProcess(1, "z"));
freeQueue(testFree);

return 0;
}
