#include "pilha.h"

void initStack(tStack* stack){
    stack->top = -1;
}

void push(tStack* stack, void* element){
    if(stack->top == MAX_SIZE - 1){
        printf("Pilha cheia\n");
        return;
    }

    stack->top++;
    stack->array[stack->top] = element;
}

void* pop(tStack* stack){
    if(stack->top == -1){
        printf("Pilha vazia\n");
        return 0;
    }

    void* element = stack->array[stack->top];
    stack->top--;
    return element;
}

void display(tStack* stack, void (*printElement)(void*)){
    for(int i=stack->top; i>=0; i--){
        printElement(stack->array[i]);
    }
}

void liberaArray(tStack* stack){
    for (int j = stack->top; j >= 0; j--) {
        free(stack->array[j]);
    }
    free(stack);
}