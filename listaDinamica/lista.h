struct aluno
{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};
typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista *li);
int insere_lista_inicio(Lista* li, struct aluno al);
int insere_lista_final(Lista* li, struct aluno al);
int insere_lista_ordenado(Lista* li, struct aluno al);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int remove_lista_elemento(Lista* li, int matricula);
int consuta_lista_posicao(Lista* li, int posicao, struct aluno *al);
