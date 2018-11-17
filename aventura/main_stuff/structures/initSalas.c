#include <stdlib.h>
#include <stdio.h>
#include "../libraries/elemento.h"
#include "../libraries/initSalas.h"
#include "../libraries/salas.h"

/*
    Inicializa as salas.
    Retorna todas as salas.
*/
Elemento *inicializarSalas() {
    Elemento lobby = criarSala0();
    Elemento sala1 = criarSala1();
    Elemento sala2 = criarSala2();
    Elemento sala3 = criarSala3();
    Elemento sala4 = criarSala4();
    Elemento sala5 = criarSala5();


    lobby.detalhe.saidas = malloc(5*sizeof(Elemento*));
    sala1.detalhe.saidas = malloc(sizeof(Elemento*));
    sala2.detalhe.saidas = malloc(sizeof(Elemento*));
    sala3.detalhe.saidas = malloc(sizeof(Elemento*));
    sala4.detalhe.saidas = malloc(sizeof(Elemento*));
    sala5.detalhe.saidas = malloc(sizeof(Elemento*));

    /* Direções cardeais */
    for (int i = 0; i < 4; i++) {
        lobby.detalhe.saidas[i] = NULL;
        sala1.detalhe.saidas[i] = NULL;
        sala2.detalhe.saidas[i] = NULL;
        sala3.detalhe.saidas[i] = NULL;
        sala4.detalhe.saidas[i] = NULL;
        sala5.detalhe.saidas[i] = NULL;
    }

    sala1.detalhe.saidas[4] = &lobby;
    sala2.detalhe.saidas[4] = &lobby;
    sala3.detalhe.saidas[4] = &lobby;
    sala4.detalhe.saidas[4] = &lobby;
    sala5.detalhe.saidas[4] = &lobby;

    lobby.detalhe.saidas[4] = &sala1;
    lobby.detalhe.saidas[5] = &sala2;
    lobby.detalhe.saidas[6] = &sala3;
    lobby.detalhe.saidas[7] = &sala4;
    lobby.detalhe.saidas[8] = &sala5;

    Elemento *salas = malloc(6 * sizeof(Elemento));
    // return NULL;
    salas[0] = lobby;
    salas[1] = sala1;
    salas[2] = sala2;
    salas[3] = sala3;
    salas[4] = sala4;
    salas[5] = sala5;

    return salas;
}
