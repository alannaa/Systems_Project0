#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

//Creates a single node with `next` set to NULL
node_t* createNode(void *element)
{
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	if (newNode==NULL){
		return NULL;
	}
	newNode->data = element;
	newNode->next = NULL;
	return newNode;
}

//Allocates heap space to a queue; `head` and `tail` set to NULL
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

	node_t* newNode = createNode(element*);
	
	if (queue->head==NULL && queue->tail==NULL){
		queue->head = newNode;
		queue->tail = newNode;
	} else {
		(queue->tail)->next = newNode;
		queue->tail = newNode;
	}
}


//Removes and returns the first element of `queue`
void* dequeue(queue_t *queue)
{
	if (queue==NULL || queue->head==NULL){
		return NULL;
	}

	node_t* temp = queue->head;
	queue->head = temp->next;
	return temp->data;
}


//Printing Helpers
void printProcess(process_t* process)
{
        if (process==NULL){
                printf("element is NULL");
                return;
        }
        printf("[id: %d, name: %s]", process->id, process->name);

}

//Prints a queue that specifically contains type `process_t` 
void printQueue(queue_t* queue)
{
	if(queue==NULL){
		printf("queue is null");
	}

	node_t* nodeItr = queue->head;
	printf(" - Queue: ");
	while(nodeItr!=NULL){
		printProcess(nodeItr->data);
		if (nodeItr->next!=NULL){
			printf(" -> ");
		}
		nodeItr = nodeItr->next;
	}
	printf("\n");
}



//Frees a queue and all of its nodes from heap memory 
//Note: this will not free elements that have been dequeued
void freeQueue(queue_t *queue)
{
	if (queue==NULL){
		return;
	}
	node_t* nodeItr = queue->head;
	while(nodeItr!=NULL){
		node_t* temp = nodeItr;
		free(nodeItr);
		nodeItr = temp->next;
	}
	free(queue);
}
