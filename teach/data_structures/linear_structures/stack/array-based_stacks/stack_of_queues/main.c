#include <stdio.h>
#include "stack.h"

int main(void){
    elemQueue x;
    elemStack q;
    Stack s;
    
    createStack(&s);
    
    printf("Creating a queue with elements 1 and 2 enqueued in that order...\n");
    createQueue(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);

    printf("Pushing the queue to the stack...\n\n");
    push(&s, q);
    
    printf("Creating a second queue, now with elements 3, 4 and 5 enqueued in that order...\n");
    emptyQueue(&q);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    printf("Pushing the queue to the stack...\n\n");
    push(&s, q);
    
    printf("Popping the queues from the stack...\n");
    while (!pop(&s, &q)) {
        printf("New queue popped. Dequeueing its elements...\n");
        while (!dequeue(&q, &x))
            printf("Element %d\n", x);
        printf("\n");
    }
    
    return 0; // success
}
