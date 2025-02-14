#include <stdio.h>
#include <stdlib.h>
#include "sieve.h"

#define BYTE 8

static int N;
static unsigned char *a;

#define set_bit(n)    (a[n/BYTE] |= (1U << n%BYTE))
#define clear_bit(n)  (a[n/BYTE] &= ~(1U << n%BYTE))
#define is_set(n)     ((a[n/BYTE] >> n%BYTE) & 1U)

void sieve_init(int size) {
    N = size;
    a = malloc((N/BYTE+1) * sizeof(char));
    for (long int i = 0; i < N; i++) {
        set_bit(i);
    }
}

void sieve_run() {
    for (long int i = 2; i < N; i++) {
        if (is_set(i)) { // a[i]
            for (long int j = i; i*j < N; j++) {
                clear_bit(i*j); //a[i*j] = 0;
            }
        }
    }
}

void sieve_finish() {
    for (long int i = 2; i < N; i++) {
        if (is_set(i)) {
            printf("%4lu ", i);
        }
    }
    printf("\n");
    free(a);
}
