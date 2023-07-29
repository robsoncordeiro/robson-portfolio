#include "queue.h"

void createQueue(Queue* q) {
    q->total = 0;
    q->ini = 0;
    q->fin = 0;
    return;
}

void emptyQueue(Queue* q) {
    createQueue(q);
    return;
}

int isQueueEmpty(Queue q) {
    return (q.total == 0);
}

int isQueueFull(Queue q) {
    return (q.total == SIZEQUEUE);
}

int enqueue(Queue* q, elemQueue x) {
    if (isQueueFull(*q))
        return 1; // error, the queue is full
    
    q->array[q->fin] = x; // copy info
    q->total++; // update count of elements

    // update the end of the queue
    if (q->fin == SIZEQUEUE - 1)
        q->fin = 0; // restart with a circular behavior
    else
        q->fin++; // go forward

    return 0; // success
}

int dequeue(Queue* q, elemQueue* x) {
    if (isQueueEmpty(*q))
        return 1; // error, the queue is empty
    
    *x = q->array[q->ini]; // copy info
    q->total--; // update count of elements

    // update the beginning of the queue
    if (q->ini == SIZEQUEUE - 1)
        q->ini = 0; // restart with a circular behavior
    else
        q->ini++; // go forward

    return 0; // success
}
