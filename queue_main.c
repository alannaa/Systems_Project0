#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.c"

int main() {

//Process Examples
process_t* procA = makeProcess(0, "A");
process_t* procB = makeProcess(1, "B");
process_t* procC = makeProcess(2, "C");

printf("%d %s\n", procA->id, procA->name);


//queue_t* queue = createQueue();
/*
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
*/

return 0;
}
