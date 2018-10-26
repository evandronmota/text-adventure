#include "tabela_de_sim.h"

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
    Elemento* conteudo;
    info detalhe;
    void **acoes;
    void* animacao;
} Elemento;

typedef union {
    TabSim tabela;
    Elemento *saidas;
} Info;
