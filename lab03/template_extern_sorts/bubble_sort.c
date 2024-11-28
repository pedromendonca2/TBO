#include "item.h"

void sort(Item *a, int lo, int hi){
    for(int i=lo; i<hi-1; i++){
        for(int j=lo; j<hi-1-i; j++){
            compexch(a[j], a[j+1]);
        }
    }
}