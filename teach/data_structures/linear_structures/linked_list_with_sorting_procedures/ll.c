#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

void create(List *l) {
    l->ini = NULL;
    l->fin = NULL;
    return;
}

int insert(List *l, elem x) {
    Node *p;
    // create node
    p = (Node *) malloc(sizeof(Node));
    if (p == NULL)
        return 1;
    // set values
    p->info = x;
    p->next = NULL;
    // update links
    if (l->ini == NULL)
        l->ini = p;
    else
        l->fin->next = p;
    l->fin = p;
    return 0;
}

void destroy(List *l) {
    Node *p;
    p = l->ini;
    while (l->ini != NULL) {
        l->ini = l->ini->next;
        free(p);
        p = l->ini;
    }
    l->fin = NULL;
    return;
}

void print(List l) {
    Node *p;
    printf("List: ");
    p = l.ini;
    while (p != NULL) {
        printf("%c ", p->info);
        p = p->next;
    }
    printf("\n");
    return;
}

int size_non_recursive(List l) {
    int sz = 0;
    Node *p;
    if (l.ini != NULL) {
        p = l.ini;
        do {
            sz++;
            p = p->next;
        } while (p != NULL);
    }
    return sz;
}

int size_recursive(Node *p) {
    if (p == NULL)
        return 0;
    else
        return 1 + size_recursive(p->next);
}

int search_non_recursive(List l, elem x) {
    Node *p = l.ini;
    while (p != NULL) {
        if (p->info == x)
            return 1;
        p = p->next;
    }
    return 0;
}

int search_recursive(Node *p, elem x) {
    if (p == NULL)
        return 0;
    else
        if (p->info == x)
            return 1;
        else
            return search_recursive(p->next, x);
}

int delete_non_recursive(List *l, elem x) {
    Node *prev, *p;
    if (l->ini != NULL) {
        p = l->ini;
        prev = NULL;
        while (p != NULL) {
            if (p->info == x) { // found
                // update links
                if (p == l->ini)
                    l->ini = l->ini->next; // first
                else
                    prev->next = p->next; // others
                if (p == l->fin)
                    l->fin = prev; // last
                // delete
                free(p);
                return 1;
            }
            prev = p;
            p = p->next;
        }
    }
    return 0;
}

int delete_recursive(List *l, Node *p, Node *prev, elem x) {
    if (p == NULL)
        return 0;
    else {
        if (p->info == x) { // found
            // update links
            if (p == l->ini)
                l->ini = l->ini->next; // first
            else
                prev->next = p->next; // others
            if (p == l->fin)
                l->fin = prev; // last
	    // delete
            free(p);
            return 1;
        } else
            return delete_recursive(l, p->next, p, x);
    }
}

void swap_values(Node *i, Node *j) {
    elem aux;
    aux = i->info;
    i->info = j->info;
    j->info = aux;
    return;
}

void sort_by_swapping_values(List *l) {
    // quadratic sorting procedure used with illustrative purpose only
    Node *i, *j;
    i = l->ini;
    while (i != l->fin) {
        j = i->next;
        while (j != NULL) {
            if (i->info > j->info)
                swap_values(i, j);
            j = j->next;
        }
        i = i->next;
    }
    return;
}

void swap_pointers(Node **pi, Node **pj, Node **point_to_i, Node **point_to_j) {
    Node *aux;
    if ((*pi)->next == *pj) {
        // i and j in sequence
        *point_to_i = *pj;
        aux = (*pj)->next;
        (*pj)->next = *pi;
        (*pi)->next = aux;
    } else {
        // i and j not in sequence
        aux = (*pi)->next;
        (*pi)->next = (*pj)->next;
        (*pj)->next = aux;
        *point_to_j = *pi;
        *point_to_i = *pj;
    }
    // swap i and j
    aux = *pi;
    *pi = *pj;
    *pj = aux;
    return;
}

void sort_by_swapping_pointers(List *l) {
    // quadratic sorting procedure used with illustrative purpose only
    Node *i, *j, **point_to_i, **point_to_j;
    i = l->ini;
    point_to_i = &(l->ini);
    while (i != l->fin) {
        j = i->next;
        point_to_j = &(i->next);
        while (j != NULL) {
            if (i->info > j->info) {
                if (j == l->fin)
                    l->fin = i; // update fin
                swap_pointers(&i, &j, point_to_i, point_to_j);
            }
            point_to_j = &(j->next);
            j = j->next;
        }
        point_to_i = &(i->next);
        i = i->next;
    }
    return;
}
