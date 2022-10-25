#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct elemento
{
    Aluno dados;
    struct elemento *prox;
};
typedef struct elemento elen;

struct descritor
{
    struct elemento *inicio;
    struct elemento *final;
    int qtd;;
}


Lista* inicio(){
    Lista *li = (Lista*)malloc(sizeof(Lista));
    if(li == NULL) return 0;
}