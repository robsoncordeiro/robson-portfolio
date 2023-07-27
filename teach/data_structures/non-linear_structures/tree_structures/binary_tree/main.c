#include <stdio.h>
#include "bt.h"

int main(void) {
    BT t;
    
    create(&t);
    
    insertRoot(&t, 'd');
    insertLeft(t, 'b', 'd');
    insertRight(t, 'c', 'b');
    insertLeft(t, 'a', 'b');
    insertRight(t, 'f', 'd');
    insertLeft(t, 'e', 'f');
    insertRight(t, 'g', 'f');
    
    printf("Father of b: %c\n", (searchFather(t, 'b'))->info);
    printf("Father of c: %c\n", (searchFather(t, 'c'))->info);
    printf("Father of a: %c\n", (searchFather(t, 'a'))->info);
    printf("Father of f: %c\n", (searchFather(t, 'f'))->info);
    printf("Father of e: %c\n", (searchFather(t, 'e'))->info);
    printf("Father of g: %c\n", (searchFather(t, 'g'))->info);
    
    print(t);
    
    printf("Height: %d\n", height(t));

    printf("Pre-order: ");
    preOrder(t);
    
    printf("In-order: ");
    inOrder(t);
    
    printf("Post-order: ");
    postOrder(t);
    
    destroy(&t);
    
    return 0;
}
