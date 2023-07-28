#include <stdio.h>
#include <string.h>
#include "queue.h"

int main(void){
    elem x;
    Queue q;


    // Using the queue to store integer numbers
    printf("Creating a queue of integer numbers...\n");
    Type t = integer;
    create(&q, t);

    printf("Enqueueing elements from 1 up to %d...\n", SIZE);
    x.i = 1;
    while(!enqueue(&q, x))
        x.i++;

    printf("Dequeueing the elements...\n");
    while(!dequeue(&q, &x))
        printf("Element: %d\n", x.i);


    // Using the queue to store real numbers
    printf("\n");
    printf("Creating a queue of real numbers...\n");
    t = real;
    create(&q, t);

    printf("Enqueueing elements from 1.0 up to %.1f with step 1.0...\n", ((float) SIZE));
    x.f = 1.0;
    while(!enqueue(&q, x))
        x.f++;

    printf("Dequeueing the elements...\n");
    while(!dequeue(&q, &x))
        printf("Element: %.1f\n", x.f);


    // Using the queue to store strings
    printf("\n");
    printf("Creating a queue of strings...\n");
    t = string;
    create(&q, t);

    printf("Enqueueing the elements \"CA\", \"TX\" and \"FL\"...\n");
    strcpy(x.s, "CA");
    enqueue(&q, x);
    strcpy(x.s, "TX");
    enqueue(&q, x);
    strcpy(x.s, "FL");
    enqueue(&q, x);

    printf("Dequeueing the elements...\n");
    while(!dequeue(&q, &x))
        printf("Element: %s\n", x.s);

    
    return 0; // success
}
