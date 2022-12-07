#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

struct grafo
{
    int eh_ponderado;
    int nro_vertices;
    int grau_max;
    int** arestas;
    float** pesos;
    int* grau;
};

Grafo *
cria_Grafo(int nro_vertices, int grau_max, int eh_ponderado)
{
    Grafo *gr = (Grafo*) malloc(sizeof(struct grafo));
    if(gr != NULL){
        int i;
        gr->nro_vertices = nro_vertices;
        gr->grau_max = grau_max;
        gr->eh_ponderado = (eh_ponderado !=0)?1:0;
        gr->grau=(int*)calloc(nro_vertices, sizeof(int));
        gr->arestas=(int**)malloc(nro_vertices*sizeof(int*));
        for(i=0; i<nro_vertices; i++)
            gr->arestas[i]=(int*)malloc(grau_max*sizeof(int));
            if(gr->eh_ponderado) {
                gr->pesos=(float**)malloc(nro_vertices*sizeof(float*));
                for(i=0; i<nro_vertices; i++)
                    gr->pesos[i]=(float*)malloc(grau_max*sizeof(float));
            }
    }
    return gr;
}

void 
libera_Grafo(Grafo* gr)
{
    int i;
    for(i=0; i<gr->nro_vertices; i++)
        free(gr->arestas[i]);
    free(gr->arestas);

    if(gr->eh_ponderado) {
        for(i=0; i<gr->nro_vertices; i++)
            free(gr->pesos[i]);
        free(gr->pesos);
    }
    free(gr->grau);
    free(gr);
}

int 
insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso) 
{
    if(gr==NULL) return 0;
    if(orig < 0 || orig >= gr->nro_vertices) return 0;
    if(dest < 0 || dest >= gr->nro_vertices) return 0;

    gr->arestas[orig][gr->grau[orig]] = dest;
    if(gr->eh_ponderado)
        gr->pesos[orig][gr->grau[orig]] = peso;
    gr->grau[orig]++;

    if(eh_digrafo == 0)
        insereAresta(gr,dest,orig,1,peso);
    return 1;
}