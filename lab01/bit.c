#include "erastotenes_1.h"

// Função para definir um bit específico como 1 (não primo)
void setBit(int* lista, int pos) {
    lista[pos / 32] |= (1 << (pos % 32));
}

// Função para verificar se um bit específico é 1 (não primo)
int isBitSet(int* lista, int pos) {
    return (lista[pos / 32] & (1 << (pos % 32))) != 0;
}

void marcaNaoPrimos(int* lista, int n){
    for(int i=2; i<n; i++){ 
        if(!isBitSet(lista, i)){
            for(int j=i+1; j<n; j++){
                if(j % i == 0) setBit(lista, j); 
            }
        }
    }
}

void imprimeListaPrimos(int* lista, int n){
    for(int i=2; i<n; i++){
        if(!isBitSet(lista, i)) printf("%d\n", i);
    }
}

int main(int argc, char* argv[]){

    int N = atoi(argv[1]);

    int tamanhoLista = (N / 32) + 1;
    int* lista = calloc(tamanhoLista, sizeof(int));

    clock_t start, stop;

    start = clock();
    marcaNaoPrimos(lista, N);
    stop = clock();

    //imprimeListaPrimos(lista, N);
    double time_taken = ((double) stop - start) / CLOCKS_PER_SEC;
    printf("Elapsed time: %.3f\n", time_taken);

    free(lista);

    return 0;
}