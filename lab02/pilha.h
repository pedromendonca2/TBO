#ifndef PILHA_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvore.h"

#define MAX_SIZE 30

typedef struct stack tStack;

void initStack(tStack* stack);

void push(tStack* stack, tArvore* element);

tArvore* pop(tStack* stack);

int isEmpty(tStack* stack);

// void display(tStack* stack, void (*printElement)(void*));

// void destroy(tStack* stack, void (*destroyElement)(void*));

// void liberaArray(tStack* stack);

#endif