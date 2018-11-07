typedef enum {
    False, True
} boolean;

typedef union {
    /* TabSim tabela; */
    struct ele *saidas;
} Info;

typedef struct ele {
    char *artigo;
    char *n;
    char *curta;
    char *longa;
    boolean ativo;
    boolean visivel;
    boolean conhecido;
    struct ele* conteudo;
    int nele; /* numero de elementos na lista de conteudos */
    Info detalhe;
    void **acoes;
    void *animacao;
} Elemento;
