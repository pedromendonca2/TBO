#include "arvore.h"
#include "pilha.h"
#include "fila.h"

void read(tArvore* t){
    printf("Chave: %d\n", getNum(t));
}

int main(int args, char* argv[]){

    int N = atoi(argv[1]);

    tArvore* a = criaVazia();
    tStack* stack = initStack();
    tQueue* queue = initQueue();

    srand(time(NULL));

    for(int i=0; i<N; i++){
        int r = rand();
        //printf("%d\n", r);
        a = insereChave(a, r);
    }

    printf("Level Order:\n\n");
    leverOrder(a, read, queue);

    printf("\n");
    printf("Altura: %d\n\n", altura(a));

    clock_t start, stop;

    start = clock();
    rec_preorder(a, read);
    stop = clock();

    double time_taken_1 = ((double) stop - start) / CLOCKS_PER_SEC;
    
    printf("\n");
    start = clock();
    rec_inorder(a, read);
    stop = clock();

    double time_taken_2 = ((double) stop - start) / CLOCKS_PER_SEC;

    printf("\n");
    start = clock();
    rec_postorder(a, read);
    stop = clock();

    double time_taken_3 = ((double) stop - start) / CLOCKS_PER_SEC;

    printf("\n");
    start = clock();
    iterative_preorder(a, read, stack);
    stop = clock();

    double time_taken_4 = ((double) stop - start) / CLOCKS_PER_SEC;

    printf("\n");
    start = clock();
    iterative_inorder(a, read, stack);
    stop = clock();

    double time_taken_5 = ((double) stop - start) / CLOCKS_PER_SEC;

    printf("\n");
    start = clock();
    iterative_postorder(a, read, stack);
    stop = clock();

    double time_taken_6 = ((double) stop - start) / CLOCKS_PER_SEC;

    printf("\nElapsed time with recursive traversal (pre): %.3f\nElapsed time with recursive traversal(in): %.3f\nElapsed time with recursive traversal (post): %.3f\nElapsed time with non-recursive traversal (pre): %.3f\nElapsed time with non-recursive traversal (in): %.3f\nElapsed time with non-recursive traversal (post): %.3f\n", time_taken_1, time_taken_2, time_taken_3, time_taken_4, time_taken_5, time_taken_6);
    
    free(queue);
    free(stack);
    destroi(a);

    return 0;
}