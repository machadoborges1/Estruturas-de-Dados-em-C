#include "fila.h"
#include <stdlib.h>

int main(){

    Fila *f;
    f = cria_fila();
    struct aluno al;

    int x = tamanho(f);

    x = consulta(f, &al);    

    libera_fila(f);
    return;
}