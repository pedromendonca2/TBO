#include <stdio.h>
#include "bst.h"

int main(void) {
    BST *t = BST_create();

    // Tree creation.
    t = BST_insert(t, 6);
    t = BST_insert(t, 2);
    t = BST_insert(t, 7);
    t = BST_insert(t, 1);
    t = BST_insert(t, 4);
    t = BST_insert(t, 9);
    t = BST_insert(t, 3);
    t = BST_insert(t, 5);
    t = BST_insert(t, 8);

    printf("Pre-order:\n");
    printf("    Recursive: ");
    rec_preorder(t, &visit_print);
    printf("\n    Iterative: ");
    it_preorder(t, &visit_print);
    printf("\nIn-order:\n");
    printf("    Recursive: ");
    rec_inorder(t, &visit_print);
    printf("\n    Iterative: ");
    it_inorder(t, &visit_print);
    printf("\nPost-order:\n");
    printf("    Recursive: ");
    rec_postorder(t, &visit_print);
    printf("\n    Iterative: ");
    it_postorder(t, &visit_print);
    printf("\nLevel-order:\n");
    printf("    Iterative: ");
    it_levelorder(t, &visit_print);
    printf("\n");

    BST_destroy(t);
}
