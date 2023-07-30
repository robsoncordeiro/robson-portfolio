#include <stdio.h>
#include "sm.h"

int main(void) {
    Matrix m;
    
    create(&m, 3, 4);
    
    printf("Creating a 3x4 matrix...\n");
    insert(m, 1, 1, 3);
    insert(m, 1, 3, 2);
    insert(m, 2, 1, -1);
    insert(m, 3, 3, 5);
    insert(m, 3, 4, 6);
    insert(m, 1, 4, 7);
    print(m);

    printf("Deleting (1,4)...\n");
    delete(m, 1, 4);
    print(m);
    
    printf("Deleting (3,4)...\n");
    delete(m, 3, 4);
    print(m);
    
    printf("Deleting (3,3)...\n");
    delete(m, 3, 3);
    print(m);
    
    printf("Deleting (2,1)...\n");
    delete(m, 2, 1);
    print(m);
    
    printf("Deleting (1,3)...\n");
    delete(m, 1, 3);
    print(m);
    
    printf("Deleting (1,1)...\n");
    delete(m, 1, 1);
    print(m);
    
    printf("Recreating the matrix...\n");
    insert(m, 1, 1, 3);
    insert(m, 1, 3, 2);
    insert(m, 2, 1, -1);
    insert(m, 3, 3, 5);
    insert(m, 3, 4, 6);
    insert(m, 1, 4, 7);
    print(m);
    
    printf("Summing 1 to Column 1...\n");
    sumToColumn(m, 1, 1);
    print(m);
    
    printf("Summing 2 to Column 2...\n");
    sumToColumn(m, 2, 2);
    print(m);
    
    printf("Summing -2 to Column 3...\n");
    sumToColumn(m, 3, -2);
    print(m);
    
    printf("Summing -6 to Column 4...\n");
    sumToColumn(m, 4, -6);
    print(m);
    
    destroy(&m);
    
    return 0; // success
}
