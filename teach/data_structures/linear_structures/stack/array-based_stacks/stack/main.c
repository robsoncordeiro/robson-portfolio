#include <stdio.h>
#include "stack.h"

int main(void) {
    elem x = 0;
    Stack s;
    
    create(&s);
    
    while(!push(&s, ++x))
        printf("Element %d pushed.\n", x);

    top(s, &x);
    printf("\nTop: %d\n\n", x);
    
    while(!pop(&s, &x))
       printf("Element %d popped.\n", x);
    
    return 0; // success
}
