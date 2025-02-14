#include <stdlib.h>
#include "stack.h"

#define MAX_SZ 10000000

struct stack {
    Item v[MAX_SZ];
    int size;
};

Stack* stack_create() {
    Stack *s = malloc(sizeof *s);
    s->size = 0;
    return s;
}

void stack_destroy(Stack* s) {
    free(s);
}

int stack_size(Stack* s) {
    return s->size;
}

void push(Stack* s, Item e) {
    s->v[s->size] = e;
    s->size++;
}

Item pop(Stack* s) {
    s->size--;
    return s->v[s->size];
}

Item peek(Stack* s) {
    return s->v[s->size - 1];
}
