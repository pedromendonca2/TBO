#include "item.h"

// Versão 8: Dijkstra 3-way partitioning

void quick_sort(Item *a, int lo, int hi) {
    if (hi <= lo) {
        return;
    }
    Item v = a[lo];
    int lt = lo, gt = hi, i = lo;
    while (i <= gt) {
        if (a[i] < v) {
            exch(a[lt], a[i]);
            lt++; i++;
        } else if (a[i] > v) {
            exch(a[i], a[gt]);
            gt--;
        } else {
            i++;
        }
    }
    quick_sort(a, lo, lt-1);
    quick_sort(a, gt+1, hi);
}

void sort(Item *a, int lo, int hi) {
    quick_sort(a, lo, hi);
}
