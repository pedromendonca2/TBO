#include <stdio.h>
#include <stdlib.h>
#include "sieve.h"

static int N;
static int *a;

void sieve_init(int size) {
    N = size;
    a = malloc(N * sizeof(int));
    for (long int i = 2; i < N; i++) {
        a[i] = 1;
    }
}

void sieve_run() {
    for (long int i = 2; i < N; i++) {
        if (a[i]) {
            for (long int j = i; i*j < N; j++) {
                a[i*j] = 0;
            }
        }
    }
}

void sieve_finish() {
    for (long int i = 2; i < N; i++) {
        if (a[i]) {
            printf("%4lu ", i);
        }
    }
    printf("\n");
    free(a);
}
