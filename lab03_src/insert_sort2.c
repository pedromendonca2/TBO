#include "item.h"

void sort(Item *a, int lo, int hi) {
    for (int i = lo + 1; i <= hi; i++) {
        int j = i;
        Item v = a[i];
        while (j > lo && less(v, a[j-1])) {
            a[j] = a[j-1];
            j--;
        }
        a[j] = v;
    }
}
