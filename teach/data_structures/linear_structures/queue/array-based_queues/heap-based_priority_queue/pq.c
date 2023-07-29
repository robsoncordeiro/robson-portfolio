#include <string.h>
#include "pq.h"

void create(Queue *q) {
    q->total = 0;
    q->ct = 0;
}

int compare(Node n1, Node n2) {
    if ((n1.p < n2.p) || (n1.p == n2.p && n1.it < n2.it))
        return -1; // n1 is smaller than n2
    if ((n1.p > n2.p) || (n1.p == n2.p && n1.it > n2.it))
        return 1; // n2 is smaller than n1
    return 0; // n1 and n2 are equal
}

int isEmpty(Queue q) {
    return q.total == 0;
}

int isFull(Queue q) {
    return q.total == SIZE;
}

int father(int i) {
    return (i - 1) / 2;
}

int sonL(int i) {
    return 2 * i + 1;
}

int sonR(int i) {
    return 2 * i + 2;
}

int enqueue(Queue *q, elem x, priority p) {
    int i, father_i;
    Node aux;
    
    if (isFull(*q))
        return 1; // error, the queue is full
    
    // update the count of elements and the current "timestamp"
    q->total++;
    q->ct++;
    
    // copy info
    strcpy(q->heap[q->total - 1].name, x);
    q->heap[q->total - 1].p = p;
    q->heap[q->total - 1].it = q->ct;
    
    // restore the order by moving the new element up in the heap as needed: bubbling-up or up-heap
    i = q->total - 1;
    father_i = father(i);
    while (i > 0 && compare(q->heap[i], q->heap[father_i]) < 0) {
        // swap father and son
        aux = q->heap[father_i];
        q->heap[father_i] = q->heap[i];
        q->heap[i] = aux;
        // update i and its father
        i = father_i;
        father_i = father(i);
    }
    
    return 0; // success
}

int dequeue(Queue *q, elem x, priority *p) {
    int i, sonL_i, sonR_i;
    Node aux;
    
    if (isEmpty(*q))
        return 1; // error, the queue is empty
    
    // copy info
    strcpy(x, q->heap[0].name);
    *p = q->heap[0].p;
    
    // update the count of elements
    q->total--;
    
    // raise the last element to the root and restore the order by descending it as needed: bubbling-down or down-heap
    q->heap[0] = q->heap[q->total];
    i = 0;
    sonL_i = sonL(i);
    sonR_i = sonR(i);
    while (  sonR_i < q->total &&
             ( ( compare(q->heap[sonL_i], q->heap[i]) < 0) ||
               ( compare(q->heap[sonR_i], q->heap[i]) < 0) )  ) {
        // swap father and smallest son
        if (compare(q->heap[sonL_i], q->heap[sonR_i]) < 0) {
            aux = q->heap[sonL_i];
            q->heap[sonL_i] = q->heap[i];
            q->heap[i] = aux;
            i = sonL_i;
        } else {
            aux = q->heap[sonR_i];
            q->heap[sonR_i] = q->heap[i];
            q->heap[i] = aux;
            i = sonR_i;
        }
            
        // update the sons of i
        sonL_i = sonL(i);
        sonR_i = sonR(i);
    }
    if (sonL_i < q->total && compare(q->heap[sonL_i], q->heap[i]) < 0) {
        // swap father and its remaining son, which is always the left one
        aux = q->heap[sonL_i];
        q->heap[sonL_i] = q->heap[i];
        q->heap[i] = aux;
    }
    
    return 0; // success
}
