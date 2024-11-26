#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct arvore tArvore;
typedef struct stack tStack;
typedef struct queue tQueue;

void rec_preorder(tArvore* t, void (*visit)(tArvore*));

void rec_postorder(tArvore* t, void (*visit)(tArvore*));

void rec_inorder(tArvore* t, void (*visit)(tArvore*));

void iterative_preorder(tArvore* t, void (*visit)(tArvore*), tStack* s);

void iterative_postorder(tArvore* t, void (*visit)(tArvore*), tStack* s);

void iterative_inorder(tArvore* t, void (*visit)(tArvore*), tStack* s);

void leverOrder(tArvore* t, void (*visit)(tArvore*), tQueue* q);

tArvore* criaVazia();

tArvore* cria(int chave);

tArvore* insereChave(tArvore* a, int chave);

int altura(tArvore* a);

void destroi(tArvore* a);

void imprime(tArvore* a);

int getNum(tArvore* a);

#endif