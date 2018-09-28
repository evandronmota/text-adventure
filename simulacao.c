#include <stdlib.h>
#include <stdio.h>
#include "elemento.h"
#include "lista_ligada.h"
#include "tabela_de_sim.h"

Elemento *criaElemento(char *n) {
    int i;
    Elemento *el = malloc(sizeof(Elemento));
    el->n = malloc(100*sizeof(char));
    el->n = n;
    el->posLivre = 0;
    el->nicks = malloc(10*sizeof(char*));
    for (i=0; i<10; i++)
        el->nicks[i] = malloc(100*sizeof(char));
    return el;
}

int main() {
    TabSim t = cria(13);

    Elemento *el0 = criaElemento("dragao com asas de fogo");
    Elemento *el1 = criaElemento("dragao com colisao");
    Elemento *el2 = criaElemento("elemento teste");

    // TESTE: INSERIR ----------------------------------------------------------------------------------
    insere(t, "dragao", el0);
    insere(t, "feioso", el0);
    insere(t, "gaodra", el1);

    // TESTE: BUSCA ------------------------------------------------------------------------------------
    // Saída correta: dragao com asas de fogo
    el2 = busca(t, "dragao");
    printf("%s\n", el2->n);

    // Saída correta: dragao com asas de fogo
    el2 = busca(t, "feioso");
    printf("%s\n", el2->n);

    // Saída correta: dragao com colisao
    el2 = busca(t, "gaodra");
    printf("%s\n", el2->n);

    // TESTE: RETIRA -----------------------------------------------------------------------------------
    // Saída correta: NÃO ENCONTRADO!, NÃO ENCONTRADO! e dragao com colisao
    retira(t, "dragao");
    el2 = busca(t, "dragao");
    printf("%s\n", (el2==NULL ? "NÃO ENCONTRADO!" : el2->n));
    el2 = busca(t, "feioso");
    printf("%s\n", (el2==NULL ? "NÃO ENCONTRADO!" : el2->n));
    el2 = busca(t, "gaodra");
    printf("%s\n", (el2==NULL ? "NÃO ENCONTRADO!" : el2->n));

    destroi(t);
    
    return 0;
}
