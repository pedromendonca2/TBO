#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "str.h"

typedef struct {
    String *s;
    int index;
} Suffix;

void print_context(int index, int context, String* text, Suffix** suffixes, String* query){
    //index fala onde o query tá no vetor de sufixos, agora eu preciso saber o index do proprio sufixo e me divertir

    while(equals_substring(suffixes[index]->s, 0, suffixes[index]->s->len - 1, query)){
        int trueIndex = suffixes[index]->index;
        int start = trueIndex - context;
        int end = trueIndex + context + query->len;
        //printf("Length of query: %zu\n", strlen(query->c));

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

    // size_t query_len = strlen(*query);
    // while (query_len > 0 && isspace((*query)[query_len - 1])) {
    //     (*query)[--query_len] = '\0';
    // }
    // while (isspace(**query)) {
    //     (*query)++;
    //     query_len--;
    // }

    (*query)[strlen(*query)] = '\0'; // É isso mesmo?
    
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

Suffix** construct_suffixes(String* s, FILE* f){
    Suffix** suffixes = malloc(s->len*sizeof(Suffix*));

    for(int i=0; i<s->len; i++){ //índice do array
        suffixes[i] = malloc(sizeof(Suffix));
        suffixes[i]->index = i;

        suffixes[i]->s = malloc(sizeof(String));
        suffixes[i]->s->c = s->c + i; // Ponteiro para a posição inicial do sufixo
        suffixes[i]->s->len = s->len - i; // Comprimento do sufixo
    }

    // for(int i=0; i<s->len; i++){
    //     print_string_file(suffixes[i]->s, f);
    //     fprintf(f, "\n");
    // }

    return suffixes;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Uso: %s <arquivo_de_entrada>\n", argv[0]);
        return 1;
    }
    
    FILE* f_out = fopen(argv[1], "w");

    char *query_0 = malloc(100 * sizeof(char));
    String *processed_text = process_file(&query_0, argv[2]);
    String *query = create_string(query_0);
    free(query_0);

    print_string(query);
    //printf("processou\n");
    int context = atoi(argv[3]);
    if (!processed_text) return 1;

    //print_string(processed_text);
    //printf("\n");

    Suffix** suffixes = construct_suffixes(processed_text, f_out);

    qsort(suffixes, processed_text->len, sizeof(Suffix*), suffix_compare);

    //faz uma busca binária no array buscando a 1a aparição do query. Após isso, verifica todas as aparições posteriores, guardando o index de cada uma
    int first_ocurrance = binary_search(suffixes, query, 0, processed_text->len - 1);
    print_context(first_ocurrance, context, processed_text, suffixes, query);
    //faz um while que verifica se se o sufixo começa com o query, se sim, imprime o que tem que imprimir
    //printf("First ocurrance: %d\n", first_ocurrance);

    //for(int i=375883; i<375890; i++) printf("%c", processed_text->c[i]);

    destroy_suffixes(suffixes, processed_text->len);
    destroy_string(query);
    destroy_string(processed_text);

    fclose(f_out);
    return 0;
}
