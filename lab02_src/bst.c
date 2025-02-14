#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "queue.h"
#include "stack.h"

struct node {
    int key;
    BST *l;
    BST *r;
};

BST* BST_create(){
    return NULL;
}

BST* create_node(int key) {
    BST *t = malloc(sizeof *t);
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

BST* BST_insert(BST *t, int key) {
    if (t == NULL) {
        return create_node(key);
    } else if (key < t->key) {
        t->l = BST_insert(t->l, key);
    } else if (key > t->key) {
        t->r = BST_insert(t->r, key);
    } //else: (key == t->key)
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

void it_preorder(BST *t, void (*visit)(BST*)) {
    Stack *s = stack_create();
    while (stack_size(s) > 0 || t != NULL) {
        if (t != NULL) {
            (*visit)(t);
            if (t->r != NULL) {
                push(s, t->r);
            }
            t = t->l;
        } else {
          t = pop(s);
        }
    }
    stack_destroy(s);
}

void it_inorder(BST *t, void (*visit)(BST*))  {
    Stack *s = stack_create();
    while (stack_size(s) > 0 || t != NULL) {
        if (t != NULL) {
            push(s, t);
            t = t->l;
        } else {
            t = pop(s);
            (*visit)(t);
            t = t->r;
        }
    }
    stack_destroy(s);
}

void it_postorder(BST *t, void (*visit)(BST*)) {
    Stack *s = stack_create();
    BST *last = NULL;
    while (stack_size(s) > 0 || t != NULL) {
        if (t != NULL) {
            push(s, t);
            t = t->l;
        } else {
            BST *pk = peek(s);
            if (pk->r != NULL && last != pk->r) {
                t = pk->r;
            } else {
                (*visit)(pk);
                last = pop(s);
            }
        }
    }
    stack_destroy(s);
}

void it_levelorder(BST *t, void (*visit)(BST*)) {
    Queue *q = queue_create();
    enqueue(q, t);
    while (queue_size(q) > 0) {
        t = dequeue(q);
        (*visit)(t);
        if (t->l != NULL) {
            enqueue(q, t->l);
        }
        if (t->r != NULL) {
            enqueue(q, t->r);
        }
    }
    queue_destroy(q);
}

void visit_print(BST* t) {
    printf("%d ", t->key);
}
