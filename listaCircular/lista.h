struct aluno
{
    int matricula;

};
typedef struct elemento *Lista;
Lista* cria_lista();
void libera_lista(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
int insere_inicio_lista(Lista* li, struct aluno al);
int insere_final_lista(Lista* li, struct aluno al);
