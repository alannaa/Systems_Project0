#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

process_t* createProcess(int id, char* name)
{
	process_t* newProc = (process_t*)malloc(sizeof(process_t));
	if (newProc==NULL){
		return NULL;
	}
	newProc->id = id;
	newProc->name = name;
	newProc->next = NULL;
	return newProc;
}

queue_t* createQueue()
{
	queue_t* newQ = (queue_t*)malloc(sizeof(queue_t));
	if (newQ==NULL){
		return NULL;
	}
	newQ->head = NULL;
	newQ->tail = NULL;
	return newQ;
}

//Adds `element` to the end of `queue`
void enqueue(queue_t *queue, void *element) 
{
	if (queue==NULL){
		return;
	}
	process_t* newElem = (process_t*)malloc(sizeof(process_t*));
	newElem = (process_t*)element;
	
	if (queue->head==NULL && queue->tail==NULL){
		queue->head = newElem;
		queue->tail = newElem;
	} else {
		
		((process_t*)queue->tail)->next = newElem;
		queue->tail = newElem;
	}
	printf("Enqueue: ");
	printProcess(newElem);
}


//Removes and returns the first element of `queue`
void* dequeue(queue_t *queue)
{
	if (queue==NULL || queue->head==NULL){
		return NULL;
	}
	process_t* temp = ((process_t*)queue->head);
	queue->head = temp->next;
	printf("Dequeue: ");
        printProcess(temp);
	return temp;
}


void printProcess(process_t* process)
{
        if (process==NULL){
                printf("element is NULL");
                return;
        }
        printf("[id: %d, name: %s]", process->id, process->name);

}

void printQueue(queue_t* queue)
{
	if(queue==NULL){
		printf("queue is null");
	}

	process_t* nodeItr = queue->head;
	printf(" - Queue: ");
	while(nodeItr!=NULL){
		printProcess(nodeItr);
		if (nodeItr->next!=NULL){
			printf(" -> ");
		}
		nodeItr = nodeItr->next;
	}
	printf("\n");
}



//Frees a queue and all of its elements from heap memory 
void freeQueue(queue_t *queue)
{
	if (queue==NULL){
		return;
	}
	process_t* nodeItr = queue->head;
	while(nodeItr!=NULL){
		free(nodeItr);
		nodeItr = nodeItr->next;
	}
	free(queue);
}
