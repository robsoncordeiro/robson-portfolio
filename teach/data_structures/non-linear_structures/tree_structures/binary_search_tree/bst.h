typedef int elem;

typedef struct node {
    elem info;
    struct node *left, *right;
} Node;

typedef struct {
    Node *root;
} BST;

void create(BST *t);
void destroy(BST *t);
int isEmpty(BST t);
void print(BST t);
int height(BST t);
void preOrder(BST t);
void inOrder(BST t);
void postOrder(BST t);
int search(BST t, elem x);
int insert(BST *t, elem x);
int delete(BST *t, elem x);
