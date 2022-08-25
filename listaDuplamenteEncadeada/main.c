#include <stdio.h>
#include "lista.h"

int main(){
    
    Lista *li;
    li =criar_lista();
    libera_lista(li);

    return 0;
}