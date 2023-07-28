#define SIZE 10

typedef char elem;

typedef struct {
    elem array[SIZE];
    int ini, fin, total;
} Queue;

void create(Queue* q);
void empty(Queue* q);
int isEmpty(Queue q);
int isFull(Queue q);
int enqueue(Queue* q, elem x);
int dequeue(Queue* q, elem* x);
