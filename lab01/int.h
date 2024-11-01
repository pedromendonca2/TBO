#ifndef LAB_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct num tNum;

struct num{
    int num;
    int flag;
};

void preencheLista(tNum* lista, int n);

void marcaNaoPrimos(tNum* lista, int n);

void imprimeListaPrimos(tNum* lista, int n);

#endif