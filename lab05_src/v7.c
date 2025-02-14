#include <stdlib.h>
#include <stdio.h>
#include "item.h"

#include "insert_sort.c"

// Versão 7: merge sort bottom up com "cutoff" = 16 e merge skip.

void merge(Item *a, Item *aux, int lo, int mid, int hi) {
    for (int k = lo; k <= hi; k++) {
        aux[k] = a[k];
    }
    int i = lo, j = mid+1;
    for (int k = lo; k <= hi; k++) {
        if (i > mid) {
            a[k] = aux[j++];
        } else if (j > hi) {
            a[k] = aux[i++];
        } else if (less(aux[j], aux[i])) {
            a[k] = aux[j++];
        } else {
            a[k] = aux[i++];
        }
    }
}

#define SZ2      (sz+sz)
#define MIN(X,Y) ((X < Y) ? (X) : (Y))

#define CUTOFF 16

void sort(Item *a, int low, int hi) {
    int N = (hi - low) + 1;
    int y = N - 1;

    // Insertion sort first.
    int sz = CUTOFF;
    for (int lo = low; lo < N; lo += sz) {
        int x = lo + sz - 1;
        insert_sort(a, lo, MIN(x,y));
    }

    Item *aux = malloc(N * sizeof(Item));
    for (sz = CUTOFF; sz < N; sz = SZ2) {
        for (int lo = low; lo < N-sz; lo += SZ2) {
            int x = lo + SZ2 - 1;
            int mid = lo+sz-1;
            if (!less(a[mid+1], a[mid])) continue;
            merge(a, aux, lo, mid, MIN(x,y));
        }
    }
    free(aux);
}
