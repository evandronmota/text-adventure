struct elo {
    char *nomes;
    Elemento *val;
    struct elo *next;
};
typedef struct elo* Lista;

Lista criaL(void);
void destroiL(Lista l);
Lista insereL(Lista l, Elemento *val);
Elemento *buscaL(Lista l, char *n);
Elemento *retiraL(Lista l, Elemento *val);
