#ifndef QUEUE_H
#define QUEUE_H

#include "item.h"

typedef struct queue Queue;

Queue* queue_create();
void queue_destroy(Queue*);
int queue_size(Queue*);
void enqueue(Queue*, Item);
Item dequeue(Queue*);

#endif
