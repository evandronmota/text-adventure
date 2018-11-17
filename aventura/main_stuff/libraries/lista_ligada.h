/*
    Uma célula da lista ligada guarda um
    ponteiro para um elemento e o nome desse
    elemento.
*/
struct elo {
    char *nome;
    Elemento *val;
    struct elo *next;
};

/* Ponteiro para a lista ligada */
typedef struct elo *Lista;

/* Funções da lista ligada */
Lista criaL(void);
void destroiL(Lista l);
Lista insereL(Lista l, Elemento *val);
Elemento *buscaL(Lista l, char *n);
Elemento *retiraL(Lista l, Elemento *val);
