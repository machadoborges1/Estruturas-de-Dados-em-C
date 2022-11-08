#include <stdio.h>
#include "pilha.h"
#include <stdlib.h>

int main(){

    struct aluno dados;
    Pilha *pi;
    pi = cria_pilha();
    libera_pilha(pi);
    int x = Tamanho_Pilha(pi);
    if(pilha_cheia(pi));
    if(pilha_vazia(pi));
    x = insere_pilha(pi, dados);
    x = consulta_pilha(pi, &dados);
    
    return 0;
}

