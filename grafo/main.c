#include "Grafo.c"

int main(){
    Grafo *gr;
    gr = cria_Grafo(10, 7, 0);

    insereAresta(gr, 0, 1, 0, 0);
    insereAresta(gr, 1, 3, 0, 0);

    libera_Grafo(gr);
}