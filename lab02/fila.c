#include "fila.h"
#include "arvore.h"

struct queue{
    tArvore* nodes[MAX_SIZE];
    int first;
    int last;
    int numItems;
};

int isFull(tQueue* queue){
    if(queue->numItems == MAX_SIZE) return 1;
    return 0;
}

int isEmpty(tQueue* queue){
    if(queue->numItems == 0) return 1;
    return 0;
}

tQueue* initQueue(){
    tQueue* q = malloc(sizeof(tQueue));

    q->first = 0;
    q->last = -1;
    q->numItems = 0;

    return q;
}

void insert(tQueue* queue, tArvore* element){
    //if(queue->last == MAX_SIZE-1) queue->last = -1;

    if(isFull(queue)){
        printf("Tá cheia mano\n");
        return;
    }

    queue->last++;
    queue->nodes[queue->last] = element;

    queue->numItems++;
}

tArvore* remove(tQueue* queue){
    if(isEmpty(queue)){
        printf("Tá vazia mano\n");
        return;
    }

    tArvore* node = queue->nodes[queue->first];

    queue->first++;
    queue->numItems--;

    return node;
}
