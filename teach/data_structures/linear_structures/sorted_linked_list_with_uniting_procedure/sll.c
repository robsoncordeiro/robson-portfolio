#include <stdlib.h>
#include <stdio.h>
#include "sll.h"

void create(List *l) {
    l->ini = NULL;
    return;
}

void destroy(List *l) {
    Node *p;
    p = l->ini;
    while (l->ini != NULL) {
        l->ini = l->ini->next;
        free(p);
        p = l->ini;
    }
    return;
}

void internal_search(List l, elem x, Node **prev, Node **p) {
    *prev = NULL;
    *p = l.ini;
    while (*p != NULL && (*p)->info < x) {
        *prev = *p;
        *p = (*p)->next;
    }
    return;
}

int insert(List *l, elem x) {
    Node *node, *prev, *p;
    internal_search(*l, x, &prev, &p);
    if (p != NULL && p->info == x)
        return 1; // error, repeated element
    node = (Node *) malloc(sizeof(Node));
    if (node == NULL)
        return 1; // error, insufficient memory
    node->info = x;
    node->next = p;
    if (prev == NULL) // insertion in the beginning
        l->ini = node;
    else // insertion in the middle or in the end
        prev->next = node;
    return 0; // sucess
}

int delete(List *l, elem x) {
    Node *prev, *p;
    internal_search(*l, x, &prev, &p);
    if (p == NULL || p->info > x)
        return 1; // error, not found
    if (p == l->ini)
        l->ini = p->next; // first
    else
        prev->next = p->next; // not first
    free(p);
    return 0;
}

int search(List l, elem x) {
    while (l.ini != NULL && l.ini->info < x)
        l.ini = l.ini->next;
    return (l.ini != NULL && l.ini->info == x);
}

int isEmpty(List l) {
    return l.ini == NULL;
}

void print(List l) {
    printf("List: ");
    while (l.ini != NULL) {
        printf("%c ", l.ini->info);
        l.ini = l.ini->next;
    }
    printf("\n");
    return;
}

// create a list by moving the elements of l1 and l2 into it; lists l1 and l2 become empty after that
List unite(List *l1, List *l2) {
    Node **link_current;
    List l3;
    
    create(&l3);
    link_current = &(l3.ini);
    
    while (l1->ini != NULL && l2->ini != NULL) {
        if (l1->ini->info < l2->ini->info) {
            *link_current = l1->ini;
            l1->ini = l1->ini->next;
        } else {
            *link_current = l2->ini;
            l2->ini = l2->ini->next;
        }
        link_current = &((*link_current)->next);
    }
    
    if (l1->ini == NULL) {
        *link_current = l2->ini;
        l2->ini = NULL;
    } else {
        *link_current = l1->ini;
        l1->ini = NULL;
    }
    
    return l3;
}
