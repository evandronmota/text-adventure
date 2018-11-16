/*
    A tabela de símbolos guarda seu tamanho e 
    um vetor de listas ligadas.
*/
typedef struct {
    int tam;
    Lista *elementos;
} tabSim;

/* Ponteiro para tabela de símbolos */
typedef tabSim *TabSim;

/* Funções da tabela de símbolos */
TabSim cria(int tam);
void destroi(TabSim t);
int insere(TabSim t, char *n, Elemento *val);
Elemento *busca(TabSim t, char *n);
int retira(TabSim t, char *n);
