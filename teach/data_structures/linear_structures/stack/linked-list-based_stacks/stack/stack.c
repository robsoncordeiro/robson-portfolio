#include <stdlib.h>
#include "stack.h"

void create(Stack *s) {
    s->top = NULL;
    return;
}

void destroy(Stack *s) {
    Node *p;
    p = s->top;
    while (s->top != NULL) {
        s->top = s->top->next;
        free(p);
        p = s->top;
    }
    return;
}

int push(Stack *s, elem x) {
    // create new node
    Node *aux = (Node *) malloc(sizeof(Node));
    if (aux == NULL)
        return 1; // error
    aux->info = x; // copy info
    aux->next = s->top; // current top is the next of the new node
    s->top = aux; // new node is now the top
    return 0;
}

int isEmpty(Stack s) {
    return (s.top == NULL);
}

int pop(Stack *s, elem *x) {
    Node *aux;
    if (isEmpty(*s))
        return 1; // error
    *x = s->top->info; // copy info
    aux = s->top; // store reference to the top
    s->top = s->top->next; // update top
    free(aux); // erase previous top
    return 0;
}

int top(Stack s, elem *x) {
    if (isEmpty(s))
        return 1; // error
    *x = s.top->info; // copy info
    return 0;
}
