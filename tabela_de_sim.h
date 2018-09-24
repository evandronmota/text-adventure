typedef struct {
    int tam;
    Lista *elementos;
} tabSim;

typedef tabSim *TabSim;

TabSim cria(int tam);
void destroi(TabSim t);
int insere(TabSim t, char *n, Elemento *val);
Elemento* busca(TabSim t, char *n);
int retira(TabSim t, char *n);
