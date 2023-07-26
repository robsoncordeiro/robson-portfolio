typedef char elem;

typedef struct node {
    elem info;
    struct node *next, *prev;
} Node;

typedef struct {
    Node *ini, *fin;
} List;

void create(List *l);
void destroy(List *l);
void print(List l);
void print_backward(List l);
int insert(List *l, elem x, int pos);
