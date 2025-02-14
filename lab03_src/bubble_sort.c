#include "item.h"

void sort(Item *a, int lo, int hi) {
    do {
        int newhi = lo;
        for (int i = lo+1; i <= hi; i++) {
            if (less(a[i], a[i-1])) {
                exch(a[i], a[i-1]);
                newhi = i;
            }
        }
        hi = newhi;
    } while (hi > lo);
}
