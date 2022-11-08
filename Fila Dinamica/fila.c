#include "fila.h"
#include <stdlib.h>

struct fila
{
    struct elementos *inicio;
    struct elemento *final;
};

struct elementos
{
    struct dados empresa;
    struct elemento *prox;
};
typedef struct elemento Elem;

Fila* cria_Fila(){
    Fila* fi = malloc(sizeof(Fila));
    if(fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
    }   return fi;
}

void libera_Fila(Fila* fi){
    if(fi != NULL){
        Elem *no;
        while (fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }   free(fi);
    }
}

int tamanho_Fila(Fila* fi){
    if(fi == NULL) return 0;
    int cont = 0;
    Elem* node = fi->inicio;
    while(node != NULL){
        cont++;
        node = node->prox;
    }
    return cont;
}

int Fila_cheia(){
    return 0;
}

int Fila_vazia(Fila* fi){
    if(fi == NULL) return 1;
    if(fi->inicio == NULL) return 1;
    else return 0;
}

int inserir_Fila(Fila* fi, struct dados emp){
    if(fi == NULL || Fila_cheia(fi)) return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->empresa = emp;
    no->prox = NULL;
    if(fi->final == NULL)
        fi->inicio = no;
    else fi->final->prox = no;
    fi->final = no;
    return 1;
}
