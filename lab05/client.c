#include "item.h"

extern void sort(Item *, int, int);

int main(int argc, char *argv[]) 
{
    // Input
    if (argc < 2) {
        printf("Uso: %s <tamanho do array>\n", argv[0]);
        return 1;
    }

    int N;
    char *caminho = argv[1];
    char *nome = strrchr(caminho, '/');
    nome++;

    if (sscanf(nome, "%d.txt", &N) != 1) {
        printf("Erro: Nome do arquivo inválido. Deve estar no formato 'numero.txt'.\n");
        return 1;
    }

    Item *array = malloc(N*sizeof(int));
    if (array == NULL) {
        printf("Erro de alocação de memória\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        fprintf(stderr, "ERROR: Could not open file '%s'!\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < N; i++) fscanf(file, "%d\n", &array[i]);

    srand(time(NULL));
    clock_t start, stop;

    start = clock();
    sort(array, 0, N-1); // Sort
    stop = clock();

    double time_taken_1 = ((double) stop - start) / CLOCKS_PER_SEC;
    printf("\nElapsed time: %.3f\n", time_taken_1);

    // Output
    for(int i=0; i<N; i++) printf("%d ", array[i]);
    printf("\n");

    free(array);
    fclose(file);
}
