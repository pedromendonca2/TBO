#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct queue tQueue;
typedef struct arvore tArvore;

tQueue* initQueue();

void insert(tQueue* queue, tArvore* element);

tArvore* remove(tQueue* queue);

int isEmpty(tQueue* queue);

#endif