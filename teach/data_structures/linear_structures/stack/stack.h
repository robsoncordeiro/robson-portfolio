typedef char elem;

typedef struct node {
    elem info;
    struct node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

void create(Stack *s);
void destroy(Stack *s);
int isEmpty(Stack s);
int push(Stack *s, elem x);
int pop(Stack *s, elem *x);
int top(Stack s, elem *x);
