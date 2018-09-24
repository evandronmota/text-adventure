#include <stdlib.h>
#include <stdio.h>
#include "elemento.h"
#include "lista_ligada.h"
#include "tabela_de_sim.h"

int main() {
    // simulacao da tabela_de_sim
    TabSim t = cria(13);

    Elemento *el_0 = malloc(sizeof(Elemento));
    el_0->n = malloc(100*sizeof(char));
    el_0->n = "teste0";

    Elemento *el_1 = malloc(sizeof(Elemento));
    el_1->n = malloc(100*sizeof(char));
    el_1->n = "0teste";

    Elemento *el_2 = malloc(sizeof(Elemento));
    el_2->n = malloc(100*sizeof(char));

    Elemento *el_3 = malloc(sizeof(Elemento));
    el_3->n = malloc(100*sizeof(char));

    Elemento *el_4 = malloc(sizeof(Elemento));
    el_4->n = malloc(100*sizeof(char));

    Elemento *el_5 = malloc(sizeof(Elemento));
    el_5->n = malloc(100*sizeof(char));

    insere(t, "teste0", el_0);
    insere(t, "0teste", el_1);

    // Saída correta: teste0
    el_2 = busca(t, "teste0");
    printf("%s\n", el_2->n);

    // Saída correta: 0teste
    el_3 = busca(t, "0teste");
    printf("%s\n", el_3->n);

    // Saída correta: NULL e 0teste
    retira(t, "teste0");
    el_4 = busca(t, "teste0");
    printf("%s\n", (el_4==NULL ? "NULL" : el_4->n));
    el_5 = busca(t, "0teste");
    printf("%s\n", (el_5==NULL ? "NULL" : el_5->n));

    destroi(t);
    // free(el_0->n);
    // free(el_0);
    // free(el_1->n);
    // free(el_1);
    // free(el_2->n);
    // free(el_2);
    // free(el_3->n);
    // free(el_3);
    // free(el_4->n);
    // free(el_4);
    // free(el_5->n);
    // free(el_5);

    return 0;
}
