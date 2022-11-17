#include <stdlib.h>
#include "lista.h"
#include <stdio.h>

int main(){

    Lista *li;
    li = cria_lista;
    struct aluno dados;

    dados.matricula = 123;

    int x = insere_inicio_lista(li, dados);

    printf(dados.matricula);

    libera_lista(li);
    return 0;
}