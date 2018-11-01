#include <stdlib.h>
#include <stdio.h>
#include "elemento.h"
#include "salas.h"

Elemento criarElemento(char *nome, char *curta,
    char *longa, boolean visivel, boolean conhecido,
    Elemento *conteudo, void **acoes,
    void *animacao, Info detalhe) {

    Elemento novo;
    novo.n = nome;
    novo.curta = curta;
    novo.longa = longa;
    novo.ativo = True;
    novo.visivel = visivel;
    novo.conhecido = conhecido;
    novo.conteudo = conteudo;
    novo.acoes = acoes;
    novo.animacao = animacao;
    novo.detalhe = detalhe;

    return novo;
}

void descricao(Elemento e) {
    if (e.conhecido)
        printf("%s\n", e.curta);
    else 
        printf("%s\n", e.longa);
}

void checarRelogio() {
    printf("São 8 horas e ... minutos.\n");   
}

void checarMensagem() {
    printf("1+1 = 2\n");
}


Elemento criarSala1() {
    /* mensagem */

    void **acoesMensagem = malloc(sizeof(checar));
    acoesMensagem[0] = checarMensagem;

    Info unionDef;

    Elemento mensagem =
    criarElemento("Mensagem",
        "Mensagem",
        "Mensagem na parede", False, False, NULL,
        acoesMensagem, NULL, unionDef);

    /* chave */

    Elemento chave =
    criarElemento("Chave",
        "Chave velha",
        "Chave velha e suja", False, False, NULL,
        NULL, NULL, unionDef);

    Elemento *conteudoConcha = malloc(sizeof(Elemento));
    conteudoConcha[0] = chave;

    /* concha */

    Elemento concha =
    criarElemento("Concha",
        "Concha espiralada",
        "Concha espiralada e oca", False, False, conteudoConcha,
        NULL, NULL, unionDef);

    /* porta */

    Elemento porta =
    criarElemento("Porta",
        "Porta trancada",
        "Porta oxidada e trancada", False, False, NULL,
        NULL, NULL, unionDef);

    /* ponteiro do relogio */

    Elemento ponteiro =
    criarElemento("Ponteiro",
        "Ponteiro dos minutos",
        "Ponteiro dos minutos no chão", False, False, NULL,
        NULL, NULL, unionDef);

    /* relogio */
    
    void **acoesRelogio = malloc(sizeof(checar));
    acoesRelogio[0] = checarRelogio;

    /* para usar a funçao na lista 
    tem que fazer typecasting */

    Elemento relogio =
    criarElemento("Relogio",
        "Minutos inoperantes",
        "Sem o ponteiro dos minutos, com o ponteiro das horas \
        apontando para o 8", False, False, NULL,
        acoesRelogio, NULL, unionDef);


    /* sala 1 */

    Info unionS1;

    Elemento *conteudoS1 = malloc(5*sizeof(Elemento));
    conteudoS1[0] = relogio;
    conteudoS1[1] = ponteiro;
    conteudoS1[2] = porta;
    conteudoS1[3] = concha;
    conteudoS1[4] = chave;

    Elemento sala1 =
    criarElemento("Fibonacci",
        "Há um ponteiro no chão",
        "Há um relógio quebrado \
        e um ponteiro no chao, uma mensagem \
        na parede, uma concha em um pilar e uma \
        porta fechada", False, False, conteudoS1, NULL,
        NULL, unionS1);

    return sala1;    
}