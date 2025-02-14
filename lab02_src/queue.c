#include <stdlib.h>
#include "queue.h"

#define MAX_SZ 10000000

#define INC(i) (i = ((i + 1) % MAX_SZ))

struct queue {
    Item v[MAX_SZ];
    int size;
    int first;
    int last;
};

Queue* queue_create() {
    Queue *q = malloc(sizeof *q);
    q->size = 0;
    q->first = -1;
    q->last = -1;
    return q;
}

void queue_destroy(Queue* q) {
    free(q);
}

int queue_size(Queue* q) {
    return q->size;
}

void enqueue(Queue* q, Item e) {
    INC(q->last);
    q->v[q->last] = e;
    q->size++;
    if (q->size == 1) {
        q->first = q->last;
    }
}

Item dequeue(Queue* q) {
    Item e = q->v[q->first];
    INC(q->first);
    q->size--;
    if (q->size == 0) {
        q->first = -1;
        q->last = -1;
    }
    return e;
}
