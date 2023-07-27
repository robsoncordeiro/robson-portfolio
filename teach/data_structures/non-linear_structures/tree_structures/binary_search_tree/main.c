#define SIZE 10 // comment print commands and increase SIZE to check the runtime
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"

int main(void) {
    BST t;
    elem x;
    int total, success;
    clock_t c_initial, c_insertion, c_search, c_removal;
    
    c_initial = clock();
    
    create(&t);
    
    c_insertion = clock();
    for (total = 0; total < SIZE;) {
        x = rand() % SIZE;
        if (!insert(&t, x)) {
            total++;
            inOrder(t);
        }
    }
    printf("Insertion: %0.3lf seconds.\n",(double)(clock()-c_insertion)/CLOCKS_PER_SEC);
    
    c_search = clock();
    for (total = 0; total < SIZE; total++) {
        x = rand() % (2*SIZE);
        success = search(t, x);
        printf("Searching %d: %s\n", x, (success) ? "found" : "not found");
    }
    printf("Search: %0.3lf seconds.\n",(double)(clock()-c_search)/CLOCKS_PER_SEC);
    
    c_removal = clock();
    while (!isEmpty(t)) {
        x = rand() % (2*SIZE);
        if (!delete(&t, x))
            inOrder(t);
    }
    printf("Removal: %0.3lf seconds.\n",(double)(clock()-c_removal)/CLOCKS_PER_SEC);
    
    destroy(&t);
    
    printf("Total: %0.3lf seconds.\n",(double)(clock()-c_initial)/CLOCKS_PER_SEC);
    
    return 0;
}
