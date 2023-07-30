#include <stdlib.h>
#include <stdio.h>
#include "gl.h"

void create(List *l) {
    l->ini = NULL;
    return;
}

void destroyNode(Node *n) {
    if (n != NULL) {
        if (n->type == atom)
            free((elem *) n->info); // destroy atom
        else
            destroyNode(((Node *) n->info)); // destroy sublist
        destroyNode(n->next); // destroy next
        free(n); // destroy the node
    }
    return;
}

void destroy(List *l) {
    destroyNode(l->ini);
    l->ini = NULL;
    return;
}

int insertAtom(List *l, elem x) {
    Node *n = malloc(sizeof(Node));
    if (n == NULL)
        return 1; // error, insufficient memory

    n->info = malloc(sizeof(elem));
    if (n->info == NULL) {
        free(n);
        return 1; // error, insufficient memory
    }

    // copy info
    *((elem *) n->info) = x;

    // define type
    n->type = atom;

    // insert in the list
    n->next = l->ini;
    l->ini = n;
    
    return 0; // success
}

int insertList(List *l, List *x) {
    // Obs.: it destroys the list of origin x

    Node *n = malloc(sizeof(Node));
    if (n == NULL)
        return 1; // error, insufficient memory

    // copy info
    n->info = x->ini;

    // disable the list of origin x
    x->ini = NULL;

    // define type
    n->type = sublist;

    // insert in the list
    n->next = l->ini;
    l->ini = n;
    
    return 0; // success
}

void printNode(Node *n) {
    if (n != NULL) {
        if (n->type == atom)
            printf("%c ", *((elem *) n->info)); // print atom
        else {
            printf("[ ");
            printNode(((Node *) n->info)); // print sublist
            printf("] ");
        }
        printNode(n->next); // print next
    }
    return;
}

void print(List l) {
    printf("[ ");
    printNode(l.ini);
    printf("]\n");
    return;
}

int searchInNode(Node *n, elem x) {
    if (n == NULL)
        return 0; // not found
    else
        if (n->type == atom)
            return (*((elem *) n->info) == x) ? 1 : searchInNode(n->next, x); // search atom or next
        else
            return (searchInNode(((Node *) n->info), x) || searchInNode(n->next, x)); // search sublist or next
}

int search(List l, elem x) {
    return searchInNode(l.ini, x);
}

int areNodesEqual(Node *n1, Node *n2) {
    if ((n1 == NULL && n2 != NULL) || (n1 != NULL && n2 == NULL))
        return 0; // not equal
    else
        if (n1 == NULL)
            return 1; // equal, both are null
        else // no null
            if (n1->type != n2->type)
                return 0; // not equal, distinct types
            else // types are equal
                if (n1->type == atom)
                    return *((elem *) n1->info) == *((elem *) n2->info) && areNodesEqual(n1->next, n2->next); // two atoms
                else
                    return areNodesEqual(((Node *) n1->info), ((Node *) n2->info)) && areNodesEqual(n1->next, n2->next); // two sublists
}

int areEqual(List l1, List l2) {
    return areNodesEqual(l1.ini, l2.ini);
}

int areNodesStructurallyEqual(Node *n1, Node *n2) {
    if ((n1 == NULL && n2 != NULL) || (n1 != NULL && n2 == NULL))
        return 0; // not equal
    else
        if (n1 == NULL)
            return 1; // equal, both are null
        else // no null
            if (n1->type != n2->type)
                return 0; // not equal, distinct types
            else // types are equal
                if (n1->type == atom)
                    return areNodesStructurallyEqual(n1->next, n2->next); // two atoms
                else
                    return areNodesStructurallyEqual(((Node *) n1->info), ((Node *) n2->info)) && areNodesStructurallyEqual(n1->next, n2->next); // two sublists
}

int areStructurallyEqual(List l1, List l2) {
    return areNodesStructurallyEqual(l1.ini, l2.ini);
}

void depthNode(Node *n, int depth, int *pMaxDepth) {
    if (n != NULL) {
        if ((n->type == sublist) && n->info != NULL)
            depthNode( ((Node *) n->info), depth + 1, pMaxDepth); // evaluate sublist
        depthNode(n->next, depth, pMaxDepth); // evaluate next
    }
    if (depth > *pMaxDepth)
        *pMaxDepth = depth;
    return;
}

int depth(List l) {
    int depth = 0, maxDepth = 0;
    if (l.ini != NULL)
        depthNode(l.ini, depth + 1, &maxDepth);
    return maxDepth;
}
