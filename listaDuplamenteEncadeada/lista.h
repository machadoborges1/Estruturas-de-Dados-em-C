struct aluno
{
    int matricula;
    char nome;
    float n1,n2;
};

typedef struct elemento *Lista;

Lista* criar_lista();
void libera_lista(Lista* li);
int lista_vazia(Lista* li);
int tamanho_lista(Lista* li);
int inserir_inicio(Lista* li, struct aluno al);
int inserir_ordenado(Lista* li, struct aluno al);
int inserir_final(Lista* li, struct aluno al);
int remocao_inicio_lista(Lista* li);
int remocao_final_lista(Lista* li);
int remove_elemento_lista(Lista* li, int matricula);

