#include "stack.h"

void create(Stack* s) {
    s->top = -1;
    return;
}

void empty(Stack* s) {
    create(s);
    return;
}

int push(Stack* s, elem x) {
    if (isFull(*s))
        return 1; // error, the stack is full
    s->top++;
    s->array[s->top] = x;
    return 0; // success
}

int isEmpty(Stack s) {
    return s.top == -1;
}

int isFull(Stack s) {
    return s.top == SIZE - 1;
}

int pop(Stack* s, elem* x) {
    if (isEmpty(*s))
        return 1; // error, the stack is empty
    *x = s->array[s->top];
    s->top--;
    return 0; // success
}

int top(Stack s, elem* x) {
    if (isEmpty(s))
        return 1; // error, the stack is empty
    *x = s.array[s.top];
    return 0; // sucess
}
