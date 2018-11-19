#include <stdlib.h>
#include "../headers/elemento.h"
#include "../headers/aventureiro.h"

Aventureiro* heroi;
void criarAventureiro(Elemento* salaInicial) {
    heroi = malloc(sizeof(Aventureiro));

    heroi->nMochila = 0;
    heroi->mochila = NULL;
    heroi->salaAtual = salaInicial;
}

int estaNaMochila(Elemento *e) {
    int i;
    for (i=0; i<heroi->nMochila; i++)
        if (heroi->mochila[i] == e)
            return 1;

    return 0;
}

void adicionarNaMochila(Elemento *e) {
    heroi->nMochila++;
    if (heroi->nMochila == 1) {
        heroi->mochila = malloc(sizeof(Elemento*));
    }
    else {
        heroi->mochila = realloc(heroi->mochila, heroi->nMochila*sizeof(Elemento*));
    }

    int i;
    for (i=0; i<heroi->salaAtual->nEle; i++)
        if (&(heroi->salaAtual->conteudo[i]) == e) {
            heroi->salaAtual->conteudo[i] = heroi->salaAtual->conteudo[heroi->salaAtual->nEle-1];
            heroi->salaAtual->nEle--;
        }
}

void tirarDaMochila(Elemento *e) {
    int i;
    for (i=0; i<heroi->nMochila; i++)
        if (heroi->mochila[i] == e) {
            heroi->salaAtual->nEle++;
            heroi->salaAtual->conteudo = realloc(heroi->salaAtual->conteudo, heroi->salaAtual->nEle*sizeof(Elemento));
            heroi->salaAtual->conteudo[heroi->salaAtual->nEle-1] = *e;

            heroi->mochila[i] = heroi->mochila[heroi->nMochila-1];
            heroi->mochila[heroi->nMochila-1] = NULL;
            heroi->nMochila--;
        }
}
