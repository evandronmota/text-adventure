#include <stdio.h>
#include "../headers/introducao.h"

/* Cores */
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

void introducao() {
    printf("Bem-vindo ao " BOLDYELLOW "INSERT GAME TITLE." RESET "\n\n \
            Você é um estudante de matemática e computação. É domingo, 21h, você tem que entregar um EP até 24h, você decide jogar video game. \n \
            Grande fã de puzzles, você pega seu jogo favorito Portal 2 e começa a jogar. \n \
            Você pega no sono e de repente acorda numa sala e uma vóz robótica começa a te dar instruções.\n\n");

    printf("______________________________________________________________________________________________________________________________\n\n\n\n");

    printf(BOLDGREEN "INSTRUÇÕES & DICAS\n\n" RESET);
    printf("O lobby conecta todas as salas. Portanto, para trocar de sala é necessário ir para o lobby primeiro (Lugares possíveis: \"lobby\" e \"sala x\").\n\n");
    printf(CYAN "listar" RESET " - para ver os objetos na sala.\n");
    printf(CYAN "<verbo> <objeto> ou <verbo> <objeto> <preposição> <objeto>" RESET " - para utilizar um comando.\n");
    printf(CYAN "tentar <objeto> <senha>" RESET " - para tentar uma senha.\n");
    printf(CYAN "mochila" RESET " - para ver a mochila.\n\n");

    printf("______________________________________________________________________________________________________________________________\n\n\n\n");
}
