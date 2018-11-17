#include <stdlib.h>
#include <stdio.h>
#include "../libraries/initSalas.h"
#include "../libraries/elemento.h"
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

    sala1.detalhe.saidas = malloc(sizeof(Elemento*));
    sala1.detalhe.saidas[0] = &lobby;

    sala2.detalhe.saidas = malloc(sizeof(Elemento*));
    sala2.detalhe.saidas[0] = &lobby;

    sala3.detalhe.saidas = malloc(sizeof(Elemento*));
    sala3.detalhe.saidas[0] = &lobby;

    sala4.detalhe.saidas = malloc(sizeof(Elemento*));
    sala4.detalhe.saidas[0] = &lobby;

    sala5.detalhe.saidas = malloc(sizeof(Elemento*));
    sala5.detalhe.saidas[0] = &lobby;

    lobby.detalhe.saidas = malloc(5*sizeof(Elemento*));
    lobby.detalhe.saidas[0] = &sala1;
    lobby.detalhe.saidas[1] = &sala2;
    lobby.detalhe.saidas[2] = &sala3;
    lobby.detalhe.saidas[3] = &sala4;
    lobby.detalhe.saidas[4] = &sala5;

    Elemento *salas = malloc(5*sizeof(Elemento));
    salas[0] = lobby;
    salas[1] = sala1;
    salas[2] = sala2;
    salas[3] = sala3;
    salas[4] = sala4;
    salas[5] = sala5;

    return salas;
}