#include "pilha.h"
#include <stdlib.h>

struct elemento
{
    struct aluno dados;
    struct elemento *proximo;
};
typedef struct elemento Elem;

Pilha* cria_pilha(){
    Pilha* pi = ((Pilha*)malloc(sizeof(Pilha)));
    if(pi != NULL){
        *pi = NULL;
        return pi;
    }
}

void libera_pilha(Pilha* pi){
    if(pi != NULL){
        Elem* no;
        while((*pi) != NULL){
            no = *pi;
            *pi = (*pi)->proximo;
            free(no);
        }
        free(pi);
    }
}

int Tamanho_Pilha(Pilha* pi){
    if(pi == NULL) return 0;
    int cont = 0;
    Elem* no = *pi;
    while(no != NULL){
        cont++;
        no = no->proximo;
    }
    return cont;
}

int pilha_cheia(Pilha* pi){
    return 0;
}

int pilha_vazia(Pilha* pi){
    if(pi == NULL || *pi == NULL) return 1;
    return 0;
}

int insere_pilha(Pilha* pi, struct aluno al){
    if(pi == NULL) return 0;
    Elem *no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;
    no->proximo = (*pi);
    *pi = no;
    return 1;
}

int remocao_pilha(Pilha* pi){
    if(pi == NULL) return 0;
    if((*pi) == NULL) return 0;
    Elem *no = *pi;
    *pi = no->proximo;
    free(no);
    return 1;
}

int consulta_pilha(Pilha* pi, struct aluno *al){
    if(pilha_vazia(pi) || pi == NULL) return 0;
    *al = (*pi)->dados;
    return 1;
}