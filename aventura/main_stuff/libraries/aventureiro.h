/* Aventureiro */
typedef struct {
    int nMochila;
    Elemento *mochila;
    int sala;
} Aventureiro;

/* Cria aventureiro */
Aventureiro *criaAventureiro();

/* Busca elemento no Aventureiro */
boolean buscarnaMochila(Elemento *e1);

/* Adiciona elemento na mochila do Aventureiro */
void adicionarnaMochila(Elemento *e1);
