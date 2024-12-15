#include "pilha.h"
#include "arvore.h"

struct stack{
    tArvore* array[MAX_SIZE];
    int top;
};

tStack* initStack(){
    tStack* s = malloc(sizeof(tStack));
    s->top = -1;

    return s;
}

void push(tStack* stack, tArvore* element){
    if(stack->top == MAX_SIZE - 1){
        printf("Pilha cheia\n");
        return;
    }

    stack->top++;
    stack->array[stack->top] = element;
}

tArvore* pop(tStack* stack){
    if(stack->top == -1){
        printf("Pilha vazia\n");
        return 0;
    }

    tArvore* element = stack->array[stack->top];
    stack->top--;
    return element;
}

int isEmpty(tStack* stack){
    if(stack->top == -1) return 1;
    return 0;
}

tArvore* peek(tStack* stack){
    return stack->array[stack->top];
}