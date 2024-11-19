#include "arvore.h"

int main(int args, char* argv[]){

    int N = atoi(argv[1]);

    tArvore* a = criaVazia();
    srand(time(NULL));

    for(int i=0; i<N; i++){
        int r = rand();
        a = insereChave(a, r);
    }

    imprime(a);
    printf("Altura: %d\n", altura(a));
    
    destroi(a);

    return 0;
}