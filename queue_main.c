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
enqueue(queue, procB);
enqueue(queue, procC);
free(dequeue(queue));
enqueue(queue, createProcess(3, "A"));
free(dequeue(queue));
enqueue(queue, createProcess(4, "D"));
enqueue(queue, createProcess(5, "E"));
free(dequeue(queue));
free(dequeue(queue));
free(dequeue(queue));
free(dequeue(queue));

free(queue);


return 0;
}
