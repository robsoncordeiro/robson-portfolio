#include <stdio.h>
#include "queue.h"

int main(void){
    elem x = 0;
    Queue q;
    
    create(&q);
    
    printf("Enqueueing elements from 1 up to %d...\n", SIZE);
    while (!enqueue(&q, ++x))
        printf("Element %d enqueued\n", x);
    
    printf("\nInverting the queue...\n\n");
    invert(&q);

    printf("Dequeueing the elements, one by one, until the queue is empty\n");
    while (!dequeue(&q, &x))
        printf("Element %d dequeued\n", x);
    
    return 0; // success
}
