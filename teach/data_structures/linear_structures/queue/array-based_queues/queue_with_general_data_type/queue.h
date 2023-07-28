#define SIZE 10
#define SIZESTR 3

typedef enum {
    integer, real, string
} Type;

typedef union {
    int i;
    float f;
    char s[SIZESTR];
} elem;

typedef struct {
    elem array[SIZE];
    int ini, fin, total;
    Type type;
} Queue;

void create(Queue* q, Type type);
void empty(Queue* q);
int isEmpty(Queue q);
int isFull(Queue q);
int enqueue(Queue* q, elem x);
int dequeue(Queue* q, elem* x);
