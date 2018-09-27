#include <stdlib.h>
#include <stdio.h>
#include "elemento.h"
#include "lista_ligada.h"
#include "tabela_de_sim.h"

int main() {
    // simulacao da tabeladesim
    //primeiro nick da lista de nicks é o nome
    int i;

    TabSim t = cria(13);

    Elemento *el0 = malloc(sizeof(Elemento));
    el0->n = malloc(100*sizeof(char));
    el0->n = "teste0";
    el0->posLivre = 0;
    el0->nicks = malloc(5*sizeof(char*));
    for (i=0; i<5; i++)
        el0->nicks[i] = malloc(100*sizeof(char));
    el0->nicks[el0->posLivre++] = el0->n;

    Elemento *el1 = malloc(sizeof(Elemento));
    el1->n = malloc(100*sizeof(char));
    el1->n = "0teste";
    el1->posLivre = 0;
    el1->nicks = malloc(5*sizeof(char*));
    for (i=0; i<5; i++)
        el1->nicks[i] = malloc(100*sizeof(char));
    el1->nicks[el1->posLivre++] = el1->n;

    Elemento *el2 = malloc(sizeof(Elemento));
    el2->n = malloc(100*sizeof(char));

    Elemento *el3 = malloc(sizeof(Elemento));
    el3->n = malloc(100*sizeof(char));

    Elemento *el4 = malloc(sizeof(Elemento));
    el4->n = malloc(100*sizeof(char));

    Elemento *el5 = malloc(sizeof(Elemento));
    el5->n = malloc(100*sizeof(char));

    Elemento *el6;

    insere(t, "teste0", el0);
    insere(t, "teste1", el0);
    // printf("insere: %d\n", p);
    insere(t, "0teste", el1);

    // Saída correta: teste0
    el2 = busca(t, "teste0");
    if (el2 != NULL)
        printf("%s\n", el2->n);

    // Saída correta: 0teste
    el3 = busca(t, "0teste");
    printf("%s\n", el3->n);

    // Saída correta: 20, 20 e 20
    el6 = busca(t, "teste1");
    if (el6==NULL)
        printf("NULLLLL\n");
    else
        printf("%s\n", el6->n);

    // Saída correta: NULL e 0teste
    retira(t, "teste0");
    el4 = busca(t, "teste0");
    printf("%s\n", (el4==NULL ? "NULL" : el4->n));
    el5 = busca(t, "0teste");
    printf("%s\n", (el5==NULL ? "NULL" : el5->n));

    destroi(t);
    
    return 0;
}
