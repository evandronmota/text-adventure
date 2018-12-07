#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../headers/elemento.h"
#include "../headers/aventureiro.h"
#include "../headers/lista_ligada.h"
#include "../headers/salas.h"
#include "../headers/tabela_de_sim.h"
#include "../headers/init_salas.h"
#include "../headers/introducao.h"

TabSim tabela;

int main() {

    /* Introdução do jogo */
    introducao();

    /* Cria salas */
    Elemento *salas = inicializarSalas();

    /* Insere elementos na tabela de símbolos */
    init_tabela(salas);

    /* Cria aventureiro na sala0 */
    criarAventureiro(&salas[0]);

    /* Descrição inicial da sala0 */
    examinar(heroi->salaAtual, NULL);
    printf("\n");

    int validou = 0;

    while(yyparse()) {
        if (!validou && !strcmp(heroi->salaAtual->n, "Sala 4")) {
            if (validar((Elemento*) busca(tabela,"Balança"), NULL))
                validou = 1;
        }
        if (!strcmp(heroi->salaAtual->n, "Lobby"))
            ((func)heroi->salaAtual->conteudo[5].animacao)(&heroi->salaAtual->conteudo[5], NULL);
    }
    return 0;
}
