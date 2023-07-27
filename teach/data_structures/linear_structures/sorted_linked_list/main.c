#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sll.h"

int main(void) {
    List l;
    elem x;

    srand(clock());
    
    create(&l);
    
    printf("Creating a list with 10 random characters...\n");
    for (int i = 0; i < 10; i++) {
        do {
	   x = (rand() % 26) + 'a'; // random lower case character
        } while(insert(&l, x)); // insert only without repetition
    }
    print(l);
    
    printf("Removing characters one by one until the list is empty...\n");
    while (!isEmpty(l)) {
        x = (rand() % 26) + 'a'; // random lower case character
        if (!delete(&l, x)) {
            printf("Element %c deleted.\n", x);
            print(l);
        }
    }

    destroy(&l);
    
    return 0;
}
