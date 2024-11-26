#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct queue tQueue;
typedef struct arvore tArvore;

int isQueueFull(tQueue* queue);

int isQueueEmpty(tQueue* queue);

tQueue* initQueue();

void insert(tQueue* queue, tArvore* element);

void withdraw(tQueue* queue);

tArvore* front(tQueue* queue);

#endif