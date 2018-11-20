#include <stdio.h>
#include <stdlib.h>
#include "../headers/elemento.h"
#include "../headers/salas.h"
#include "../headers/init_salas.h"

Elemento *inicializarSalas() {
    /* lobby = sala0 (sala principal) */

    int i;

    Elemento lobby = criarSala0();
    Elemento sala1 = criarSala1();
    Elemento sala2 = criarSala2();
    Elemento sala3 = criarSala3();
    Elemento sala4 = criarSala4();
    Elemento sala5 = criarSala5();

    lobby.detalhe.saidas = malloc(9 * sizeof(saidas*));
    sala1.detalhe.saidas = malloc(5 * sizeof(saidas*));
    sala2.detalhe.saidas = malloc(5 * sizeof(saidas*));
    sala3.detalhe.saidas = malloc(5 * sizeof(saidas*));
    sala4.detalhe.saidas = malloc(5 * sizeof(saidas*));
    sala5.detalhe.saidas = malloc(5 * sizeof(saidas*));

    /* Direções cardeais (não possuem em nosso jogo) */
    for (i = 0; i < 4; i++) {
        lobby.detalhe.saidas[i] = malloc(sizeof(saidas));
        lobby.detalhe.saidas[i]->saida = NULL;
        lobby.detalhe.saidas[i]->esta_fechada = True;

        sala1.detalhe.saidas[i] = malloc(sizeof(saidas));
        sala1.detalhe.saidas[i]->saida = NULL;
        sala1.detalhe.saidas[i]->esta_fechada = True;

        sala2.detalhe.saidas[i] = malloc(sizeof(saidas));
        sala2.detalhe.saidas[i]->saida = NULL;
        sala2.detalhe.saidas[i]->esta_fechada = True;

        sala3.detalhe.saidas[i] = malloc(sizeof(saidas));
        sala3.detalhe.saidas[i]->saida = NULL;
        sala3.detalhe.saidas[i]->esta_fechada = True;

        sala4.detalhe.saidas[i] = malloc(sizeof(saidas));
        sala4.detalhe.saidas[i]->saida = NULL;
        sala4.detalhe.saidas[i]->esta_fechada = True;

        sala5.detalhe.saidas[i] = malloc(sizeof(saidas));
        sala5.detalhe.saidas[i]->saida = NULL;
        sala5.detalhe.saidas[i]->esta_fechada = True;
    }

    /* Das salas para o lobby */
    sala1.detalhe.saidas[4] = malloc(sizeof(saidas));
    sala1.detalhe.saidas[4]->saida = &lobby;
    sala1.detalhe.saidas[4]->esta_fechada = False;

    sala2.detalhe.saidas[4] = malloc(sizeof(saidas));
    sala2.detalhe.saidas[4]->saida = &lobby;
    sala2.detalhe.saidas[4]->esta_fechada = False;

    sala3.detalhe.saidas[4] = malloc(sizeof(saidas));
    sala3.detalhe.saidas[4]->saida = &lobby;
    sala3.detalhe.saidas[4]->esta_fechada = False;

    sala4.detalhe.saidas[4] = malloc(sizeof(saidas));
    sala4.detalhe.saidas[4]->saida = &lobby;
    sala4.detalhe.saidas[4]->esta_fechada = False;

    sala5.detalhe.saidas[4] = malloc(sizeof(saidas));
    sala5.detalhe.saidas[4]->saida = &lobby;
    sala5.detalhe.saidas[4]->esta_fechada = False;


    /* Do lobby para as salas */
    lobby.detalhe.saidas[4] = malloc(sizeof(saidas));
    lobby.detalhe.saidas[4]->saida = &sala1;
    lobby.detalhe.saidas[4]->esta_fechada = False;

    lobby.detalhe.saidas[5] = malloc(sizeof(saidas));
    lobby.detalhe.saidas[5]->saida = &sala2;
    lobby.detalhe.saidas[5]->esta_fechada = False;

    lobby.detalhe.saidas[6] = malloc(sizeof(saidas));
    lobby.detalhe.saidas[6]->saida = &sala3;
    lobby.detalhe.saidas[6]->esta_fechada = False;

    lobby.detalhe.saidas[7] = malloc(sizeof(saidas));
    lobby.detalhe.saidas[7]->saida = &sala4;
    lobby.detalhe.saidas[7]->esta_fechada = False;

    lobby.detalhe.saidas[8] = malloc(sizeof(saidas));
    lobby.detalhe.saidas[8]->saida = &sala5;
    lobby.detalhe.saidas[8]->esta_fechada = False;

    /* Salas */
    Elemento *salas = malloc(6 * sizeof(Elemento));

    salas[0] = lobby;
    salas[1] = sala1;
    salas[2] = sala2;
    salas[3] = sala3;
    salas[4] = sala4;
    salas[5] = sala5;

    return salas;
}
