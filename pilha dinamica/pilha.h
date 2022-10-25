struct aluno
{
    char nome[30];
    int n1, n2;
    int id;
};
typedef struct elemento* Pilha;

// criar, liberar
Pilha* cria_pilha();
void libera_pilha(Pilha* pi);
// informações
int Tamanho_Pilha(Pilha* pi);
int pilha_cheia(Pilha* pi);
int pilha_vazia(Pilha* pi);
// inseção, remoção e consulta ao topo
int insere_pilha(Pilha* pi, struct aluno aluno);
int remocao_pilha(Pilha* pi);
int consulta_pilha(Pilha* pi, struct aluno *al);