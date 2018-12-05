#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../headers/elemento.h"
#include "../headers/aventureiro.h"
#include "../headers/lista_ligada.h"
#include "../headers/salas.h"
#include "../headers/tabela_de_sim.h"
#include "../headers/init_salas.h"

#define RESET   "\033[0m"
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */

TabSim tabela;

int main() {

    printf("Bem-vindo ao " BOLDYELLOW "INSERT GAME TITLE." RESET "\n\n \
            Você é um estudante de matemática e computação. É domingo, 21h, você tem que entregar um EP até 24h, você decide jogar video game. \n \
            Grande fã de puzzles, você pega seu jogo favorito Portal 2 e começa a jogar. \n \
            Você pega no sono e de repente acorda numa sala e uma vóz robótica começa a te dar instruções.\n\n\n");

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
        if (!validou && !strcmp(heroi->salaAtual->n, "Sala 4"))
            if (validar((Elemento*) busca(tabela,"Balança"), NULL))
                validou = 1;
        if (!strcmp(heroi->salaAtual->n, "Lobby"))
            ((func)heroi->salaAtual->conteudo[5].animacao)(&heroi->salaAtual->conteudo[5], NULL);
    }
    return 0;
}
