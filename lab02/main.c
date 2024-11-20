#include "arvore.h"
#include "pilha.h"

void read(tArvore* t){
    printf("Chave: %d\n", getNum(t));
}

int main(int args, char* argv[]){

    int N = atoi(argv[1]);

    tArvore* a = criaVazia();
    tStack* stack = initStack();

    srand(time(NULL));

    for(int i=0; i<N; i++){
        int r = rand();
        //printf("%d\n", r);
        a = insereChave(a, r);
    }

    //printf("\n\n");
    //imprime(a);
    // printf("Altura: %d\n", altura(a));
    // printf("\n");

    clock_t start, stop;

    start = clock();
    rec_preorder(a, read);
    printf("\n");
    rec_postorder(a, read);
    printf("\n");
    rec_inorder(a, read);
    stop = clock();

    double time_taken_1 = ((double) stop - start) / CLOCKS_PER_SEC;

    ///

    start = clock();
    iterative_preorder(a, read, stack);
    printf("\n");
    iterative_postorder(a, read, stack);
    printf("\n");
    iterative_inorder(a, read, stack);
    stop = clock();

    double time_taken_2 = ((double) stop - start) / CLOCKS_PER_SEC;
    printf("\nElapsed time with non-recursive traversal: %.3f\nElapsed time with recursive traversal: %.3f\n", time_taken_2, time_taken_1);
    
    free(stack);
    destroi(a);

    return 0;
}