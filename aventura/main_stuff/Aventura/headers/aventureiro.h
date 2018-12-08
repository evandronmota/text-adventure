/* Aventureiro */
typedef struct {
    int nMochila;
    Elemento **mochila;
    Elemento *salaAtual;
} Aventureiro;

extern Aventureiro *heroi;


/* Cria aventureiro */
void criarAventureiro();


/*
    Recebe um ponteiro para um elemento.
    Verifica se esse elemento está na mochila.
    Retorna um inteiro indicando se está na
    mochila ou não.
*/
int estaNaMochila(Elemento *e);


/*
    Recebe um ponteiro para um elemento.
    Coloca esse elemento na mochila do
    aventureiro, retirando-o da sala em que ele
    está.
    Retorna um inteiro indicando se a ação foi
    bem-sucedida.
*/
int adicionarNaMochila(Elemento *e);


/*
    Recebe um ponteiro para um elemento.
    Retira esse elemento da mochila do
    aventureiro e o deixa na sala em que ele
    está.
    Retorna um inteiro indicando se a ação foi
    bem-sucedida.
*/
int tirarDaMochila(Elemento *e);
