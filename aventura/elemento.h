typedef enum {
    False, True
} boolean;

typedef union {
    boolean valor_estado;
    int valor_num;
    char *valor_str;
} atr_val;

typedef struct {
    char *nome;
    atr_val valor;
} obj_atr;

typedef union {
    obj_atr *atributos;
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
    int nEle; /* numero de elementos na lista de conteudos */
    Info detalhe;
    void **acoes;
    void *animacao;
} Elemento;
