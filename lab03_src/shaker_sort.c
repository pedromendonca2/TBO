#include "item.h"

void sort(Item *a, int lo, int hi) {
    while (lo <= hi) {
        int newlo = hi;
        int newhi = lo;
        for (int i = lo+1; i <= hi; i++) {
            if (less(a[i], a[i-1])) {
                exch(a[i], a[i-1]);
                newhi = i;
            }
        }
        hi = newhi - 1;
        for (int i = hi; i >= lo; i--) {
            if (less(a[i+1], a[i])) {
                exch(a[i+1], a[i]);
                newlo = i;
            }
        }
        lo = newlo + 1;
    }
}
