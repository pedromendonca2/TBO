#ifndef MSD_H
#define MSD_H
#define char_at(S, D) ((D < S->len) ? S->c[D] : -1)

#include <stdio.h>
#include <stdlib.h>
#include "str.h"

int* create_count_array(int N);

void count_sort(String* *a, String* *aux, int *count, int lo, int hi, int d, int range, int* indexes);

void rec_MSD(String* *a, String* *aux, int lo, int hi, int d, int* indexes);

void sort(String* *a, int N, int* indexes);

#endif