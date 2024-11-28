#include "item.h"

void sort(Item *a, int lo, int hi){
    for(int i = lo; i<hi; i++){
        int menor = a[i], indice;

        for(int j = i; j<hi; j++){
            if(less(a[j], menor)){
                menor = a[j];
                indice = j;
            }
        }

        exch(a[i], a[indice]);
    }
}