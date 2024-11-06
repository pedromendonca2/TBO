#include "josefo_2.h"

struct celula {
	int valor;
	tCelula* prox;
	tCelula* ant;
};

struct lista {
	tCelula* inicio;
	tCelula* fim;
	int tamanho;
};

int main(int argc, char* argv[]){

	clock_t start, stop;
    start = clock();

	int valor;	

	LISTA* lista = lista_inicia();
    LISTA* listaRemovidos = lista_inicia();

	int N = atoi(argv[1]);
    int M = atoi(argv[2]);

	for(int i=1; i<=N; i++){
		lista_insere(lista, i);
	}

    for(int i=1; i<=N-1; i++){
        int valor = atPos(lista, M);
        lista_remover(lista, valor);
		lista_insere(listaRemovidos, valor);
	}

    //lista_imprime(listaRemovidos);
    lista_libera(lista);
	lista_libera(listaRemovidos);

	stop = clock();
    double time_taken = ((double) stop - start) / CLOCKS_PER_SEC;
    printf("Elapsed time: %.3f\n", time_taken);

	return 0;
}

LISTA * lista_inicia(){
	LISTA* new = malloc(sizeof(LISTA));
	new->inicio = NULL;
	new->fim = NULL;
	new->tamanho = 0;
	return new;
}

void lista_insere(LISTA * l, int valor){
	tCelula* new = malloc(sizeof(tCelula));
	new->valor = valor;

	if(l->tamanho == 0){
		l->inicio = new;
		l->fim = new;
		l->tamanho++;
	}
	else if(l->tamanho == 1){
		l->inicio->prox = new;
		l->inicio->ant = new;
		l->fim = new;
		new->ant = l->inicio;
		new->prox = l->inicio;
		l->tamanho++;
	}else{
		l->inicio->ant = new;
		new->prox = l->inicio;
		new->ant = l->fim;
		l->fim->prox = new;
		l->fim = new;
		l->tamanho++;
	}
}

void lista_imprime(LISTA * l){
	tCelula* percorre = l->inicio;
	printf("%d\n", percorre->valor);
	percorre = percorre->prox;
	while(percorre!=l->inicio){
		printf("%d\n", percorre->valor);
		percorre = percorre->prox;
	}
}

void lista_remover(LISTA *l, int valor) {
    if (l->inicio == NULL) return; // Verifica se a lista está vazia

    tCelula* percorre = l->inicio;

    // Itera sobre a lista circular
    do {
        if (percorre->valor == valor) {
            // Atualiza os ponteiros dos nós adjacentes
            tCelula* proximo = percorre->prox;

            // Se a célula a ser removida é o início, atualiza o início
            if (percorre == l->inicio) {
                l->inicio = proximo;
            } else {
                l->inicio = proximo;
            }

            percorre->ant->prox = percorre->prox;
            percorre->prox->ant = percorre->ant;

            free(percorre); // Libera a célula removida
            l->tamanho--; // Diminui o tamanho da lista
            return; // Encerra a função após a remoção
        }
        percorre = percorre->prox;
    } while (percorre != l->inicio);
}

int atPos(LISTA * l, int index){
	tCelula* percorre = l->inicio;
	for(int i=1; i<index; i++) percorre = percorre->prox;
	return percorre->valor;
}

void lista_libera(LISTA * l){
    if (l->inicio == NULL) {
        free(l);
        return;
    }

    tCelula* percorre = l->inicio;
    do {
        tCelula* proximo = percorre->prox;
        free(percorre);
        percorre = proximo;
    } while (percorre != l->inicio);

    free(l);
}