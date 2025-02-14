#ifndef BST_H
#define BST_H

struct node;
typedef struct node BST;

BST* BST_create();
BST* BST_insert(BST *t, int key);
void BST_destroy(BST *t);

int BST_height(BST *t);

void rec_preorder(BST *t, void (*visit)(BST*));
void rec_inorder(BST *t, void (*visit)(BST*));
void rec_postorder(BST *t, void (*visit)(BST*));

void it_preorder(BST *t, void (*visit)(BST*));
void it_inorder(BST *t, void (*visit)(BST*));
void it_postorder(BST *t, void (*visit)(BST*));

void it_levelorder(BST *t, void (*visit)(BST*));

// Basic visitor that just prints the node key.
void visit_print(BST*);

#endif
