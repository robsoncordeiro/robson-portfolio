#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

void create(BST *t) {
    t->root = NULL;
    return;
}

void destroySub(Node *p) {
    if (p != NULL) {
        destroySub(p->left);
        destroySub(p->right);
        free(p);
    }
    return;
}

void destroy(BST *t) {
    destroySub(t->root); // start recursive process
    t->root = NULL;
    return;
}

int isEmpty(BST t) {
    return t.root == NULL;
}

void printSub(Node *p) {
    printf("{");
    if (p != NULL) {
        printf("%d, ", p->info);
        printSub(p->left);
        printf(", ");
        printSub(p->right);
    }
    printf("}");
    return;
}

void print(BST t) {
    printSub(t.root); // start recursive process
    printf("\n");
    return;
}

int heightSub(Node *p) {
    int hleft, hright;
    if (p == NULL)
        return 0; // empty tree
    hleft = heightSub(p->left);
    hright = heightSub(p->right);
    return (hleft > hright) ? hleft + 1 : hright + 1;
}

int height(BST t) {
    return heightSub(t.root); // start recursive process
}

void preOrderSub(Node *p) {
    if (p != NULL) {
        printf("%d ", p->info); // print node before subtrees
        preOrderSub(p->left); // print left subtree
        preOrderSub(p->right); // print right subtree
    }
    return;
}

void preOrder(BST t) {
    preOrderSub(t.root); // start recursive process
    printf("\n");
    return;
}

void inOrderSub(Node *p) {
    if (p != NULL) {
        inOrderSub(p->left); // print left subtree
        printf("%d ", p->info); // print node after left subtree and before right subtree
        inOrderSub(p->right); // print right subtree
    }
    return;
}

void inOrder(BST t) {
    inOrderSub(t.root); // start recursive process
    printf("\n");
    return;
}

void postOrderSub(Node *p) {
    if (p != NULL) {
        postOrderSub(p->left); // print left subtree
        postOrderSub(p->right); // print right subtree
        printf("%d ", p->info); // print node after subtrees
    }
    return;
}

void postOrder(BST t) {
    postOrderSub(t.root); // start recursive process
    printf("\n");
    return;
}

int searchSub(Node *p, elem x) {
    if (p == NULL)
        return 0; // element not found
    if (p->info == x)
        return 1; // element found
    return (x < p->info) ? searchSub(p->left, x) : searchSub(p->right, x); // search appropriate subtree
}

int search(BST t, elem x) {
    return searchSub(t.root, x); // start recursive process
}

Node *createNode(elem info, Node *left, Node *right) {
    Node *newnode = malloc(sizeof(Node));
    if (newnode != NULL) {
        newnode->info = info;
        newnode->left = left;
        newnode->right = right;
    }
    return newnode;
}

int insertSub(Node **p, elem x) {
    // p => type Node**; *p => type Node*; **p => type Node
    if (*p == NULL) {
        *p = createNode(x, NULL, NULL);
        return (*p == NULL) ? 1 : 0; // memory error or success
    }
    if (x == (*p)->info)
        return 1; // error, element already exists
    return (x < (*p)->info) ? insertSub(&((*p)->left), x) : insertSub(&((*p)->right), x);
}

int insert(BST *t, elem x) {
    return insertSub(&(t->root), x); // start recursive process
}

int deleteSub(Node **p, elem x) {
    // p => type Node**; *p => type Node*; **p => type Node
    int numChildren = 0;
    Node *aux, *fatherAux;
    if (*p == NULL)
        return 1; // error, element does not exist
    if ((*p)->info == x) { // if found, remove
        if ((*p)->left != NULL)
            numChildren++;
        if ((*p)->right != NULL)
            numChildren++;
        switch (numChildren) {
            case 0: // no children
                free(*p); // erase
                *p = NULL; // update link
                return 0; // success
            case 1: // one child
                aux = *p;
                *p = ((*p)->left != NULL) ? (*p)->left : (*p)->right; // update link
                free(aux); // erase
                return 0; // success
            case 2: // two children
                // find largest element in left subtree (aux)
                aux = (*p)->left;
                fatherAux = *p;
                while (aux->left != NULL) {
                    fatherAux = aux;
                    aux = aux->right;
                }
                (*p)->info = aux->info; // copy info
                return deleteSub((fatherAux->left == aux) ? &(fatherAux->left) : &(fatherAux->right), aux->info); // erase aux
        }
    }
    return (x < (*p)->info) ? deleteSub(&((*p)->left), x) : deleteSub(&((*p)->right), x); // remove from the appropriate subtree
}

int delete(BST *t, elem x) {
    return deleteSub(&(t->root), x); // start recursive process
}
