#define MAX 100
struct aluno {
    int matricula;
    char nome[30];
    float n1, n2;
};

typedef struct pilha Pilha;
Pilha* cria_pilha();
void libera_pilha(Pilha* pi);
//informações
int tamanho_pilha(Pilha* pi);
int pilha_cheia(Pilha* pi); 
int pilha_vazia(Pilha* pi);
// inserção e remoção
int insere_pilha(Pilha* pi, struct aluno al);
int remove_pilha(Pilha* pi);
//int x = consuta_topo_pilha(pi, &aluno)
int consuta_topo_pilha(Pilha* pi, struct aluno *al);