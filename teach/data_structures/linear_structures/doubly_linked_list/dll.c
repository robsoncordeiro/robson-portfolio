#include <stdlib.h>
#include <stdio.h>
#include "dll.h"

void create(List *l) {
    l->ini = NULL;
    l->fin = NULL;
    return;
}

void destroy(List *l) {
    Node *p = l->ini;
    while (l->ini != NULL) {
        l->ini = l->ini->next;
        free(p);
        p = l->ini;
    }
    return;
}

void print(List l) {
    while (l.ini != NULL) {
        printf("%c ", l.ini->info);
        l.ini = l.ini->next;
    }
    printf("\n");
    return;
}

void print_backward(List l) {
    while (l.fin != NULL) {
        printf("%c ", l.fin->info);
        l.fin = l.fin->prev;
    }
    printf("\n");
    return;
}

int insert(List *l, elem x, int pos) {
    Node *current, *prev;
    Node *p = (Node *) malloc(sizeof(Node));
    if (p == NULL)
        return 1; // error
    p->info = x; // copy info
    if (l->ini == NULL) { // empty list
        l->ini = p;
        l->fin = p;
        p->next = NULL;
        p->prev = NULL;
    } else {
        current = l->ini;
        while (current != NULL && (pos - 1) > 0) {
            current = current->next;
            pos--;
        }
        if (current == l->ini) { // insert in the beginning
            p->next = l->ini;
            p->prev = NULL;
            l->ini->prev = p;
            l->ini = p;
        } else
            if (current == NULL) { // insert in the end
                p->next = NULL;
                p->prev = l->fin;
                l->fin->next = p;
                l->fin = p;
            } else { // insert in the middle
                prev = current->prev;
                prev->next = p;
                current->prev = p;
                p->next = current;
                p->prev = prev;
            }
    }
    return 0; // sucess
}
