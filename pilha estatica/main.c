#include "pilha.h"
#include <stdlib.h>

int main(){

    Pilha *pi;
    pi = cria_pilha();
    struct aluno dados_aluno;

    int x = tamanho_pilha(pi);
    x = pilha_cheia(pi);
    if(pilha_cheia(pi))

    x = insere_pilha(pi, dados_aluno);
    x = remove_pilha(pi);

    int consulta_topo_pilha(pi, &dados_aluno);

    libera_pilha(pi);
    return 0;
}