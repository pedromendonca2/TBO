#include "item.h"

// Versão 1: quick sort clássico top-down (recursivo).

int partition(Item *a, int lo, int hi) {
    int i = lo;
    int j = hi+1;
    Item v = a[lo];
    while(1) {
        while (less(a[++i], v)) {  // Find item on left to swap.
            if (i == hi) {
                break;
            }
        }
        while (less(v, a[--j])) {  // Find item on right to swap.
            if (j == lo) {
                break;
            }
        }
        if (i >= j) { // Check if pointers cross.
            break;
        }
        exch(a[i], a[j]);
    }
    exch(a[lo], a[j]); // Swap with partitioning item.
    return j; // Return index of item known to be in place.
}

void quick_sort(Item *a, int lo, int hi) {
    if (hi <= lo) {
        return;
    }
    int j = partition(a, lo, hi);
    quick_sort(a, lo, j-1);
    quick_sort(a, j+1, hi);
}

void sort(Item *a, int lo, int hi) {
    quick_sort(a, lo, hi);
}
