/* Define o tipo boolean */
typedef enum {
    False, True
} boolean;

/* Union para o tipo de atributo */
typedef union {
    boolean valor_estado;
    int valor_num;
    char *valor_str;
} atr_val;

/* Atributos de um objeto */
typedef struct {
    char *nome; /* Nome do atributo */
    atr_val valor;
} obj_atr;

/*
    Union para atributos específicos de sala
    e objeto.
*/
typedef union {
    obj_atr *atributos;
    struct ele **saidas;
} Info;

/* Elemento */
typedef struct ele {
    char *artigo;
    char *n;
    char *curta;
    char *longa;
    boolean ativo;
    boolean visivel;
    boolean conhecido;
    struct ele* conteudo;
    int nEle; /* número de elementos na lista de conteudos */
    int nAcoes; /* número de acoes do elemento */
    void **acoes;
    int *transitividade;
    /*
        0 = intransitivo
        1 = transitivo
        2 = bitransitivo
    */
    void *animacao;
    Info detalhe;
} Elemento;
