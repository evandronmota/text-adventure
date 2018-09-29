struct celula{
    char *nick;
    Elemento *val;
    struct celula *next;
};

typedef struct celula *Lista;

Lista criaL(void);
void destroiL(Lista l);
Lista insereL(Lista l, Elemento *val);
Elemento *buscaL(Lista l, char *n);
Elemento *retiraL(Lista l, Elemento *val);
