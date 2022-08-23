
#define MAX 100

struct aluno
{
    int matricula;
    char nome;
    float n1,n2,n3;
};

typedef struct lista Lista;

Lista* cria_lista();
void libera_lista(Lista *li);
int tamanho_lista(Lista *li);
int lista_cheia(Lista *li);
int lista_vazia(Lista *li);
int insere_lista_final(Lista* li, struct aluno al);
int insere_lista_inicio(Lista* li, struct aluno al);
int insere_lista_ordenada(Lista* li, struct aluno al);
int remove_lista_inicio(Lista* li, struct aluno al);
int remove_lista_final(Lista* li, struct aluno al);
int remove_lista_elemento(Lista* li, int matricula);
int consuta_lista_pos(Lista* li, int pos, struct aluno *al);
int consuta_lista_matricula(Lista* li, int mat, struct aluno *al);