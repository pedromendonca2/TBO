#include "item.h"

#define MAX_SIZE 10000000 // Suporta até 10 milhões de inteiros.
#define push2(A, B) push(B); push(A)

typedef struct stack {
    int array[MAX_SIZE];
    int top;
} tStack;

tStack* stack = NULL;

void stack_init(){
    stack = malloc(sizeof(tStack));
    if (!stack) {
        printf("Erro ao alocar memória para a pilha.\n");
        exit(1);
    }
    stack->top = -1;
}

void push(int element){
    if (stack->top == MAX_SIZE - 1) { // Verifica se a pilha está cheia.
        printf("Pilha cheia\n");
        exit(1);
    }
    stack->array[++stack->top] = element; // Incrementa o topo e insere o elemento.
}

int pop() {
    if (stack->top == -1) { // Verifica se a pilha está vazia.
        printf("Pilha vazia\n");
        exit(1); // Abortamos em caso de acesso inválido.
    }
    return stack->array[stack->top--]; // Retorna o elemento do topo e decrementa.
}

int stack_empty(){
    return stack->top == -1;
}

int partition(Item *a, int lo, int hi) {
    int i = lo, j = hi+1;
    Item v = a[lo];
    while(1) {
        while (less(a[++i], v)) // Find item on left to swap.
            if (i == hi) break;
        while (less(v, a[--j])) // Find item on right to swap.
            if (j == lo) break;
        if (i >= j) break; // Check if pointers cross.
        exch(a[i], a[j]);
    }
    exch(a[lo], a[j]); // Swap with partitioning item.
    return j; // Return index of item known to be in place.
}

void quick_sort(Item *a, int lo, int hi) {
    stack_init();
    push2(lo, hi);
    while(!stack_empty()) {
        lo = pop(); hi = pop();
        if (hi <= lo) continue; // Could add cutoff here.
        int i = partition(a, lo, hi);
        if (i-lo > hi-i) { // Test the size of sub-arrays.
            push2(lo, i-1); // Push the larger one.
            push2(i+1, hi); // Sort the smaller one first.
        } else {
            push2(i+1, hi);
            push2(lo, i-1);
        }
    }
    free(stack);
}

void sort(Item *a, int lo, int hi) {
    //shuffle(a, hi-lo+1); // Needed for performance guarantee.
    quick_sort(a, lo, hi);
}