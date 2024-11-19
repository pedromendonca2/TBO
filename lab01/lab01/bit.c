#include "erastotenes.h"

struct num{
    int num;
};

// Função para definir um bit específico como 1 (não primo)
void setBit(tNum* lista, int pos) {
    lista[pos / 32].num |= (1 << (pos % 32)); 
    //Encontra a posição da lista que contém o inteiro em questão, faz um OU bit a bit e 
    //define como 1 tantos bits a esquerda (posição exata do inteiro naqueles 32 bits)
    //o operador |= faz com que se adicione bit 1 sem perder os que estavam lá
    //1010 | 0110 = 1110
}

// Função para verificar se um bit específico é 1 (não primo)
int isBitSet(tNum* lista, int pos) {
    return (lista[pos / 32].num & (1 << (pos % 32))) != 0;
}

void marcaNaoPrimos(tNum* lista, int n){
    for(int i=2; i<n; i++){ 
        if(!isBitSet(lista, i)){
            for(int j=i+1; j<n; j++){
                if(j % i == 0) setBit(lista, j); 
            }
        }
    }
}

void imprimeListaPrimos(tNum* lista, int n){
    for(int i=2; i<n; i++){
        if(!isBitSet(lista, i)) printf("%d\n", i);
    }
}

int main(int argc, char* argv[]){

    int N = atoi(argv[1]);

    int tamanhoLista = (N / 32) + 1;
    tNum* lista = calloc(tamanhoLista, sizeof(int));

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