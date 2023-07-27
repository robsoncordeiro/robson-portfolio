#include <stdlib.h>
#include <stdio.h>
#include "bt.h"

void create(BT *t) {
    t->root = NULL;
    return;
}

void destroySub(Node *p) {
    if (p != NULL) {
        destroySub(p->left); // destroy left subtree
        destroySub(p->right); // destroy right subtree
        free(p); // erase node
    }
    return;
}

void destroy(BT *t) {
    destroySub(t->root); // start recursive process
    t->root = NULL;
    return;
}

int isEmpty(BT t) {
    return t.root == NULL;
}

Node *searchSub(Node *p, elem x) {
    Node *aux;
    if (p == NULL || p->info == x)
        return p; // applies both to when the element was found and when it was not
    aux = searchSub(p->left, x); // left search
    return (aux == NULL) ? searchSub(p->right, x) : aux;
}

Node *search(BT t, elem x) {
    return searchSub(t.root, x); // start recursive process

}

Node * createNode(elem info, Node *left, Node *right) {
    Node *newnode = malloc(sizeof(Node));
    if (newnode != NULL) {
        newnode->info = info;
        newnode->left = left;
        newnode->right = right;
    }
    return newnode;
}

int insertRoot(BT *t, elem x) {
    if (t->root != NULL)
        return 1; // error, root node already exists
    t->root = createNode(x, NULL, NULL);
    if (t->root == NULL)
        return 1; // error, insufficient memory
    return 0; // success
}

int insertLeft(BT t, elem x, elem infoFather) {
    Node *father = searchSub(t.root, infoFather);
    if (father == NULL || father->left != NULL)
        return 1; // error, father not found or already has a left son
    father->left = createNode(x, NULL, NULL);
    if (father->left == NULL)
        return 1; // error, insufficient memory
    return 0; // success
}

int insertRight(BT t, elem x, elem infoFather) {
    Node *father = searchSub(t.root, infoFather);
    if (father == NULL || father->right != NULL)
        return 1; // error, father does not exist or already has a right son
    father->right = createNode(x, NULL, NULL);
    if (father->right == NULL)
        return 1; // error, insufficient memory
    return 0; // success
}

void printSub(Node *p) {
    printf("{");
    if (p != NULL) {
        printf("%c, ", p->info); // print root
        printSub(p->left); // print left subtree
        printf(", ");
        printSub(p->right); // print right subtree
    }
    printf("}");
    return;
}

void print(BT t) {
    printSub(t.root); // start recursive process
    printf("\n");
    return;
}

Node *searchFatherSub(Node *p, elem x) {
    Node *aux;
    if ( p == NULL ||
       ( p->left != NULL && p->left->info == x) ||
       ( p->right != NULL && p->right->info == x) )
        return p; // applies both to when the element was found and when it was not
    aux = searchFatherSub(p->left, x); // search left subtree
    return (aux == NULL) ? searchFatherSub(p->right, x) : aux;
}

Node *searchFather(BT t, elem x) {
    return searchFatherSub(t.root, x); // start recursive process
}

int heightSub(Node *p) {
    int hleft, hright;
    if (p == NULL)
        return 0; // empty tree
    hleft = heightSub(p->left); // height of the left subtree
    hright = heightSub(p->right); // height of the right subtree
    return (hleft > hright) ? hleft + 1 : hright + 1;
}

int height(BT t) {
    return heightSub(t.root); // start recursive process
}

void preOrderSub(Node *p) {
    if (p != NULL) {
        printf("%c ", p->info); // process node before its subtrees
        preOrderSub(p->left); // process left subtree
        preOrderSub(p->right); // process right subtree
    }
    return;
}

void preOrder(BT t) {
    preOrderSub(t.root); // start recursive process
    printf("\n");
    return;
}

void inOrderSub(Node *p) {
    if (p != NULL) {
        inOrderSub(p->left); // process left subtree
        printf("%c ", p->info); // process node after left subtree and before right subtree
        inOrderSub(p->right); // process right subtree
    }
    return;
}

void inOrder(BT t) {
    inOrderSub(t.root); // start recursive process
    printf("\n");
    return;
}

void postOrderSub(Node *p) {
    if (p != NULL) {
        postOrderSub(p->left); // process left subtree
        postOrderSub(p->right); // process right subtree
        printf("%c ", p->info); // process node after subtrees
    }
    return;
}

void postOrder(BT t) {
    postOrderSub(t.root); // start recursive process
    printf("\n");
    return;
}
