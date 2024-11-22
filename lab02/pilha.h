#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct stack tStack;
typedef struct arvore tArvore;

tStack* initStack();

void push(tStack* stack, tArvore* element);

tArvore* pop(tStack* stack);

int isEmpty(tStack* stack);

tArvore* peek(tStack* stack);

// void display(tStack* stack, void (*printElement)(void*));

// void destroy(tStack* stack, void (*destroyElement)(void*));

// void liberaArray(tStack* stack);

#endif