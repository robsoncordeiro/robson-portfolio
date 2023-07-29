#define SIZESTACK 10

#include "queue.h"

typedef Queue elemStack;

typedef struct {
    elemStack array[SIZESTACK];
    int top;
} Stack;

void createStack(Stack* s);
void emptyStack(Stack* s);
int push(Stack* s, elemStack x);
int isStackEmpty(Stack s);
int isStackFull(Stack s);
int pop(Stack* s, elemStack* x);
int top(Stack s, elemStack* x);
