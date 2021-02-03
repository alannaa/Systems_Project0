
typedef struct process{
	int id;
	char* name;
	struct process* next;
}process_t;

typedef struct queue{
	void* head;
	void* tail;
}queue_t;


process_t* createProcess(int id, char* name);
queue_t* createQueue();
void enqueue(queue_t *queue, void *element);
void* dequeue(queue_t *queue);
void printProcess(process_t* process);
void printQueue(queue_t* queue);
void freeQueue(queue_t* queue);
