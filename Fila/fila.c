#include "fila.h"
#include <stdlib.h>

struct fila
{
    struct aluno dados[MAX];
    int inicio, fim, quantidade;
};

Fila* cria_fila(){
    Fila *f;
    f = malloc(sizeof(struct fila));
    if(f != NULL){
        f->fim = 0;
        f->inicio = 0;
        f->quantidade = 0;
    }
    return f;
}

void libera_fila(Fila* fi){
    free(fi);
}

int tamanho(Fila* fi){
    if(fi == NULL) return -1;
    return fi->quantidade;
}

int cheia(Fila* fi){
    if(fi == NULL) return -1;
    if(fi->quantidade == MAX) return 1;
    else return 0;
}

int vazia(Fila* fi){
    if(fi == NULL) return -1;
    if(fi->quantidade == 0) return 1;
    else return 0;
}

int insere(Fila* fi, struct aluno dado){
    if(fi == NULL || cheia(fi)) return 0;
    fi->dados[fi->fim] = dado;
    fi->fim = (fi->fim+1)%MAX;
    fi->quantidade++;
    return 1;
}

int remove(Fila* fi){
    if(fi == NULL || vazia(fi)) return 0;
    fi->inicio = (fi->inicio+1)%MAX;
    fi->quantidade--;
    return 1;
}

int consulta(Fila* fi, struct aluno* dado){
    if(fi == NULL || vazia(fi)) return 0;
    *dado = fi->dados[fi->inicio];
    return 1;
}