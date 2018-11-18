/* Aventureiro */
typedef struct {
    int nMochila;
    Elemento *mochila;
    int sala;
} Aventureiro;

/* Cria aventureiro */
Aventureiro *criaAventureiro();
boolean buscarnaMochila(Elemento *e1);
void adicionarnaMochila(Elemento *e1);