#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "event.h"
#include "PQ.h"

// TODO: Aqui você deve implementar uma fila com prioridade mínima para
//       ordenar os eventos por tempo, isto é, o evento com o menor tempo tem
//       a maior prioridade. Veja as funções definidas em 'event.h' para
//       a manipulação das estruturas de evento. A princípio, as funções já
//       existentes em 'event.h' são suficientes para implementar a simulação,
//       isto é, você não precisa implementar mais nada lá.
//
//       Você é livre para implementar a fila com prioridade da forma que quiser
//       mas é recomendado usar um min-heap para obter um bom desempenho. As
//       simulações maiores geram uma quantidade grande de eventos: um
//       limite superior frouxo (mas seguro) para o número máximo simultâneo de
//       eventos é N^3, aonde N é o número de partículas.

// TODO: Crie a struct pq.

struct pq{
    Event** items;
    int size;
    int max;
};

bool greater(Event* e1, Event* e2) {
    return compare(e1, e2) > 0;  // Retorna verdadeiro se e1 ocorre depois de e2
}

void fix_up(PQ *pq, int k) {
    while (k > 1 && greater(pq->items[k / 2], pq->items[k])) {
        exch(&pq->items[k], &pq->items[k / 2]);
        k = k / 2;
    }
}

void fix_down(PQ *pq, int k) {
    while (2 * k <= pq->size) {
        int j = 2 * k;
        if (j < pq->size && greater(pq->items[j], pq->items[j + 1])) {
            j++;
        }
        if (!greater(pq->items[k], pq->items[j])) {
            break;
        }
        exch(&pq->items[k], &pq->items[j]);
        k = j;
    }
}

/*
 * Cria uma nova fila de prioridade mínima com o limite de elementos informado.
 */
PQ* PQ_create(int max_N) {
    // TODO: Implemente a criação da fila que suporta no máximo o número de
    //       de eventos informados no parâmetro.

    PQ* heap = malloc(sizeof(PQ));
    if (heap == NULL) {
        return NULL;  // Falha na alocação de memória
    }

    heap->items = malloc((max_N + 1) *sizeof(Event*));
    if (heap->items == NULL) {
        free(heap);  // Libera a memória alocada para a estrutura
        return NULL;  // Falha na alocação de memória
    }
    heap->size = 0;
    heap->max = max_N;

    return heap;
}

/*
 * Libera a memória da fila.
 */
void PQ_destroy(PQ *pq) {
    // TODO: Implemente essa função que libera toda a memória da fila,
    //       destruindo inclusive os eventos que estavam na fila.

    for(int i = 1; i <= pq->size; i++){
        destroy_event(pq->items[i]);
    }
    free(pq->items);
    free(pq);
}

/*
 * Insere o evento na fila segundo o seu tempo.
 */
void PQ_insert(PQ *pq, Event *e) {
    // TODO: Implemente essa função que insere o evento dado na fila segundo
    //       o tempo do evento.
    //       Assuma que 'e' não é nulo. É importante testar overflow (inserção
    //       em uma fila que já contém o número máximo de eventos) para evitar
    //       dores de cabeça com acessos inválidos na memória.

    if(pq->size >= pq->max){
        perror("Deu ruim aí na insert\n");
        exit(1);
    }
    pq->items[++pq->size] = e;
    fix_up(pq, pq->size);
}

/*
 * Remove e retorna o evento mais próximo.
 */
Event* PQ_delmin(PQ *pq) {
    // TODO: Implemente essa função que remove o evento com o menor tempo da
    //       fila e o retorna.

    if (PQ_is_empty(pq)) return NULL;
    Event* min = pq->items[1];
    exch(&pq->items[1], &pq->items[pq->size]);
    pq->size--;
    fix_down(pq, 1);
    return min;

}

/*
 * Testa se a fila está vazia.
 */
bool PQ_is_empty(PQ *pq) {
    if(pq->size == 0) return true;
    return false;
}

/*
 * Retorna o tamanho da fila.
 */
int PQ_size(PQ *pq) {
    return pq->size;
}
