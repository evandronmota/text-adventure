struct node{
    Elemento *val;
    struct node *next;
};

typedef struct node *Lista;

Lista criaL(void);
void destroiL(Lista l);
Lista insereL(Lista l, Elemento *val);
Elemento *buscaL(Lista l, char *n);
Elemento *retiraL(Lista l, Elemento *val);
