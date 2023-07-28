#include <string.h>
#include "queue.h"

void create(Queue* q, Type type) {
    q->total = 0;
    q->ini = 0;
    q->fin = 0;
    q->type = type;
    return;
}

void empty(Queue* q) {
    create(q, q->type);
    return;
}

int isEmpty(Queue q) {
    return (q.total == 0);
}

int isFull(Queue q) {
    return (q.total == SIZE);
}

int enqueue(Queue* q, elem x) {
    if (isFull(*q))
        return 1; // error

    // copy the info
    switch (q->type) {
        case integer:
            q->array[q->fin].i = x.i;
            break;
        case real:
            q->array[q->fin].f = x.f;
            break;
        case string:
            strcpy(q->array[q->fin].s, x.s);
    }

    q->total++; // update the count of elements

    // update the end of the queue
    if (q->fin == SIZE - 1)
        q->fin = 0; // restart with a circular behavior
    else
        q->fin++; // go forward

    return 0; // success
}

int dequeue(Queue* q, elem* x) {
    if (isEmpty(*q))
        return 1; // error

    // copy the info
    switch (q->type) {
        case integer:
            x->i = q->array[q->ini].i;
            break;
        case real:
            x->f = q->array[q->ini].f;
            break;
        case string:
            strcpy(x->s, q->array[q->ini].s);
    }

    q->total--; // update the count of elements

    // update the beginning of the queue
    if (q->ini == SIZE - 1)
        q->ini = 0; // restart with a circular behavior
    else
        q->ini++; // go forward

    return 0; // success
}
