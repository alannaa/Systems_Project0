#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.c"

int main() {

//Examples
process_t* procA = createProcess(0, "A");
process_t* procB = createProcess(1, "B");
process_t* procC = createProcess(2, "C");

queue_t* queue = createQueue();

printQueue(queue);	
enqueue(queue, procA);
printQueue(queue);
enqueue(queue, procB);
printQueue(queue);
enqueue(queue, procC);
printQueue(queue);
printf("\n");
free(dequeue(queue));
printQueue(queue);
enqueue(queue, createProcess(3, "A"));
printQueue(queue);
free(dequeue(queue));
printQueue(queue);
enqueue(queue, createProcess(4, "D"));
printQueue(queue);
enqueue(queue, createProcess(5, "E"));
printQueue(queue);
free(dequeue(queue));
printf("\n");
free(dequeue(queue));
printf("\n");
free(dequeue(queue));
printf("\n");
free(dequeue(queue));
printf("\n");
printQueue(queue);


free(queue);


return 0;
}
