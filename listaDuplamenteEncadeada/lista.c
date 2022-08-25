#include "lista.h"
#include <stdlib.h>

struct elemento
{
    struct aluno dados;
    struct elemento *ant;
    struct elemento *prox;
};
typedef struct elemento Elem;

Lista *criar_lista(){
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL) *li = NULL;
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){ // conteudo da li
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int tamanho_lista(Lista* li){
    if(li == NULL) return 0;
    int cont = 0;
    Elem* no = *li;
    while(no != NULL)
    {
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_vazia(Lista* li){
    if(li == NULL) return 1; //não tem lista
    if(*li == NULL) return 1; //não tem conteudo
    return 0;
}

int inserir_inicio(Lista* li, struct aluno al){
    if(li == NULL) return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;
    no->ant = NULL;
    no->prox = (*li);
    //lista não vazia: aponta para o anterior
    if(*li != NULL) (*li)->ant = no;
    *li = no;
    return 1;
}

int inserir_final(Lista* li, struct aluno al){
    if(li == NULL) return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL){ //lista vazia: insere inicio
        no->ant = NULL;
        *li = no; // priemiro elemento passa ser o no
    } else {
        Elem *aux = *li; // auxilar recebe o inicio da lista
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = no;
        no->ant = aux;
    }
    return 1;
}

int inserir_ordenado(Lista* li, struct aluno al){
    if(li == NULL) return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;
    if(lista_vazia(li)){
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return 1;
    } else { 
        Elem *anterior, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            anterior = atual;
            atual = atual->prox;
        }
        if(atual == *li){
            no->ant = NULL;
            (*li)->ant = no;
            *li = no;
        } else {
            no->prox = anterior->prox;
            no->ant = anterior;
            anterior->prox = no;
            if(atual != NULL) atual->ant = no;
        }
    }
}

int remocao_inicio_lista(Lista* li){
    if(li == NULL) return 0;
    if((*li) == NULL) return 0;
    Elem *no = *li;
    *li = no->prox;
    if(no->prox != NULL){
        no->prox->ant = NULL;
    }
    free(no);
    return 1;
}

int remocao_final_lista(Lista* li){
    if(li == NULL) return 0;
    if((*li) == NULL) return 0;
    Elem *no = *li;
    while(no->prox != NULL) no = no->prox;
    if(no->ant == NULL) *li = no->prox; // remove primeiro e unico
    else no->ant->prox = NULL;
    free(no);
    return 1;
}

int remove_elemento_lista(Lista* li, int matricula){
    if(li == NULL) return 0;
    Elem *no = *li;
    while(no != NULL && no->dados.matricula != matricula)
        no = no->prox;
    if(no == NULL) return 0; // não encontrado
    if(no->ant == NULL) *li = no->prox;
    else no->ant->prox = no->prox;
    //não é o ultimo?
    if(no->prox != NULL)
        no->prox->ant = no->ant;
    free(no);
    return 1;
}
