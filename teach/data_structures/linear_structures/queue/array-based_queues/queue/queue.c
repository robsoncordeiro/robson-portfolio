#include "queue.h"

void create(Queue* q) {
    q->total = 0;
    q->ini = 0;
    q->fin = 0;
    return;
}

void empty(Queue* q) {
    create(q);
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
    
    q->array[q->fin] = x; // copy info
    q->total++; // update count of elements
    
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

    *x = q->array[q->ini]; // copy info
    q->total--; // update count of elements

    // update the beginning of the queue
    if (q->ini == SIZE - 1)
        q->ini = 0; // restart with a circular behavior
    else
        q->ini++; // go forward
    
    return 0; // success
}
