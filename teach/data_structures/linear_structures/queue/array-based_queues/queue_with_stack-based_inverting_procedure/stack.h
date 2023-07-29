#define SIZE 10

typedef char elem;

typedef struct {
    elem array[SIZE];
    int top;
} Stack;

void createStack(Stack* s);
void emptyStack(Stack* s);
int push(Stack* s, elem x);
int isStackEmpty(Stack s);
int isStackFull(Stack s);
int pop(Stack* s, elem* x);
int top(Stack s, elem* x);
