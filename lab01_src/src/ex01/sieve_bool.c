#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "sieve.h"

static int N;
static bool *a;

void sieve_init(int size) {
    N = size;
    a = malloc(N * sizeof(bool));
    for (long int i = 2; i < N; i++) {
        a[i] = true;
    }
}

void sieve_run() {
    for (long int i = 2; i < N; i++) {
        if (a[i]) {
            for (long int j = i; i*j < N; j++) {
                a[i*j] = false;
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
