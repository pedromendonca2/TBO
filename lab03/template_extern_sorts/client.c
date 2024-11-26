#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"

extern void sort(Item *, int, int);

int main(int argc, char *argv[]) 
{
    // Input
    if (argc < 2) {
        printf("Uso: %s <tamanho do array>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);

    Item *array = malloc(N*sizeof(int));
    if (array == NULL) {
        printf("Erro de alocação de memória\n");
        return 1;
    }

    for(int i=0; i<N; i++){
        scanf("%d", &array[i]);
    }

    // Sort
    sort(array, 0, N-1);

    // Output
    for(int i=0; i<N; i++){
        printf("%d", array[i]);
    }

    free(array);
}
