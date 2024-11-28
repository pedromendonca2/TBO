#include "item.h"

void sort(Item *a, int lo, int hi){
    int i = lo;

    while(i < hi){
        int j = i;
        while(j > 0 && less(a[j], a[j-1])){
            exch(a[j-1], a[j]);
            j--;
        }
        i++;
    }
}