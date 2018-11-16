#include <stdlib.h>
#include <stdio.h>
#include "../libraries/elemento.h"
#include "../libraries/salas.h"

/*
    Inicializa as salas.
    Retorna todas as salas.
*/
Elemento *inicializarSalas() {
    //Elemento lobby = criarLobby();
    Elemento sala1 = criarSala1();
    Elemento sala2 = criarSala2();
    Elemento sala3 = criarSala3();
    Elemento sala4 = criarSala4();
    Elemento sala5 = criarSala5();

    sala1.detalhe.saidas = malloc(sizeof(Elemento*));
    //sala1.detalhe.saidas[0] = &lobby;

    sala2.detalhe.saidas = malloc(sizeof(Elemento*));
    //sala2.detalhe.saidas[0] = &lobby;

    sala3.detalhe.saidas = malloc(sizeof(Elemento*));
    //sala3.detalhe.saidas[0] = &lobby;

    sala4.detalhe.saidas = malloc(sizeof(Elemento*));
    //sala4.detalhe.saidas[0] = &lobby;

    sala5.detalhe.saidas = malloc(sizeof(Elemento*));
    //sala5.detalhe.saidas[0] = &lobby;

    Elemento *salas = malloc(5*sizeof(Elemento));
    salas[0] = sala1;
    salas[1] = sala2;
    salas[2] = sala3;
    salas[3] = sala4;
    salas[4] = sala5;

    return salas;
}