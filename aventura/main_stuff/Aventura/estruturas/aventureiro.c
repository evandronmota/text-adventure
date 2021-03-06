#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/elemento.h"
#include "../headers/aventureiro.h"
#include "../headers/lista_ligada.h"
#include "../headers/tabela_de_sim.h"

Aventureiro *heroi;

void criarAventureiro(Elemento *salaInicial) {
    heroi = malloc(sizeof(Aventureiro));

    heroi->nMochila = 0;
    heroi->mochila = NULL;
    heroi->salaAtual = salaInicial;
}

int estaNaMochila(Elemento *e) {
    int i;
    for (i=0; i<heroi->nMochila; i++)
        if (!strcmp(heroi->mochila[i]->n, e->n))
            return 1;

    return 0;
}

int adicionarNaMochila(Elemento *e) {
    Elemento *copia = malloc(sizeof(Elemento));


    heroi->nMochila++;
    if (heroi->nMochila == 1)
        heroi->mochila = malloc(sizeof(Elemento*));
    else
        heroi->mochila = realloc(heroi->mochila, heroi->nMochila * sizeof(Elemento*));

    /* Pega o último elemento da sala atual e coloca no lugar do elemento adicionado na mochila */
    int i;
    for (i=0; i<heroi->salaAtual->nEle; i++) {
        if (!strcmp(heroi->salaAtual->conteudo[i].n, e->n)) {   
            *copia = heroi->salaAtual->conteudo[i];
            retira(tabela, e->n);
            insere(tabela, copia->n, copia);
            heroi->mochila[heroi->nMochila-1] = copia;
            heroi->salaAtual->conteudo[i] = heroi->salaAtual->conteudo[heroi->salaAtual->nEle - 1];
            heroi->salaAtual->nEle--;
            return 1;
        }
    }

    return 0;
}

int tirarDaMochila(Elemento *e) {
    Elemento *copia = malloc(sizeof(Elemento));
    int i;

    for (i=0; i<heroi->nMochila; i++)
        if (!strcmp(heroi->mochila[i]->n, e->n)) {
            /* Coloca o último elemento da mochila no lugar do elemento removido */
            heroi->mochila[i] = heroi->mochila[heroi->nMochila - 1];
            heroi->mochila[heroi->nMochila-1] = NULL;
            heroi->nMochila--;

            /* Adiciona elemento na sala */
            *copia = *e;
            retira(tabela, e->n);
            insere(tabela, copia->n, copia);
            heroi->salaAtual->nEle++;
            heroi->salaAtual->conteudo = realloc(heroi->salaAtual->conteudo, heroi->salaAtual->nEle * sizeof(Elemento));
            heroi->salaAtual->conteudo[heroi->salaAtual->nEle - 1] = *e;

            return 1;
        }

    return 0;
}
