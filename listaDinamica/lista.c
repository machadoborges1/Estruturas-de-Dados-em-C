#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct elemento
{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL) *li = NULL;
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
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
    Elem* no = *li; //sempre andar com auxiliar
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_vazia(Lista *li){
    if(li == NULL) return 1;
    if(*li == NULL) return 1;
    return 0;
}

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL) return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;
    no->prox = (*li);
    *li = no;
    return 1;
}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL) return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL){
        *li = no;
    } else {
        Elem *aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

int insere_lista_ordenado(Lista* li, struct aluno al){
    if(li == NULL) return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;
    if(lista_vazia(li)){
        no->prox = (*li);
        *li = no;
        return 1;
    } else { // procurar onde inserir
        Elem *atual = *li, *anterior;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            anterior = atual;
            atual = atual->prox;
        } 
        if(atual == *li){
            no->prox = (*li);
            *li = no;
        } else {
            no->prox = anterior->prox;
            anterior->prox = no;
        }
        return 1;
    }
}

int remove_lista_inicio(Lista* li){
    if(li == NULL) return 0;
    if((*li) == NULL) return 0; //lista Vazia
    Elem *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL) return 0;
    if((*li) == NULL) return 0;
    Elem *ant, *no = *li;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }
    if(no == (*li)) *li = no->prox; //remove primeiro?
    else ant->prox = no->prox;
    free(no);
    return 1;
}

int remove_lista_elemento(Lista* li, int matricula){
    if(li == NULL) return 0;
    Elem *ant, *no = *li;
    while(no != NULL && no->dados.matricula != matricula){
        ant = no;
        no = no->prox;
    }
    if(no == NULL) return 0; //não encontrado
    if(no == *li) *li = no->prox;
    else ant->prox = no->prox;
    free(no);
    return 1;
}

int consuta_lista_posicao(Lista* li, int posicao, struct aluno *al){
    if(li == NULL || posicao <= 0) return 0;
    Elem *no = *li;
    int i = 1;
    while(no != NULL && i < posicao){
        no = no->prox;
        i++;
    }
    if(no == NULL) return 0;
    else{
        *al = no->dados;
        return 1;
    }
}

int consuta_lista_conteudo(Lista* li, int matricula, struct aluno *al){
    if(li == NULL) return 0;
    Elem *no = *li;
    while(no != NULL && no->dados.matricula != matricula){
        no = no->prox;
    }
    if(no == NULL) return 0;
    else{
        *al = no->dados;
        return 1;
    }
}