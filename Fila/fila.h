#define MAX 10

struct aluno {
    char nome [30];
    int matricula;
};

typedef struct fila Fila;

Fila* cria_fila();
void libera_fila(Fila* fi);
int tamanho(Fila* fi);
int tamanho(Fila* fi);
int cheia(Fila* fi);
int vazia(Fila* fi);
int insere(Fila* fi, struct aluno dado);
int remove(Fila* fi);
int consulta(Fila* fi, struct aluno* dado);