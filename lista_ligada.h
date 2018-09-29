struct no{
    Elemento *val;
    struct no *prox;
};

typedef struct no *Lista;

Lista criaL(void);
void destroiL(Lista l);
Lista insereL(Lista l, Elemento *val);
Elemento *buscaL(Lista l, char *n);
Elemento *retiraL(Lista l, Elemento *val);
