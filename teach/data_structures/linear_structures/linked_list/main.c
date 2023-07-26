#include <stdio.h>
#include "ll.h"

int main(void){
    List l;
    
    create(&l);
    
    insert(&l, 'a');
    insert(&l, 'b');
    insert(&l, 'c');
    insert(&l, 'd');
    
    print(l);
    
    printf("Size (computed non-recursively): %d\n", size_non_recursive(l));
    printf("Size (computed recursively): %d\n", size_recursive(l.ini));
    
    if (search_non_recursive(l, 'c'))
        printf("Element `c' is in the list\n");
    else
        printf("Element `c' is NOT in the list\n");
    
    if (search_recursive(l.ini, 'e'))
        printf("Element `e' is in the list\n");
    else
        printf("Element `e' is NOT in the list\n");
    
    printf("Deleting `a'...\n");
    delete_non_recursive(&l, 'a');
    print(l);

    printf("Deleting `c'...\n");
    delete_recursive(&l, l.ini, NULL, 'c');
    print(l);

    printf("Deleting `d'...\n");
    delete_non_recursive(&l, 'd');
    print(l);

    printf("Deleting `b'...\n");
    delete_recursive(&l, l.ini, NULL, 'b');
    print(l);
    
    destroy(&l);
    
    return 0;
}
