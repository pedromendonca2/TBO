#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"

#define MAX_TRIES 10

int main(int argc, char *argv[]) {
    int N = atoi(argv[1]);
    srand(time(NULL));

    printf("ITER\tHEIGHT\n");

    for (int step = 0; step < MAX_TRIES; step++) {
        printf("%d\t", step);
        BST *t = BST_create();
        for (int i = 0; i < N; i++) {
            int r = rand();
            t = BST_insert(t, r);
        }
        printf("%d\n", BST_height(t));
        BST_destroy(t);
    }
}
