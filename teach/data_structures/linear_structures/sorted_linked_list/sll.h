typedef char elem;

typedef struct node {
    elem info;
    struct node *next;
} Node;

typedef struct {
    Node *ini;
} List;

void create(List *l);
void destroy(List *l);
int insert(List *l, elem x);
int delete(List *l, elem x);
int search(List l, elem x);
int isEmpty(List l);
void print(List l);
