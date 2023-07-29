#include <stdio.h>
#include "pq.h"

int main(void) {
    Queue q;
    elem x;
    priority p;
    
    create(&q);
    
    enqueue(&q, "Alice", medium);
    printf("Element enqueued: Alice with medium priority\n");
    enqueue(&q, "Jose", low);
    printf("Element enqueued: Jose with low priority\n");
    enqueue(&q, "Ana", high);
    printf("Element enqueued: Ana with high priority\n\n");
    
    dequeue(&q, x, &p);
    printf("Element dequeued: %s with %s priority\n", x, (p == high) ? "high" : (p == medium) ? "medium" : "low");
    
    enqueue(&q, "Peter", high);
    printf("\nElement enqueued: Peter with high priority\n");
    enqueue(&q, "Lea", medium);
    printf("Element enqueued: Lea with medium priority\n");
    enqueue(&q, "Mary", medium);
    printf("Element enqueued: Mary with medium priority\n\n");
    
    dequeue(&q, x, &p);
    printf("Element dequeued: %s with %s priority\n", x, (p == high) ? "high" : (p == medium) ? "medium" : "low");
    
    enqueue(&q, "Paul", high);
    printf("\nElement enqueued: Paul with high priority\n\n");
    
    while (!dequeue(&q, x, &p))
        printf("Element dequeued: %s with %s priority\n", x, (p == high) ? "high" : (p == medium) ? "medium" : "low");
    
    return 0; // success
}
