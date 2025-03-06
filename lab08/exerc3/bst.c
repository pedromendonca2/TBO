#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

struct node {
    int key;
    int size;
    BST *l;
    BST *r;
};

int returnSize(BST* t) {
    if (t == NULL) return 0; // Se a árvore for vazia, o tamanho é 0
    
    int ls = (t->l != NULL) ? t->l->size : 0; 
    int rs = (t->r != NULL) ? t->r->size : 0;

    return 1 + ls + rs;
}


BST* BST_create(){
    return NULL;
}

BST* create_node(int key) {
    BST *t = malloc(sizeof *t);
    t->size = 1;
    t->key = key;
    t->l = t->r = NULL;
    return t;
}

void BST_destroy(BST *t) {
    if (t != NULL) {
        BST_destroy(t->l);
        BST_destroy(t->r);
        free(t);
    }
}

BST* partitioning(BST *n, int k) {
    if(n == NULL) return n;  // Se o nó for nulo, retorna o nó nulo

    int t = (n->l != NULL) ? n->l->size : 0;  // Tamanho da subárvore esquerda

    if(t > k){
        n->l = partitioning(n->l, k);
        n = rotate_right(n);
    } else if(t < k){
        n->r = partitioning(n->r, k-t-1);
        n = rotate_left(n);
    }

    return n;
}

BST* balancing(BST *n){
    if (n == NULL || n->size < 2) return n;

    n = partitioning(n, (n->size - 1)/2);

    if (n->l != NULL) n->l = balancing(n->l);
    if (n->r != NULL) n->r = balancing(n->r);

    n->size = returnSize(n);
    return n;
}

BST* insert_root(BST *t, int key) {
    if (t == NULL) {
        return create_node(key);
    } else if (key < t->key) {
        t->l = insert_root(t->l, key);
        t = rotate_right(t);
    } else if (key > t->key) {
        t->r = insert_root(t->r, key);
        t = rotate_left(t);
    }

    t->size = returnSize(t);
    return t;
}

BST* BST_insert(BST *t, int key) {
    if (t == NULL) return create_node(key);
    
    int N = t->size;
    if(rand() % (N+1) == 0) return insert_root(t, key);

    if (key < t->key) {
        t->l = BST_insert(t->l, key);
    } else if (key > t->key) {
        t->r = BST_insert(t->r, key);
    } //else: (key == t->key)

    t->size = returnSize(t);
    return t; // Nothing to do.
}

int BST_height(BST *t) {
    if (t == NULL) {
        return -1;
    }
    int lh = BST_height(t->l);
    int rh = BST_height(t->r);
    if (lh > rh) {
        return lh + 1;
    } else {
        return rh + 1;
    }
}

BST* rotate_right(BST *n) {
    BST *t = n->l;
    n->l = t->r;
    t->r = n;

    n->size = returnSize(n);
    t->size = returnSize(t);
    return t;
}

BST* rotate_left(BST *n) {
    BST *t = n->r;
    n->r = t->l;
    t->l = n;

    n->size = returnSize(n);
    t->size = returnSize(t);
    return t;
}

void rec_preorder(BST *t, void (*visit)(BST*)) {
    (*visit)(t);
    if (t->l != NULL) {
        rec_preorder(t->l, visit);
    }
    if (t->r != NULL) {
        rec_preorder(t->r, visit);
    }
}

void rec_inorder(BST *t, void (*visit)(BST*)) {
    if (t->l != NULL) {
        rec_inorder(t->l, visit);
    }
    (*visit)(t);
    if (t->r != NULL) {
        rec_inorder(t->r, visit);
    }
}

void rec_postorder(BST *t, void (*visit)(BST*)) {
    if (t->l != NULL) {
        rec_postorder(t->l, visit);
    }
    if (t->r != NULL) {
        rec_postorder(t->r, visit);
    }
    (*visit)(t);
}

void visit_print(BST* t) {
    //printf("%d ", t->key);
    printf("%d - altura: %d\n", t->key, t->size);

}
