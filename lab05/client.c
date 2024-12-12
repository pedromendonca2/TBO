// client.c
#include "item.h"
#include <dirent.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>

extern void sort(Item *, int, int);

int main(int argc, char *argv[]) 
{
    if (argc < 2) {
        printf("Uso: %s <caminho para o arquivo>\n", argv[0]);
        return 1;
    }

    int N;
    char *caminho = argv[1];
    char *nome = strrchr(caminho, '/');
    if (nome != NULL) {
        nome++; // Avança o ponteiro para o nome do arquivo
    } else {
        nome = caminho; // Caso não haja '/', o caminho é o próprio nome do arquivo
    }

    if (sscanf(nome, "%d.txt", &N) != 1) {
        printf("Erro: Nome do arquivo inválido. Deve estar no formato 'numero.txt'.\n");
        return 1;
    }

    Item *array = malloc(N * sizeof(int));
    if (array == NULL) {
        printf("Erro de alocação de memória\n");
        return 1;
    }

    FILE *file = fopen(caminho, "r");

    if (file == NULL) {
        fprintf(stderr, "ERROR: Could not open file '%s'!\n", caminho);
        free(array);
        return 1;
    }

    for (int i = 0; i < N; i++) fscanf(file, "%d\n", &array[i]);

    fclose(file);

    srand(time(NULL));
    clock_t start, stop;

    start = clock();
    sort(array, 0, N - 1);
    stop = clock();

    double time_taken = ((double)(stop - start)) / CLOCKS_PER_SEC;

    // Output time to a file
    FILE *output = fopen("temp_result.txt", "w");
    if (output == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        free(array);
        return 1;
    }

    fprintf(output, "%.6f\n", time_taken);
    //for(int i=0; i<N; i++) printf("%d ", array[i]);
    //printf("%.6f\n", time_taken);
    fclose(output);

    free(array);
    return 0;
}
