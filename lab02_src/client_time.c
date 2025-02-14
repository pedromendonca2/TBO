#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"

#define compute_time() (((double) stop - start) / CLOCKS_PER_SEC)

int counter = 0; // Dummy variable to use in the visitor function.

// Silly action to ensure the compiler does not optimize away the call
// to the visitor.
void visit_count(BST *t) {
    counter++;
}

int main(int argc, char *argv[]) {
    int N = atoi(argv[1]);
    srand(time(NULL));

    BST *t = BST_create();
    for (int i = 0; i < N; i++) {
        int r = rand();
        t = BST_insert(t, r);
    }

    printf("Type\t\tRec\tIter\n");
    clock_t start, stop;

    printf("Pre-order\t");
    start = clock();
    rec_preorder(t, &visit_count);
    stop = clock();
    printf("%.3f\t", compute_time());
    start = clock();
    it_preorder(t, &visit_count);
    stop = clock();
    printf("%.3f\n", compute_time());

    printf("In-order\t");
    start = clock();
    rec_inorder(t, &visit_count);
    stop = clock();
    printf("%.3f\t", compute_time());
    start = clock();
    it_inorder(t, &visit_count);
    stop = clock();
    printf("%.3f\n", compute_time());

    printf("Post-order\t");
    start = clock();
    rec_postorder(t, &visit_count);
    stop = clock();
    printf("%.3f\t", compute_time());
    start = clock();
    it_postorder(t, &visit_count);
    stop = clock();
    printf("%.3f\n", compute_time());

    BST_destroy(t);
}
