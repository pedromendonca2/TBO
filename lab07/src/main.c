#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "str.h"
#include "msd.h"

typedef struct {
    String *s;
    int index;
} Suffix;

void print_context(int index, int context, String* text, Suffix** suffixes, String* query){
    while(index < text->len && equals_substring(suffixes[index]->s, 0, suffixes[index]->s->len - 1, query)){
        int trueIndex = suffixes[index]->index;
        int start = trueIndex - context;
        int end = trueIndex + context + query->len;

        if (start < 0) {
            start = 0;
        }
        if (end > text->len) {
            end = text->len;
        }

        for(int i = start; i < end; i++){
            printf("%c", text->c[i]);
        }
        index++;
        printf("\n");
    }
}

int binary_search(Suffix** suffixes, String* query, int left, int right){
    int result = -1;

    while(left <= right){
        int mid = left + (right - left) / 2;
        bool starts_with_query = equals_substring(suffixes[mid]->s, 0, suffixes[mid]->s->len - 1, query);

        if(starts_with_query){
            result = mid;
            right = mid - 1;
        } else{
            int cmp = compare(suffixes[mid]->s, query);
            if(cmp == -1){
                left = mid + 1;
            } else{
                right = mid - 1;
            }
        }
    }

    if(result == -1){
        printf("\nThere is no such query!"); 
        exit(0);
    }

    return result;
}

int suffix_compare(const void* a, const void* b){

    Suffix *sa = *(Suffix **)a;
    Suffix *sb = *(Suffix **)b;

    return compare_from(sa->s, sb->s, 0);
}

void destroy_suffixes(Suffix** suffixes, int length){
    for(int i=0; i<length; i++){
        free(suffixes[i]->s);
        free(suffixes[i]);
    }
    free(suffixes);
}

void print_string_file(String *s, FILE* f) {
    for (int i = 0; i < s->len; i++) {
        fprintf(f, "%c", s->c[i]);
    }
}

// Função para processar o arquivo e criar a String formatada
String* process_file(char** query, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return NULL;
    }
    
    char buffer[1024]; // Buffer temporário para leitura
    char *cleaned = malloc(1024 * sizeof(char));
    int len = 0, capacity = 1024;
    int last_was_space = 1; // Para evitar múltiplos espaços consecutivos

    fgets(buffer, sizeof(buffer), file); // Consome a primeira linha
    fscanf(file, "%s", *query);
    (*query)[strlen(*query)] = '\0';
    
    while (fgets(buffer, sizeof(buffer), file)) {
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (isspace(buffer[i])) {
                if (!last_was_space) {
                    if (len >= capacity - 1) {
                        capacity *= 2;
                        cleaned = realloc(cleaned, capacity);
                    }
                    cleaned[len++] = ' ';
                    last_was_space = 1;
                }
            } else {
                if (len >= capacity - 1) {
                    capacity *= 2;
                    cleaned = realloc(cleaned, capacity);
                }
                cleaned[len++] = buffer[i];
                last_was_space = 0;
            }
        }
    }
    
    if (len > 0 && cleaned[len - 1] == ' ') {
        len--; // Remove espaço final se houver
    }
    cleaned[len] = '\0';
    
    fclose(file);
    String *result = create_string(cleaned);
    free(cleaned);
    return result;
}

Suffix** construct_suffixes(String* s){
    Suffix** suffixes = malloc(s->len*sizeof(Suffix*));

    for(int i=0; i<s->len; i++){ //índice do array
        suffixes[i] = malloc(sizeof(Suffix));
        suffixes[i]->index = i;

        suffixes[i]->s = malloc(sizeof(String));
        suffixes[i]->s->c = s->c + i; // Ponteiro para a posição inicial do sufixo
        suffixes[i]->s->len = s->len - i; // Comprimento do sufixo
    }

    return suffixes;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <arquivo_de_entrada>\n", argv[0]);
        return 1;
    }

    char *query_0 = malloc(100 * sizeof(char));
    String *processed_text = process_file(&query_0, argv[1]);
    String *query = create_string(query_0);
    free(query_0);

    int context = atoi(argv[2]);
    if (!processed_text) return 1;

    Suffix** suffixes = construct_suffixes(processed_text);

    srand(time(NULL));
    clock_t start, stop;

    start = clock();
    qsort(suffixes, processed_text->len, sizeof(Suffix*), suffix_compare);
    stop = clock();

    double time_taken = ((double)(stop - start)) / CLOCKS_PER_SEC;
    printf("%.6f\n\n", time_taken);

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // String** substrings = malloc(processed_text->len*sizeof(String*));
    // for(int i=0; i<processed_text->len; i++){
    //     substrings[i] = suffixes[i]->s;
    // }

    // int* indexes = malloc(processed_text->len*sizeof(int));
    // for (int i = 0; i < processed_text->len; i++) indexes[i] = i; // Inicializa os índices

    // srand(time(NULL));
    // clock_t start, stop;

    // start = clock();
    // sort(substrings, processed_text->len, indexes);
    // stop = clock();

    // double time_taken = ((double)(stop - start)) / CLOCKS_PER_SEC;
    // printf("%.6f\n\n", time_taken);

    // for(int i=0; i<processed_text->len; i++){
    //     suffixes[i]->s = substrings[i];
    //     suffixes[i]->index = indexes[i];
    // }

    // free(substrings); free(indexes);
    
    int first_ocurrance = binary_search(suffixes, query, 0, processed_text->len - 1);
    print_context(first_ocurrance, context, processed_text, suffixes, query);

    destroy_suffixes(suffixes, processed_text->len);
    destroy_string(query);
    destroy_string(processed_text);

    return 0;
}
