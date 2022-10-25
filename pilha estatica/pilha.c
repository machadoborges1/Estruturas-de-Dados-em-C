#include "pilha.h"
#include <stdlib.h>

struct pilha{
    int qtd;
    struct aluno dados[MAX];
};

Pilha* cria_pilha(){
    Pilha * pi;
    pi = (Pilha*)malloc(sizeof(struct pilha));
    if(pi != NULL){
        pi->qtd = 0;
    }
    return pi;
}

void libera_pilha(Pilha* pi){
    free(pi);
}

int tamanho_pilha(Pilha* pi){
    if(pi != NULL){
        return pi->qtd;
    }
    return -1;
}

int pilha_cheia(Pilha* pi){
    if(pi == NULL) return -1;
    return (pi->qtd == MAX); // 1 se verdadeiro; 0 se falso
}

int pilha_vazia(Pilha* pi){
    if(pi == NULL) return -1;
    return (pi->qtd == 0); // 1 if True; 0 if False
}

int insere_pilha(Pilha* pi, struct aluno dado){
    if(pilha_cheia(pi) || pi == NULL) return 0;
    pi->dados[pi->qtd] = dado;
    pi->qtd++;
    return 1;
}

int remove_pilha(Pilha *pi){
    if(pi == NULL || pilha_vazia(pi)) return 0;
    pi->qtd--;
    return 1;
}

int consulta_topo_pilha(Pilha* pi, struct aluno* dado){
    if(pi == NULL || pilha_vazia(pi)) return 0;
    *dado = pi->dados[pi->qtd-1];
    return 1;
}