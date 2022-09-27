#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no_descritor
{
    Aluno *inicio, *final;
    int qtd;
};

Lista* inicio(){
    Lista *li = (Lista*)malloc(sizeof(Lista));
    if(li == NULL) return 0;
}