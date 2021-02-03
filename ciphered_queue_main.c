#include <stdio.h>
#include <stdlib.h>
#include "queue.c"
#include "caesar.c"


//Prints the process to encript and enqueue
//Encripts process `name` using caesar cipher 
//Enqueues the process
//Prints the current state of the queue
//Note: This modifies the original process
void encriptAndEnqueue(queue_t* queue, process_t* proc, int key)
{
	if (queue==NULL || proc==NULL){
		return;
	}
	printf("Enqueue: ");
	printProcess(proc);
	encode(proc->name, key);
	enqueue(queue, proc);
	printQueue(queue);
}


//Dequeues process at the head of the queue
//Decripts process `name` using caesar cipher
//Prints the process (decoded) 
//Prints the current state of the queue
void dequeueAndDecrypt(queue_t* queue, int key)
{
        if (queue==NULL){
                return;
        }
	process_t* proc = dequeue(queue);
	if (proc==NULL){
		return;
	}
	decode(proc->name, key);
        printf("Dequeue: ");
        printProcess(proc);
        printQueue(queue);
	free(proc);//Since printing is the only purpose of the process,
			//free it immediately after printing so as not to lose it
}

int main(){

const int key = 5;

char abc[4] = "abc";
char xyz[4] = "xyz";
char MSG[10] = "secretMSG";

//Messages to encode and enqueue in the form of processes
process_t*  procAbc = makeProcess(1, abc);
process_t* procXyz = makeProcess(2, xyz);
process_t* procMSG = makeProcess(3, MSG);

//Queue building
queue_t* queue = makeQueue();
printQueue(queue);

//En/De-queue and print
encriptAndEnqueue(queue, procAbc, key);

encriptAndEnqueue(queue, procXyz, key);

dequeueAndDecrypt(queue, key);

encriptAndEnqueue(queue, procMSG, key);

dequeueAndDecrypt(queue, key);

dequeueAndDecrypt(queue, key);

freeQueue(queue);

return 0;
}
