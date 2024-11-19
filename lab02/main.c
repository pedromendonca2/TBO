#include "arvore.h"

void read(tArvore* t){
    printf("Chave: %d\n", getNum(t));
}

int main(int args, char* argv[]){

    int N = atoi(argv[1]);

    tArvore* a = criaVazia();
    tStack* stack = malloc(sizeof(tStack));
    initStack(stack);

    srand(time(NULL));

    for(int i=0; i<N; i++){
        int r = rand();
        printf("%d\n", r);
        a = insereChave(a, r);
    }
    printf("\n\n");

    //imprime(a);
    printf("Altura: %d\n", altura(a));
    printf("\n");

    rec_preorder(a, read);
    printf("\n");
    rec_postorder(a, read);
    printf("\n");
    rec_inorder(a, read);
    
    destroi(a);

    return 0;
}