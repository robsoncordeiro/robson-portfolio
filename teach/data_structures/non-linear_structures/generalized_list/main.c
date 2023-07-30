#include <stdio.h>
#include "gl.h"

int main(void) {
    List l1, l2, l3, l4, l5, l6;
    
    create(&l1);
    create(&l2);
    create(&l3);
    create(&l4);
    create(&l5);
    create(&l6);
    
    insertAtom(&l1, 'a');
    insertAtom(&l2, 'b');
    insertAtom(&l3, 'c');
    
    insertList(&l2, &l3);
    insertList(&l1, &l2);
    
    printf("List l1 is ");
    print(l1);
    
    if (search(l1, 'a'))
        printf("Element \'a\' was found in l1\n");
    else
        printf("Element \'a\' was NOT found in l1\n");
    
    if (search(l1, 'b'))
        printf("Element \'b\' was found in l1\n");
    else
        printf("Element \'b\' was NOT found in l1\n");
    
    if (search(l1, 'c'))
        printf("Element \'c\' was found in l1\n");
    else
        printf("Element \'c\' was NOT found in l1\n");
    
    if (search(l1, 'd'))
        printf("Element \'d\' was found in l1\n");
    else
        printf("Element \'d\' was NOT found in l1\n");
    
    insertAtom(&l4, 'x');
    insertAtom(&l5, 'y');
    insertAtom(&l6, 'z');
    
    insertList(&l5, &l6);
    insertList(&l4, &l5);
    
    printf("List l4 is ");
    print(l4);
    
    if (areEqual(l1, l4))
        printf("Lists l1 and l4 are equal\n");
    else
        printf("Lists l1 and l4 are NOT equal\n");
    
    if (areStructurallyEqual(l1, l4))
        printf("Lists l1 and l4 are structurally equal\n");
    else
        printf("Lists l1 and l4 are NOT structurally equal\n");
    
    printf("The depth of l1 is %d\n", depth(l1));
    printf("The depth of l4 is %d\n", depth(l4));
    
    destroy(&l1);
    destroy(&l2);
    destroy(&l3);
    destroy(&l4);
    destroy(&l5);
    destroy(&l6);
    
    return 0; // success
}
