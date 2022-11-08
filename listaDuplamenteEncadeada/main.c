#include <stdio.h>
#include "lista.h"

int main(){

    Lista *li;
    int posicao = 1234;
    struct aluno dados_aluno;
    li =criar_lista();
    libera_lista(li);
    int x = busca_por_posicao(li, posicao, &dados_aluno);

    return 0;
}