#ifndef ERASTOTENES_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h> 

typedef struct num tNum;

void preencheLista(tNum* lista, int n);

void marcaNaoPrimos(tNum* lista, int n);

void imprimeListaPrimos(tNum* lista, int n);

#endif