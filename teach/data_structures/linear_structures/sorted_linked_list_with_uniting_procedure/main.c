#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sll.h"

int main(void) {
    List l1, l2, l3;
    elem x;

    srand(clock());

    printf("Creating a list with 13 random characters...\n");
    create(&l1);
    for (int i = 0; i < 13; i++) {
        do {
           x = (rand() % 26) + 'a'; // random lower case character
        } while(insert(&l1, x)); // insert only without repetition
    }
    print(l1);
    
    printf("Creating another list with the 13 characters remaining...\n");
    create(&l2);
    for (int i = 0; i < 13; i++) {
        do {
	   x = (rand() % 26) + 'a'; // random lowercase character
        } while(search(l1, x) || insert(&l2, x)); // insert only if not in the other list, and without repetition
    }
    print(l2);
    
    printf("Creating a third list with the union of the previous two...\n");
    l3 = unite(&l1, &l2);
    print(l3);
    
    printf("Removing characters from the united list, one by one, until it is empty...\n");
    while (!isEmpty(l3)) {
        x = (rand() % 26) + 'a'; // random lower case character
        if (!delete(&l3, x)) {
            printf("Element %c deleted.\n", x);
            print(l3);
        }
    }

    destroy(&l1);
    destroy(&l2);
    destroy(&l3);
    
    return 0;
}
