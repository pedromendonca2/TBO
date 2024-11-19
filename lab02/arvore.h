#ifndef ARVORE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pilha.h"

typedef struct arvore tArvore;

void rec_preorder(tArvore* t, void (*visit)(tArvore*));

void rec_postorder(tArvore* t, void (*visit)(tArvore*));

void rec_inorder(tArvore* t, void (*visit)(tArvore*));

void iterative_preorder(tArvore* t, void (*visit)(tArvore*), tStack* s);

tArvore* criaVazia();

tArvore* cria(int chave);

tArvore* insereChave(tArvore* a, int chave);

int altura(tArvore* a);

void destroi(tArvore* a);

void imprime(tArvore* a);

int getNum(tArvore* a);

#endif