#include "arvore.h"

struct arvore{
    tArvore* esq;
    tArvore* dir;
    int num;
};

void rec_preorder(tArvore* t, void (*visit)(tArvore*)){

    if(t == NULL) return;

    visit(t);
    
    rec_preorder(t->esq, visit);
    rec_preorder(t->dir, visit);
}

void rec_postorder(tArvore* t, void (*visit)(tArvore*));

void rec_inorder(tArvore* t, void (*visit)(tArvore*));

tArvore* criaVazia(){
    return NULL;
}

tArvore* cria(int chave){
    tArvore* a = malloc(sizeof(tArvore));

    a->esq = NULL;
    a->dir = NULL;
    a->num = chave;

    return a;
}

tArvore* insereChave(tArvore* a, int chave){

    if(a == NULL){
        a = cria(chave);
    } else if(chave > a->num){
        a->dir = insereChave(a->dir, chave);
    } else if(chave < a->num){
        a->esq = insereChave(a->esq, chave);
    } else{
        printf("Chave igual, cavalo\n");
        //return a;
    }

    return a;
}

int altura(tArvore* a){
    if(a == NULL){
        return -1;
    } else{
        int esq = altura(a->esq);
        int dir = altura(a->dir);

        if(esq > dir){
            return esq + 1;
        } else{
            return dir + 1;
        }
    }
}

void destroi(tArvore* a){
    if(a){
        destroi(a->esq);
        destroi(a->dir);
        free(a);
    }
}

void imprime(tArvore* a){
    if(a){
        imprime(a->esq);
        printf("%d\n", a->num);
        imprime(a->dir);
    }
}