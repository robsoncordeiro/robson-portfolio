#include <stdio.h>
#include "dll.h"

int main(void) {
    List l;
    elem x;
    int pos;
    
    create(&l);

    printf("Inform an element to insert (type \'*\' to stop): ");
    scanf("%c%*c", &x);
    while (x != '*') {
        printf("Inform the position: ");
        scanf("%d%*c", &pos);
        insert(&l, x, pos);
        printf("Inform another element to insert (type \'*\' to stop): ");
        scanf("%c%*c", &x);
    };

    printf("\nList: ");
    print(l);

    printf("List (backward order): ");
    print_backward(l);

    destroy(&l);
    
    return 0;
}
