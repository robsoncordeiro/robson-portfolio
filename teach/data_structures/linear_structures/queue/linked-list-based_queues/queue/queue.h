typedef char elem;

typedef struct node {
    elem info;
    struct node *next;
} Node;

typedef struct {
    Node *ini, *fin;
} Queue;

void create(Queue *q);
void destroy(Queue *q);
int enqueue(Queue *q, elem x);
int dequeue(Queue *q, elem *x);
int isEmpty(Queue q);