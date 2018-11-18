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


/* Cria uma lista ligada. Retorna a lista criada. */
Lista criaL(void);


/*
    Recebe uma lista ligada. Destroi a lista
    recebida.
*/
void destroiL(Lista l);


/*
    Recebe uma lista ligada e um ponteiro para
    um elemento. Insere nessa lista o elemento
    recebido.
*/
Lista insereL(Lista l, Elemento *val);


/*
    Recebe uma lista ligada e uma string. Realiza
    uma busca nessa lista a partir da string
    recebida. Retorna um ponteiro para o elemento
    associado a tal string, em caso de sucesso, ou
    NULL, caso contrário.
*/
Elemento *buscaL(Lista l, char *n);


/*
    Recebe uma lista ligada e um ponteiro para um
    elemento. Remove esse elemento da lista recebida.
    Retorna um ponteiro para tal elemento, em caso
    de sucesso, ou NULL, caso contrário.
*/
Elemento *retiraL(Lista l, Elemento *val);
