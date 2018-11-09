// define o tipo boolean
typedef enum {
    False, True
} boolean;

// union para o tipo de atributo
typedef union {
    boolean valor_estado;
    int valor_num;
    char *valor_str;
} atr_val;

// atributos de um objeto
typedef struct {
    char *nome; // nome do atributo
    atr_val valor;
} obj_atr;

/*
    union para atributos específicos de sala
    e objeto.
*/
typedef union {
    obj_atr *atributos;
    struct ele *saidas;
} Info;

// elemento
typedef struct ele {
    char *artigo;
    char *n;
    char *curta;
    char *longa;
    boolean ativo;
    boolean visivel;
    boolean conhecido;
    struct ele* conteudo;
    int nEle; /* numero de elementos na lista de conteudos */
    int nAcoes; /* numero de acoes do elemento */
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
