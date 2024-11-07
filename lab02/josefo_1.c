#include "josefo_1.h"

void criaArray(int* array, int N){
    for(int i=0, j=1; i<N; i++, j++){
        array[i] = j;
    }
}

void imprimeArray(int* array, int N){
    for(int i=0; i<(N-1); i++){
        printf("%d\n", array[i]);
    }
}

void removeItem(int* ar_1, int* ar_2, int ind_1, int ind_2){
    ar_2[ind_2] = ar_1[ind_1];
    ar_1[ind_1] = 0;
}

int main(int argc, char* argv[]){

    clock_t start, stop;
    start = clock();

    int N = atoi(argv[1]);
    int M = atoi(argv[2]);

    int array[N];
    int removed[N-1];
    int flag = 1;

    criaArray(array, N);

    int indice_1 = M-1;
    int indice_2 = 0;

    removeItem(array, removed, indice_1, indice_2);
    indice_2++;

    while(flag != 0){
        int minorFlag = 0;
        int minorFlag_2 = 0;
        int soma = 0;

        while(minorFlag_2 == 0){

            indice_1++;
            if(indice_1 == N) indice_1 = 0;

            if(array[indice_1] != 0) soma++;

            if(soma == M){
                removeItem(array, removed, indice_1, indice_2);
                minorFlag_2 = 1;
            }
        }

        for(int i=0; i<N; i++){
            if(array[i] != 0) minorFlag = 1;
        }

        if(minorFlag == 0) flag = 0;
        indice_2++;
    }

    stop = clock();
    double time_taken = ((double) stop - start) / CLOCKS_PER_SEC;

    //imprimeArray(removed, N);
    printf("Elapsed time: %.3f\n", time_taken);

    return 0;
}