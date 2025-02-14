#include "item.h"
#include "shuffle.h"

#include "insert_sort.c"

// Versão 7: quick sort recursivo com mediana de 3, cutoff = 20 e shuffle.

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

int median_of_3(Item *a, int lo, int hi) {
    int mid = lo + (hi-lo)/2;
    compexch(a[lo], a[hi]);
    compexch(a[lo], a[mid]);
    compexch(a[mid], a[hi]);
    return mid;
}

#define CUTOFF 20

void quick_sort(Item *a, int lo, int hi) {
    if (hi <= lo + CUTOFF - 1) {
        insert_sort(a, lo, hi);
        return;
    }
    int median = median_of_3(a, lo, hi);
    exch(a[lo], a[median]);
    int j = partition(a, lo, hi);
    quick_sort(a, lo, j-1);
    quick_sort(a, j+1, hi);
}

void sort(Item *a, int lo, int hi) {
    shuffle(a, hi-lo+1);
    quick_sort(a, lo, hi);
}
