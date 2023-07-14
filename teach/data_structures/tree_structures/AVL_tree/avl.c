#include <stdlib.h>
#include <stdio.h>
#include "avl.h"

void create(AVL *t) {
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

void destroy(AVL *t) {
    destroySub(t->root); // start recursive process
    t->root = NULL;
    return;
}

int isEmpty(AVL t) {
    return t.root == NULL;
}

void printSub(Node *p) {
    printf("{");
    if (p != NULL) {
        printf("%d:%d, ", p->info, p->fb);
        printSub(p->left);
        printf(", ");
        printSub(p->right);
    }
    printf("}");
    return;
}

void print(AVL t) {
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

int height(AVL t) {
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

void preOrder(AVL t) {
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

void inOrder(AVL t) {
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

void postOrder(AVL t) {
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

int search(AVL t, elem x) {
    return searchSub(t.root, x); // start recursive process
}

Node *createNode(elem info, Node *left, Node *right, int fb) {
    Node *newnode = malloc(sizeof(Node));
    if (newnode != NULL) {
        newnode->info = info;
        newnode->left = left;
        newnode->right = right;
        newnode->fb = fb;
    }
    return newnode;
}

// simple rotation to the left
void L(Node **p) {
    Node *reall, *newRoot;
    newRoot = (*p)->right;
    reall = newRoot->left;
    newRoot->left = *p;
    (*p)->right = reall;
    *p = newRoot;
    return;
}

// simple rotation to the right
void R(Node **p) {
    Node *reall, *newRoot;
    newRoot = (*p)->left;
    reall = newRoot->right;
    newRoot->right = *p;
    (*p)->left = reall;
    *p = newRoot;
    return;
}

// double rotation left-right
void LR(Node **p) {
    L(&((*p)->left)); // rotate left subtree to the left
    R(p); // rotate tree to the right
    return;
}

// double rotation right-left
void RL(Node **p) {
    R(&((*p)->right)); // rotate right subtree to the right
    L(p); // rotate tree to the left
    return;
}

// update factor of balancing after double rotation
void updateFB(Node *p) {
    switch (p->fb) {
        case 0:
            p->left->fb = 0;
            p->right->fb = 0;
            break;
        case 1:
            p->left->fb = -1;
            p->right->fb = 0;
            break;
        case -1:
            p->left->fb = 0;
            p->right->fb = 1;
            break;
    }
    p->fb = 0;
}

int insertSub(Node **p, elem x, int *grew) {
    // p => type Node**; *p => type Node*; **p => type Node
    int ret;
    if (*p == NULL) {
        *p = createNode(x, NULL, NULL, 0);
        *grew = 1; // the tree height grew: an empty subtree became a non empty one
        return *p == NULL; // memory error or success
    }
    if (x == (*p)->info)
        return 1; // error, element already exists
    ret = insertSub((x < (*p)->info) ? &((*p)->left) : &((*p)->right), x, grew); // insert in the appropriate subtree
    if (!ret && *grew) { // if the element was inserted and the tree height grew
        (*p)->fb += (x < (*p)->info) ? -1 : 1; // update factor of balancing
        if ((*p)->fb == 0 || (*p)->fb == 2 || (*p)->fb == -2) {
            *grew = 0; // tree no longer growing: 0 => balancing improved; 2 or -2 => unbalance will be fixed
            switch ((*p)->fb) {
                case 2: // right subtree is too much tall
                    if ((*p)->right->fb == 1) { // same signals
                        L(p); // simple rotation to the left
                        (*p)->left->fb = 0;
                        (*p)->fb = 0;
                    } else { // opposed signals
                        RL(p); // double rotation right-left
                        updateFB(*p); // update factors of balancing
                    }
                    break;
                case -2: // left subtree is too much tall
                    if ((*p)->left->fb == -1) { // same signals
                        R(p); // simple rotation to the right
                        (*p)->right->fb = 0;
                        (*p)->fb = 0;
                    } else { // opposed signals
                        LR(p); // double rotation left-right
                        updateFB(*p); // update factors of balancing
                    }
                    break;
            }
        }
    }
    return ret;
}

int insert(AVL *t, elem x) {
    int grew;
    return insertSub(&(t->root), x, &grew); // start recursive process
}

void rebalance(Node **p, elem x, int *shrank) {
    if (*shrank) { // if the tree did not shrink, there is nothing to be done
        if ((*p)->fb == 0)
            *shrank = 0; // the tree is no longer shrinking, because both subtrees had the same height before the removal
        (*p)->fb += (x < (*p)->info) ? 1 : -1; // update factor of balancing
        switch ((*p)->fb) {
            case 2: // unbalanced to the right
                *shrank = (*p)->right->fb; // the tree stops shrinking only when the child has fb 0
                if ((*p)->right->fb == 1 || (*p)->right->fb == 0) { // same signal or zero
                    L(p); // simple rotation to the left
                    (*p)->left->fb = (*shrank) ? 0 : 1;
                    (*p)->fb = (*shrank) ? 0 : -1;
                } else {
                    RL(p); // double rotation right-left
                    updateFB(*p); // update factors of balancing
                }
                break;
            case -2:  // unbalanced to the left
                *shrank = (*p)->left->fb; // the tree stops shrinking only when the child has fb 0
                if ((*p)->left->fb == -1 || (*p)->left->fb == 0) { // same signal or zero
                    R(p); // simple rotation to the right
                    (*p)->right->fb = (*shrank) ? 0 : -1;
                    (*p)->fb = (*shrank) ? 0 : 1;
                } else {
                    LR(p); // double rotation left-right
                    updateFB(*p); // update factors of balancing
                }
                break;
        }
    }
    return;
}

int deleteSub(Node **p, elem x, int *shrank); // pre-declaration to be used in function deleteLargest()

elem deleteLargest(Node **p, int *shrank) {
    elem infoLargest;
    if ((*p)->right == NULL) { // executed only when it is the largest
        infoLargest = (*p)->info; // store info
        deleteSub(p, (*p)->info, shrank); // delete the largest; note that it will always be the case with no child or the case with one child
    } else {
        infoLargest = deleteLargest(&((*p)->right), shrank);
        rebalance(p, infoLargest, shrank); // update factors of balancing and fix a potential unbalance
    }
    return infoLargest;
}

int deleteSub(Node **p, elem x, int *shrank) {
    // p => type Node**; *p => type Node*; **p => type Node
    int numChildren = 0, ret;
    Node *aux;
    if (*p == NULL)
        return 1; // error, element does not exist
    if ((*p)->info == x) { // if element was found, remove it
        if ((*p)->left != NULL)
            numChildren++;
        if ((*p)->right != NULL)
            numChildren++;
        switch (numChildren) {
            case 0: // no children
                free(*p); // erase node
                *p = NULL; // update link
                *shrank = 1; // the subtree shrank: there was only the root and tree is empty now
                break;
            case 1: // one child
                aux = *p;
                *p = ((*p)->left != NULL) ? (*p)->left : (*p)->right; // update link
                free(aux); // erase node
                *shrank = 1; // the subtree shrank: the grandfather's grandson is now the son
                break;
            case 2: // two children
                (*p)->info = deleteLargest(&((*p)->left), shrank); // remove largest in the left subtree and copy its information to the current node
                rebalance(p, ((*p)->info) - 1, shrank); // update factors of balancing and fix a potential unbalance; ((*p)->info) - 1 forces to go to the left
                break;
        }
        return 0; // success
    }
    ret = deleteSub((x < (*p)->info) ? &((*p)->left) : &((*p)->right), x, shrank); // delete from the appropriate subtree
    if (!ret)
        rebalance(p, x, shrank); // update factors of balancing and fix a potential unbalance
    return ret;
}

int delete(AVL *t, elem x) {
    int shrank;
    return deleteSub(&(t->root), x, &shrank); // start recursive process
}
