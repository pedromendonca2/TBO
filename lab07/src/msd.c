#include "msd.h"
#define R 256
#define CUTOFF 15

void insertion_sort(String** a, int lo, int hi, int* indexes) {
    for (int i = lo + 1; i <= hi; i++) {
        String* temp = a[i];
        int temp_index = indexes[i];
        int j = i - 1;
        while (j >= lo && compare(a[j], temp) > 0) {
            a[j + 1] = a[j];
            indexes[j + 1] = indexes[j];
            j--;
        }
        a[j + 1] = temp;
        indexes[j + 1] = temp_index;
    }
}

void clear_count_array(int *count, int r) {
    for(int i=0; i<r; i++) count[i] = 0;
}

int* create_count_array(int N) {
    int* a = malloc(N * sizeof(int));
    return a;
}

void count_sort(String* *a, String* *aux, int *count, int lo, int hi, int d, int range, int* indexes) {
    clear_count_array(count, range + 2);

    int* indexes_aux = malloc((hi - lo + 1) * sizeof(int));  // Cópia dos índices

    for (int i = lo; i <= hi; i++) { // Count frequencies.
        count[char_at(a[i], d) + 2]++;
    }

    for (int r = 0; r < range+1; r++) { // Compute cumulates.
        count[r+1] += count[r];
    }

    for (int i = lo; i <= hi; i++) { // Move items.
        int p = count[char_at(a[i], d) + 1]++;
        aux[p] = a[i];
        indexes_aux[p] = indexes[i];
    }

    for (int i = lo; i <= hi; i++) { // Copy back.
        a[i] = aux[i - lo];
        indexes[i] = indexes_aux[i - lo]; // Atualiza o índice com os valores originais
    }

    free(indexes_aux);
}

void rec_MSD(String* *a, String* *aux, int lo, int hi, int d, int* indexes) {
    //if (hi <= lo) return;
    if (hi <= lo + CUTOFF) {
        insertion_sort(a, lo, hi, indexes);
        return;
    }

    //printf("rec_MSD called with lo: %d, hi: %d, d: %d\n", lo, hi, d);

    int* count = create_count_array(R + 2);
    count_sort(a, aux, count, lo, hi, d, R, indexes); // Key-indexed count.

    for (int r = 1; r < R + 1; r++) {
        //printf("rec_MSD sorting range r: %d, lo: %d, hi: %d\n", r, lo + count[r], lo + count[r + 1] - 1);
        if (lo + count[r] <= hi && lo + count[r + 1] - 1 <= hi && lo + count[r] < lo + count[r + 1] - 1) { // Verificação adicional para garantir intervalos válidos
            rec_MSD(a, aux, lo + count[r], lo + count[r + 1] - 1, d + 1, indexes);
        } else {
            //printf("Skipping invalid range r: %d, lo: %d, hi: %d\n", r, lo + count[r], lo + count[r + 1] - 1);
        }
    }

    free(count);
}

void sort(String* *a, int N, int *indexes) {
    String* *aux = create_str_array(N);

    rec_MSD(a, aux, 0, N-1, 0, indexes);

    free(aux);
}