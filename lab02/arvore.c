#include "arvore.h"
#include "pilha.h"

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

void rec_postorder(tArvore* t, void (*visit)(tArvore*)){
    if(t == NULL) return;

    rec_postorder(t->esq, visit);
    rec_postorder(t->dir, visit);
    visit(t);
}

void rec_inorder(tArvore* t, void (*visit)(tArvore*)){
    if(t == NULL) return;

    rec_inorder(t->esq, visit);
    visit(t);
    rec_inorder(t->dir, visit);
}

void iterative_preorder(tArvore* t, void (*visit)(tArvore*), tStack* s){
    if(t == NULL) return;

    push(s, t);

    while(isEmpty(s) == 0){
        tArvore* node = pop(s);
        visit(node);
        if(node->dir != NULL) push(s, node->dir);
        if(node->esq != NULL) push(s, node->esq);
    }
}

void iterative_postorder(tArvore* t, void (*visit)(tArvore*), tStack* s){
    if(t == NULL) return;

    tArvore* lastNodeVisited = NULL;
    tArvore* node = t;

    while(isEmpty(s) == 0 || node != NULL){
        if(node != NULL){ //vai acrescentando a pilha ate nao ter como mais ir à erq da copoia da arv
            push(s, node);
            node = node->esq;
        } else{
            tArvore* peekNode = peek(s);
            if(peekNode->dir != NULL && lastNodeVisited != peekNode->dir){ //vai a direita o quanto der
                node = peekNode->dir;
            } else{ //visita e começa a remover da pilha
                visit(peekNode);
                lastNodeVisited = pop(s);
            }
        }
    }
}

void iterative_inorder(tArvore* t, void (*visit)(tArvore*), tStack* s){
    if(t == NULL) return;

    tArvore* node = t;

    while(isEmpty(s) == 0 || node != NULL){
        if(node != NULL){
            push(s, node);
            node = node->esq;
        } else{
            node = pop(s);
            visit(node);
            node = node->dir;
        }
    }
}

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

int getNum(tArvore* a){
    return a->num;
}