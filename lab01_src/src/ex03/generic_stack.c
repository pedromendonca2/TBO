#include <stdlib.h>
#include "generic_stack.h"

// Stack with a very, very simple implementation.

#ifndef MAX_SZ
#define MAX_SZ 100
#endif

struct TPREFIX(stack) {
    TYPE v[MAX_SZ];
    int size;
};

TPREFIX(Stack*) TPREFIX(stack_create)() {
    TPREFIX(Stack) *s = malloc(sizeof(*s));
    s->size = 0;
    return s;
}

void TPREFIX(stack_destroy)(TPREFIX(Stack*) s) {
    free(s);
}

void TPREFIX(stack_push)(TPREFIX(Stack*) s, TYPE e) {
    s->v[s->size] = e;
    s->size++;
}

TYPE TPREFIX(stack_pop)(TPREFIX(Stack*) s) {
    s->size--;
    return s->v[s->size];
}

// Returns the stack size.
int TPREFIX(stack_size)(TPREFIX(Stack*) s) {
    return s->size;
}
