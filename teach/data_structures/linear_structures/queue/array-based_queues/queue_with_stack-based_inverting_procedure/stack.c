#include "stack.h"

void createStack(Stack* s) {
    s->top = -1;
    return;
}

void emptyStack(Stack* s) {
    createStack(s);
    return;
}

int push(Stack* s, elem x) {
    if (isStackFull(*s))
        return 1; // error, the stack is full
    s->top++;
    s->array[s->top] = x;
    return 0; // success
}

int isStackEmpty(Stack s) {
    return s.top == -1;
}

int isStackFull(Stack s) {
    return s.top == SIZE - 1;
}

int pop(Stack* s, elem* x) {
    if (isStackEmpty(*s))
        return 1; // error, the stack is empty
    *x = s->array[s->top];
    s->top--;
    return 0; // success
}

int top(Stack s, elem* x) {
    if (isStackEmpty(s))
        return 1; // error, the stack is empty
    *x = s.array[s.top];
    return 0; // success
}
