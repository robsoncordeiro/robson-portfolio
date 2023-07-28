#include <stdio.h>
#include "queue.h"

int main(void) {
    elem x;
    Queue q;
    
    create(&q);
    
    x = 0;
    printf("Enqueueing elements from 1 up to %d...\n", SIZE);
    while(!enqueue(&q, ++x));
    
    printf("Dequeueing the elements...\n"); 
    while(!dequeue(&q, &x))
        printf("Element: %d\n", x);
    
    return 0;
}
