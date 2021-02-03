
typedef struct process{
	int id;
	char* name;
}process_t;

typedef struct node{
	void* data;
	struct node* next;
}node_t;

typedef struct queue{
	node_t* head;
	node_t* tail;
}queue_t;


node_t* createNode(void *element);
queue_t* createQueue();
void enqueue(queue_t *queue, void *element);
void* dequeue(queue_t *queue);
void printProcess(process_t *process);
void printQueue(queue_t *queue);
void freeQueue(queue_t *queue);
