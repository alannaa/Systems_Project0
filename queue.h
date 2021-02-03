
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

process_t* makeProcess(int id, char* name);
node_t* makeNode(void *element);
queue_t* makeQueue();
void enqueue(queue_t *queue, void *element);
void* dequeue(queue_t *queue);
void printProcess(process_t *process);
void printQueue(queue_t *queue);
void freeNode(node_t *node);
void freeQueue(queue_t *queue);
