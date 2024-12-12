#include "item.h"

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

void merge(Item *a, Item *aux, int lo, int mid, int hi) {
    for (int k = lo; k <= hi; k++)
        aux[k] = a[k]; // Copy array
    int i = lo, j = mid+1;
    for (int k = lo; k <= hi; k++) { // Merge
        if (i > mid) a[k] = aux[j++];
        else if (j > hi) a[k] = aux[i++];
        else if (less(aux[j], aux[i])) a[k] = aux[j++];
        else a[k] = aux[i++];
    }
}

void merge_sort(Item *a, Item *aux, int lo, int hi) {
    if (hi <= lo + CUTOFF - 1) {
        insert_sort(a, lo, hi);
        return;
    }
    int mid = lo + (hi - lo) / 2; // Avoid overflow.
    merge_sort(a, aux, lo, mid);
    merge_sort(a, aux, mid+1, hi);
    merge(a, aux, lo, mid, hi);
}

void sort(Item *a, int lo, int hi) {
    int n = (hi - lo) + 1;
    Item *aux = malloc(n * sizeof(Item));
    if (aux == NULL) {
        fprintf(stderr, "Erro: Falha na alocação de memória.\n");
        return;
    }
    merge_sort(a, aux, lo, hi);
    free(aux);
}