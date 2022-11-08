#include "lista.h"
#include <stdlib.h>

struct elemento
{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

Lista* cria_lista(){
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL) *li = NULL;
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL && (*li) != NULL){
        Elem *aux, *no = *li;
        while((*li) != no->prox){
            aux = no;
            no = no->prox;
            free(aux);
        }
        free(no);
        free(li);
    }
}

int tamanho_lista(Lista* li){
    if(li == NULL || (*li) == NULL) return 0;
    int cont = 0;
    Elem* no = *li;
    do{
        cont++;
        no = no->prox;
    } while(no != (*li));
    return cont;
}

int lista_vazia(Lista* li){
    if(li == NULL && (*li) == NULL) return 1;
    else return 0;
}

int insere_inicio_lista(Lista* li, struct aluno al){
    if(li == NULL) return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;
    if((*li) == NULL){
        *li = no;
        no->prox = no;
        return 1;
    } else {
        Elem *aux = *li;
        while(aux->prox != (*li))
            aux = aux->prox;
        aux->prox = no;
        no->prox = *li;
        *li = no;
    }
    return 1;
}

int insere_final_lista(Lista* li, struct aluno al){
    if(li == NULL) return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;
    if((*li) == NULL){
        *li = no;
        no->prox = no;
        return 1;
    } else {
        Elem *aux = *li;
        while(aux->prox != (*li))
            aux = aux->prox;
        aux->prox = no;
        no->prox = *li;
    }
    return 1;
}

int insere_meio_lista(Lista* li, struct aluno al){
    if(li == NULL) return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;
    if((*li) == NULL){
        *li = no;
        no->prox = no;
        return 1;
    } else {
        if((*li)->dados.matricula > al.matricula){
            Elem *atual = *li;
            while(atual->prox != (*li)){
                atual = atual->prox;
                no->prox = *li;
                atual->prox = no;
                *li = no;
                return 1;
            }
        }
        Elem *ant = *li, *atual = (*li)->prox;
        while (atual != (*li) && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        ant->prox = no;
        no->prox = atual;
    }
}

