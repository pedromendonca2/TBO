#include "erastotenes.h"

struct num{
    int num;
    bool flag;
};

void preencheLista(tNum* lista, int n){
    for(int j=0, i=2; j<n; j++, i++){
        lista[j].num = i;
        lista[j].flag = false;
    }
}

void marcaNaoPrimos(tNum* lista, int n){
    for(int i=0; i<n; i++){ 
        if(lista[i].flag == false){
            for(int j=i+1; j<n; j++){
                if(lista[j].num % lista[i].num == 0) lista[j].flag = true; 
            }
        }
    }
}

void imprimeListaPrimos(tNum* lista, int n){
    for(int j=0; j<n; j++){
        if(lista[j].flag == false) printf("%d\n", lista[j].num);
    }
}

int main(int argc, char* argv[]){

    int N = atoi(argv[1]);

    tNum* lista = malloc(N * sizeof(tNum));

    preencheLista(lista, N);

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