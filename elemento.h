typedef enum {
    False, True
} boolean;

typedef struct {
    char *n;
    char *curta;
    char *longa;
    boolean ativo;
    boolean visivel;
    boolean conhecido;
    info detalhe;
    void **acoes;
    void* animacao;
} Elemento;

typedef union {

} info;
