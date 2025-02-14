#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "joseph.h"

typedef struct cell {
    int id;
    struct cell *next;
} Cell;

static int M;
static int N;
static Cell *v; // We need to keep this pointer for freeing.
static Cell *x;

void joseph_init(int skip, int size) {
    M = skip;
    N = size;
    v = malloc(N * (sizeof *v));
    x = v;
    for (int i = 0; i < N-1; i++) {
        x[i].id = i+1;
        x[i].next = &x[i+1];
    }
    // Last one.
    x[N-1].id = N;
    x[N-1].next = &x[0];
}

void joseph_run(bool print) {
    if (print) {
        printf("ELIMINATED:");
    }
    while (x != x->next) {
        // Stop one position before.
        for (int i = 0; i < M-2; i++) {
            x = x->next;
        }
        if (print) {
            printf(" %d", x->next->id);
        }
        // Eliminate next.
        x->next = x->next->next;
        // Advance one more because otherwise we would
        // be counting in M-1 steps.
        x = x->next;
    }
    if (print) {
        printf("\nELECTED: %d\n", x->id);
    }
}

void joseph_finish() {
    free(v);
}
