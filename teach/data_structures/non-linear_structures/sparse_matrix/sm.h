typedef int elem;

typedef struct node {
    int lin, col;
    elem info;
    struct node *nextLin, *nextCol;
} Node;

typedef struct {
    Node **lines, **columns;
    int nLines, nColumns;
} Matrix;

int create(Matrix *m, int nLines, int nColumns);
void destroy(Matrix *m);
int insert(Matrix m, int lin, int col, elem x);
int delete(Matrix m, int lin, int col);
void print(Matrix m);
int sumToColumn(Matrix m, int col, elem x);
