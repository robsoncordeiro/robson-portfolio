#define SIZEQUEUE 5

typedef char elemQueue;

typedef struct {
    elemQueue array[SIZEQUEUE];
    int ini, fin, total;
} Queue;

void createQueue(Queue* q);
void emptyQueue(Queue* q);
int isQueueEmpty(Queue q);
int isQueueFull(Queue q);
int enqueue(Queue* q, elemQueue x);
int dequeue(Queue* q, elemQueue* x);
