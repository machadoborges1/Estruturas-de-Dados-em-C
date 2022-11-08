struct dados
{
    char nome[30];
    int matricula;
};

typedef struct fila Fila;

Fila* cria_Fila();
void libera_Fila(Fila* fi);
int tamanho_Fila(Fila* fi);
int Fila_cheia();
int Fila_vazia(Fila* fi);
