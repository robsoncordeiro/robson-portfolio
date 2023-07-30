#include <stdio.h>
#include <stdlib.h>
#include "sm.h"

int create(Matrix *m, int nLines, int nColumns) {
    m->lines = malloc(nLines * sizeof(Node *));
    if (m->lines == NULL)
        return 1; // error, insufficient memory
    
    m->columns = malloc(nColumns * sizeof(Node *));
    if (m->columns == NULL) {
        free(m->lines);
        return 1; // error, insufficient memory
    }
    
    // data initialization
    for (int l = 0; l < nLines; l++)
        m->lines[l] = NULL;

    for (int c = 0; c < nColumns; c++)
        m->columns[c] = NULL;

    m->nLines = nLines;
    m->nColumns = nColumns;
    
    return 0; // success
}

void destroy(Matrix *m) {
    Node *aux;
    for (int l = 0; l < m->nLines; l++) {
        // pass through the line deleting one node at a time
        while (m->lines[l] != NULL) {
            aux = m->lines[l];
            m->lines[l] = m->lines[l]->nextCol;
            free(aux);
        }
    }
    free(m->lines); // destroy array of lines
    free(m->columns); // destroy array of columns
    return;
}

void internalSearch(Node *n, int value, Node **ant, Node **p, int isLine) {
    // ant, p => Node **
    // *ant, *p => Node *
    // **ant, **p => Node

    *ant = NULL;
    *p = n;
    while (  *p != NULL &&
             ( (isLine && (*p)->col < value) ||
               (!isLine && (*p)->lin < value) )  ) {
        *ant = *p;
        *p = (isLine) ? (*p)->nextCol : (*p)->nextLin;
    }
    return;
}

int insert(Matrix m, int lin, int col, elem x) {
    Node *n, *ant, *p;
    
    if (lin > m.nLines || col > m.nColumns)
        return 1; // error, line or column is invalid    
    
    n = malloc(sizeof(Node));
    if (n == NULL)
        return 1; // error, insufficient memory
    
    // search in the line
    internalSearch(m.lines[lin - 1], col, &ant, &p, 1);
    if (p != NULL && p->col == col) {
        free(n);
        return 1; // error, element already exists
    }
    
    // copy info
    n->info = x;
    n->lin = lin;
    n->col = col;
    
    // insert in the list of the line
    n->nextCol = p;
    if (ant == NULL)
        m.lines[lin - 1] = n; // insert in the beginning
    else
        ant->nextCol = n; // insert in the middle or in the end
    
    // insert in the list of the column
    internalSearch(m.columns[col - 1], lin, &ant, &p, 0);
    n->nextLin = p;
    if (ant == NULL)
        m.columns[col - 1] = n; // insert in the beginning
    else
        ant->nextLin = n; // insert in the middle or in the end
    
    return 0; // success
}

int delete(Matrix m, int lin, int col) {
    Node *ant, *p;
    
    if (lin > m.nLines || col > m.nColumns)
        return 1; // error, line or column is invalid
    
    // search in the list of the line
    internalSearch(m.lines[lin - 1], col, &ant, &p, 1);
    if (p == NULL || p->col != col)
        return 1; // error, element not found
    
    // delete from the list of the line
    if (ant == NULL)
        m.lines[lin - 1] = m.lines[lin - 1]->nextCol; // delete from the beginning
    else
        ant->nextCol = p->nextCol; // delete from the middle or the end

    // delete from the list of the column
    internalSearch(m.columns[col - 1], lin, &ant, &p, 0);
    if (ant == NULL)
        m.columns[col - 1] = m.columns[col - 1]->nextLin; // delete from the beginning
    else
        ant->nextLin = p->nextLin; // delete from the middle or the end
    
    free(p); // delete node
    
    return 0; // success
}

void print(Matrix m) {
    Node *aux;
    int c;
    for (int l = 0; l < m.nLines; l++) {
        // print one line
        c = 1;
        aux = m.lines[l];
        while (aux != NULL) {
            for (;c < aux->col; c++)
                printf("0 "); // print the zeros before aux (if any)
            printf("%d ", aux->info);
            c++;
            aux = aux->nextCol;
        }
        for (;c <= m.nColumns; c++)
            printf("0 "); // print the final zeros (if any)
        printf("\n");
    }
    return;
}

int sumToColumn(Matrix m, int col, elem x) {
    // Obs.: it does not prevent error in the malloc of the insertions,
    //       which may occur if memory is insufficient

    Node *aux;
    int lin = 1; // current line being processed
    
    if (col > m.nColumns)
        return 1; // error, the column is invalid
    
    if (x == 0)
        return 0; // success, summing zero to the column changes nothing
    
    aux = m.columns[col - 1];
    while (aux != NULL) {
        for (; lin < aux->lin; lin++)
            insert(m, lin, col, x); // insert nodes before aux (if any)

        aux->info = aux->info + x; // update info of aux
        if (aux->info == 0) { // it became zero, then delete the node
            aux = aux->nextLin;
            delete(m, lin, col);
        } else
            aux = aux->nextLin;
        lin++;
    }

    for (;lin <= m.nLines; lin++)
        insert(m, lin, col, x); // insert the final nodes (if any)
    
    return 0; // success
}
