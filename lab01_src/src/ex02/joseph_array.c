#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "joseph.h"

static int M;
static int N;
static int *id;
static int *next;
static int x;

void joseph_init(int skip, int size) {
    M = skip;
    N = size;
    id = malloc(N * sizeof(int));
    next = malloc(N * sizeof(int));
    for (int i = 0; i < N-1; i++) {
        id[i] = i+1;
        next[i] = i+1;
    }
    // Last one.
    id[N-1] = N;
    next[N-1] = 0;
    x = 0;
}

void joseph_run(bool print) {
    if (print) {
        printf("ELIMINATED:");
    }
    while (x != next[x]) {
        // Stop one position before.
        for (int i = 0; i < M-2; i++) {
            x = next[x];
        }
        if (print) {
            printf(" %d", id[next[x]]);
        }
        // Eliminate next.
        next[x] = next[next[x]];
        // Advance one more because otherwise we would
        // be counting in M-1 steps.
        x = next[x];
    }
    if (print) {
        printf("\nELECTED: %d\n", id[x]);
    }
}

void joseph_finish() {
    free(id);
    free(next);
}
