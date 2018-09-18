#include <stdlib.h>
#include <stdio.h>
#include "elemento.h"
#include "lista_ligada.h"
#include "tabela_de_sim.h"

int main() {
    // simulacao da tabela_de_sim
    TabSim t = cria(13);
    Elemento* val = malloc(sizeof(Elemento));
    val->n = malloc(100*sizeof(char));
    val->n = "teste";
    insere(t, "teste", val);
    Elemento* vel = busca(t, "teste");
    printf("%s\n", vel->n);
    destroi(t);

    // simulacao da lista_ligada
    return 0;
}
