#include <stdio.h>
#include "queue.h"

int main(void) {
    elem x;
    Queue q;
    
    create(&q);
    
    for (x = 0; x < 5; x++) {
       enqueue(&q, x);
       printf("Element %d enqueued.\n", x);
    }

    printf("\n");
    
    while(!dequeue(&q, &x))
       printf("Element %d dequeued.\n", x);

    destroy(&q);
    
    return 0;
}
