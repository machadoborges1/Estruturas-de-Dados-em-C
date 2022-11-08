#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
    
    Lista *li; //Ponteiro para ponteiro
    li = cria_lista();
    int x = tamamho_lista(li);
    libera_lista(li);

    return 0;
}