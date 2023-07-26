typedef char elem;

typedef struct node {
    elem info;
    struct node *next;
} Node;

typedef struct {
    Node *ini, *fin;
} List;

void create(List *l);
int insert(List *l, elem x);
void destroy(List *l);
void print(List l);
int size_non_recursive(List l);
int size_recursive(Node *p);
int search_non_recursive(List l, elem x);
int search_recursive(Node *p, elem x);
int delete_non_recursive(List *l, elem x);
int delete_recursive(List *l, Node *p, Node *prev, elem x);
