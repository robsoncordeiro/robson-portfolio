#include <stdlib.h>
#include "queue.h"

void create(Queue *q) {
    q->ini = NULL;
    q->fin = NULL;
    return;
}

void destroy(Queue *q) {
    Node *p;
    p = q->ini;
    while (q->ini != NULL) {
        q->ini = q->ini->next;
        free(p);
        p = q->ini;
    }
    q->fin = NULL;
    return;
}

int enqueue(Queue *q, elem x) {
    Node *aux = (Node *) malloc(sizeof(Node));
    if (aux == NULL)
        return 1; // error
    aux->info = x;
    aux->next = NULL;
    if (isEmpty(*q))
        q->ini = aux;
    else
        q->fin->next = aux;
    q->fin = aux;
    return 0;
}

int dequeue(Queue *q, elem *x) {
    Node *aux;
    if (isEmpty(*q))
        return 1; // error
    *x = q->ini->info;
    aux = q->ini;
    q->ini = q->ini->next;
    if (q->ini == NULL)
        q->fin = NULL;
    free(aux);
    return 0;
}

int isEmpty(Queue q) {
    return (q.ini == NULL);
}
