#include <stdio.h>
#include "ll.h"

int main(void){
    List l;
    
    create(&l);

    printf("Inserting `i'...\n");
    insert(&l, 'i');
    printf("Inserting `g'...\n");
    insert(&l, 'g');
    printf("Inserting `e'...\n");
    insert(&l, 'e');
    printf("Inserting `c'...\n");
    insert(&l, 'c');
    printf("Inserting `a'...\n");
    insert(&l, 'a');
    printf("\n");
    
    print(l);
    printf("\n");

    printf("Sorting the list by swapping values...\n");
    sort_by_swapping_values(&l);
    print(l);
    printf("\n");

    printf("Inserting `j'...\n");
    insert(&l, 'j');
    printf("Inserting `h'...\n");
    insert(&l, 'h');
    printf("Inserting `f'...\n");
    insert(&l, 'f');
    printf("Inserting `d'...\n");
    insert(&l, 'd');
    printf("Inserting `b'...\n");
    insert(&l, 'b');
    printf("\n");
    
    print(l);
    printf("\n");

    printf("Sorting the list by swapping pointers...\n");
    sort_by_swapping_pointers(&l);
    print(l);
    printf("\n");
    
    printf("Size (computed non-recursively): %d\n", size_non_recursive(l));
    printf("Size (computed recursively): %d\n", size_recursive(l.ini));
    printf("\n");
    
    if (search_non_recursive(l, 'c'))
        printf("Element `c' is in the list\n");
    else
        printf("Element `c' is NOT in the list\n");
    
    if (search_recursive(l.ini, 'x'))
        printf("Element `x' is in the list\n");
    else
        printf("Element `x' is NOT in the list\n");
    printf("\n");
    
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
