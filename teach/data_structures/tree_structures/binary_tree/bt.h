typedef char elem;

typedef struct node {
    elem info;
    struct node *left, *right;
} Node;

typedef struct {
    Node *root;
} BT;

void create(BT *t);
void destroy(BT *t);
int isEmpty(BT t);
Node *search(BT t, elem x);
Node *searchFather(BT t, elem x);
int insertRoot(BT *t, elem x);
int insertLeft(BT t, elem x, elem infoFather);
int insertRight(BT t, elem x, elem infoFather);
void print(BT t);
int height(BT t);
void preOrder(BT t);
void inOrder(BT t);
void postOrder(BT t);
