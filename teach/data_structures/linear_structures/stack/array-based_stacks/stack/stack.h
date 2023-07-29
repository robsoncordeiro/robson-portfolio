#define SIZE 10

typedef char elem;

typedef struct {
    elem array[SIZE];
    int top;
} Stack;

void create(Stack* s);
void empty(Stack* s);
int push(Stack* s, elem x);
int isEmpty(Stack s);
int isFull(Stack s);
int pop(Stack* s, elem* x);
int top(Stack s, elem* x);
