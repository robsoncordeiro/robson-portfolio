#include <stdio.h>
#include "stack.h"

int main(void) {
    elem x;
    Stack s;
    
    create(&s);
    
    for (x = 0; x < 5; x++) {
        push(&s, x);
        printf("Element %d pushed.\n", x);
    }

    top(s, &x);
    printf("\nTop: %d\n\n", x);
    
    while(!pop(&s, &x))
       printf("Element %d popped.\n", x);

    destroy(&s);
    
    return 0;
}
