#include "pilha.h"

struct stack{
    tArvore* array[MAX_SIZE];
    int top;
};

void initStack(tStack* stack){
    stack->top = -1;
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

    int element = stack->array[stack->top];
    stack->top--;
    return element;
}

int isEmpty(tStack* stack){
    if(stack->top == -1) return 1;
    return 0;
}

// void display(tStack* stack, void (*printElement)(void*)){
//     for(int i=stack->top; i>=0; i--){
//         printElement(stack->array[i]);
//     }
// }

// void liberaArray(tStack* stack){
//     for (int j = stack->top; j >= 0; j--) {
//         free(stack->array[j]);
//     }
//     free(stack);
// }