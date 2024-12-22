#include "item.h"

void shuffle(Item *a, int N) {
    struct timeval tv; gettimeofday(&tv, NULL);
    srand48(tv.tv_usec);
    for (int i = N-1; i > 0; i--) {
        int j = (unsigned int) (drand48()*(i+1));
        exch(a[i], a[j]);
    }
}

int median_of_3(Item *a, int lo, int hi) {
    int mid = lo + (hi - lo) / 2;

    // Comparar e ordenar os elementos em `lo`, `mid` e `hi`
    compexch(a[lo], a[hi]); // Garantir a[lo] <= a[hi]
    compexch(a[mid], a[lo]); // Garantir a[lo] <= a[mid]
    compexch(a[mid], a[hi]); // Garantir a[mid] <= a[hi]

    // Agora, a mediana está em `mid`
    return mid;
}

void insert_sort(Item *a, int lo, int hi){
    int i = lo;

    while(i < hi){
        int j = i;
        while(j > lo && less(a[j], a[j-1])){
            exch(a[j-1], a[j]);
            j--;
        }
        i++;
    }
}

int partition(Item *a, int lo, int hi) {
    int i = lo, j = hi+1;
    Item v = a[lo];
    while(1) {
        while (less(a[++i], v)) // Find item on left to swap.
            if (i == hi) break;
        while (less(v, a[--j])) // Find item on right to swap.
            if (j == lo) break;
        if (i >= j) break; // Check if pointers cross.
        exch(a[i], a[j]);
    }
    exch(a[lo], a[j]); // Swap with partitioning item.
    return j; // Return index of item known to be in place.
}

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
    shuffle(a, hi-lo+1); // Needed for performance guarantee.
    quick_sort(a, lo, hi);
}