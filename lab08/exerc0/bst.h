#ifndef BST_H
#define BST_H

struct node;
typedef struct node BST;

int returnSize(BST* t);

BST* BST_create();
BST* BST_insert(BST *t, int key);
void BST_destroy(BST *t);

BST* partitioning(BST *n, int k);
BST* balancing(BST *n);

int BST_height(BST *t);

BST* rotate_right(BST *n);
BST* rotate_left(BST *n);

void rec_preorder(BST *t, void (*visit)(BST*));
void rec_inorder(BST *t, void (*visit)(BST*));
void rec_postorder(BST *t, void (*visit)(BST*));

// Basic visitor that just prints the node key.
void visit_print(BST*);

void void_function(){ printf("Alteration at develop branch"); };

#endif
