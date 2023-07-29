#define SIZEELEM 10
#define SIZE 10

typedef char elem[SIZEELEM];

typedef enum {
    high, medium, low
} priority;

typedef struct {
    elem name;
    priority p;
    int it; // insertion "timestamp"
} Node;

typedef struct {
    Node heap[SIZE]; // heap structure implemented as an array of elements
    int total;
    int ct; // current "timestamp". That is, the count of insertion operations performed so far.
            // Obs.: This works as long as ct doesn't surpass INT_MAX. To resolve this, a new 
            //       queue should be created with the elements removed from the current queue.
} Queue;

void create(Queue *q);
int isEmpty(Queue q);
int isFull(Queue q);
int enqueue(Queue *q, elem x, priority p);
int dequeue(Queue *q, elem x, priority *p);
