typedef int elem;

typedef struct node {
    elem info;
    struct node *left, *right;
    int fb;
} Node;

typedef struct {
    Node *root;
} AVL;

void create(AVL *t);
void destroy(AVL *t);
int isEmpty(AVL t);
void print(AVL t);
int height(AVL t);
void preOrder(AVL t);
void inOrder(AVL t);
void postOrder(AVL t);
int search(AVL t, elem x);
int insert(AVL *t, elem x);
int delete(AVL *t, elem x);
