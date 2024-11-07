#ifndef PILHA_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 30

typedef struct{
    void* array[MAX_SIZE];
    int top;
} tStack;

void initStack(tStack* stack);

void push(tStack* stack, void* element);

void* pop(tStack* stack);

void display(tStack* stack, void (*printElement)(void*));

void destroy(tStack* stack, void (*destroyElement)(void*));

void liberaArray(tStack* stack);

#endif