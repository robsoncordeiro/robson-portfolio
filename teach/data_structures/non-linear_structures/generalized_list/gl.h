typedef char elem;

typedef enum {
    atom, sublist
} Type;

typedef struct node {
    void *info;
    Type type;
    struct node *next;
} Node;

typedef struct {
    Node *ini;
} List;

void create(List *l);
void destroy(List *l);
int insertAtom(List *l, elem x);
int insertList(List *l, List *x);
void print(List l);
int search(List l, elem x);
int areEqual(List l1, List l2);
int areStructurallyEqual(List l1, List l2);
int depth(List l);
