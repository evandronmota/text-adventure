#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../headers/introducao.h"
#include "../headers/elemento.h"
#include "../headers/aventureiro.h"
#include "../headers/lista_ligada.h"
#include "../headers/salas.h"
#include "../headers/tabela_de_sim.h"
#include "../headers/init_salas.h"

int main() {
    introducao();

    init_tabela();
    Elemento *salas = inicializarSalas();
    criarAventureiro(salas[0]);

    // printf(">>>%s\n", busca(tabela, "Robo")->n);

    examinar(heroi->salaAtual, NULL);
    printf("\n");

    while(yyparse());

    return 0;
}
