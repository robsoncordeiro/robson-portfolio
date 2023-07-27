#define SIZE 10 // comment print commands and increase SIZE to check the runtime
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "avl.h"

int main(void) {
    AVL t;
    elem x;
    int total, success;
    clock_t c_initial, c_insertion, c_search, c_removal;
    
    c_initial = clock();
    
    create(&t);
    
    c_insertion = clock();
    for (x = 0; x < SIZE; x++) { // insert elements in order; worst-case scenario
        insert(&t, x);
        inOrder(t);
    }
    printf("Insertion: %0.3lf seconds.\n",(double)(clock()-c_insertion)/CLOCKS_PER_SEC);
    
    printf("Tree height after inserting %d elements: %d\n", SIZE, height(t));
    printf("Resulting tree: ");
    print(t);
    
    c_search = clock();
    for (total = 0; total < SIZE; total++) {
        x = rand() % (2*SIZE);
        success = search(t, x);
        printf("Searching %d: %s\n", x, (success) ? "found" : "not found");
    }
    printf("Search: %0.3lf seconds.\n",(double)(clock()-c_search)/CLOCKS_PER_SEC);
    
    c_removal = clock();
    for (x = SIZE-1; x >= 0; x--) { // delete elements in descending order; worst-case scenario
        delete(&t, x);
        inOrder(t);
        if (x == SIZE/2) {
            printf("Tree height after removing %d elements: %d\n", SIZE-x, height(t));
            printf("Resulting tree: ");
            print(t);
        }
    }
    printf("Removal: %0.3lf seconds.\n",(double)(clock()-c_removal)/CLOCKS_PER_SEC);
    
    destroy(&t);
    
    printf("Total: %0.3lf seconds.\n",(double)(clock()-c_initial)/CLOCKS_PER_SEC);
    
    return 0;
}
