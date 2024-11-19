#ifndef JOSEFO_2_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct celula tCelula;
typedef struct lista LISTA;

LISTA * lista_inicia();

void lista_insere(LISTA * lista, int valor);

void lista_imprime(LISTA * l);

void lista_remover(LISTA * l, int valor);

int atPos(LISTA * l, int index);

void lista_libera(LISTA * l);

#endif