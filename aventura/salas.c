#include <stdlib.h>
#include <stdio.h>
#include "elemento.h"
#include "salas.h"

Elemento criarElemento(char *artigo, char *nome, char *curta,
    char *longa, boolean visivel, boolean conhecido,
    Elemento *conteudo, int nEle, void **acoes,
    void *animacao, Info detalhe) {

    Elemento novo;
    novo.artigo = artigo;
    novo.n = nome;
    novo.curta = curta;
    novo.longa = longa;
    novo.ativo = True;
    novo.visivel = visivel;
    novo.conhecido = conhecido;
    novo.conteudo = conteudo;
    novo.nEle = nEle;
    novo.acoes = acoes;
    novo.animacao = animacao;
    novo.detalhe = detalhe;

    return novo;
}

void nome(Elemento e) {
    printf("%s %s.\n", e.artigo, e.n);
}

int examinar(Elemento *e1, Elemento *e2) {
    if (e1 == NULL) 
        printf("Examinar o quê?\n");
    else if (e1->conhecido)
        printf("%s\n", e1->curta);
    else {
        printf("%s\n", e1->longa);
        e1->conhecido = True;
    }
    return (e1==NULL? 0: 1);
}

Elemento criarSala1() {
    /* ------------------------------------- SALA 1 ---------------------------------------------- */
    /* mensagem */
    
    func checarMensagem, checarRelogio;
    checarMensagem = checarRelogio = examinar;

    void **acoesMensagem = malloc(sizeof(func));
    acoesMensagem[0] = checarMensagem;

    Info unionDef;

    Elemento mensagem1 =
    criarElemento("Uma","Mensagem",
        "Na parede há uma mensagem: 1 + 1 = 2.",
        "Na parede está escrito com tinta vermelha (ou será sangue...?): 1 + 1 = 2.", False, False, NULL, 0,
        acoesMensagem, NULL, unionDef);

    /* chave */

    Elemento chave1 =
    criarElemento("Uma","Chave",
        "Uma chave velha.",
        "Uma chave velha e enferrujada.", False, False, NULL, 0,
        NULL, NULL, unionDef);

    Elemento *conteudoConcha = malloc(sizeof(Elemento));
    conteudoConcha[0] = chave1;

    /* concha */

    Elemento concha1 =
    criarElemento("Uma","Concha",
        "Uma concha em formato de espiral.",
        "Uma concha verde em formato de espiral.", False, False, conteudoConcha, 0,
        NULL, NULL, unionDef);

    /* porta */

    Elemento porta1 =
    criarElemento("Uma", "Porta",
        "Uma porta trancada.",
        "Uma porta de ferro com fechadura dourada.", False, False, NULL, 0,
        NULL, NULL, unionDef);

    /* ponteiro do relogio */

    Elemento ponteiro1 =
    criarElemento("Um", "Ponteiro",
        "Um ponteiro de relógio.",
        "Um ponteiro de minutos do relógio quebrado.", False, False, NULL, 0,
        NULL, NULL, unionDef);

    /* relogio */
    
    void **acoesRelogio = malloc(sizeof(func));
    acoesRelogio[0] = checarRelogio;

    /* para usar a funçao na lista 
    tem que fazer typecasting */

    Elemento relogio1 =
    criarElemento("Um","Relógio",
        "Relógio quebrado sem um dos ponteiros.",
        "Relógio sem o ponteiro dos minutos e com o ponteiro das horas apontando para o 8.", 
        False, False, NULL, 0, acoesRelogio, NULL, unionDef);


    /* sala 1 */

    Info unionS1;

    Elemento *conteudoS1 = malloc(6*sizeof(Elemento));
    conteudoS1[0] = relogio1;
    conteudoS1[1] = ponteiro1;
    conteudoS1[2] = porta1;
    conteudoS1[3] = concha1;
    conteudoS1[4] = chave1;
    conteudoS1[5] = mensagem1;

    Elemento sala1 =
    criarElemento("Uma","Fibonacci",
        "Uma sala empoeirada com cheiro de mofo.",
        "Uma sala empoeirada com cheiro de mofo. Há um relógio e um ponteiro no chão. Na parede está escrita uma mensagem e sob um pedestal há uma concha. Além disso, tem uma porta no fundo da sala.",
        False, False, conteudoS1, 6, NULL, NULL, unionS1);

    return sala1;

    
    
    
    /* --------------------------------------- SALA 2 --------------------------------------------- */
    /* .. ... ... --- -. .- --- . -.-. --- -.. .. --. --- -- --- .-. ... .
    0 0 0 0 0 0 0 0 1 1 1 1 0 0 1 1 1 1 0 1 0 1 0 1 1 1 1 0 0 0 0 1 1 0 1 1 1 1 1 1 1 1 0 1 0 0 0 0 0 */

/* 
    func checarMensagem=checar, checarRelogio=checar;

    void **acoesMensagem = malloc(sizeof(func));
    acoesMensagem[0] = checarMensagem;

    Info unionDef; */

    /* mensagem */

    Elemento mensagem2 =
    criarElemento("Uma","Mensagem",
        "Está escrito: \".. ... ... --- -. .- --- . -.-. --- -.. .. --. --- -- --- .-. ... .\"",
        "Numa folha de papel amassada está escrito: \".. ... ... --- -. .- --- . -.-. --- -.. .. --. --- -- --- .-. ... .\"", False, False, NULL, 0,
        acoesMensagem, NULL, unionDef);

    /* porta */

    Elemento porta2 =
    criarElemento("Uma", "Porta",
        "Uma porta.",
        "Uma porta dourada.", False, False, NULL, 0,
        NULL, NULL, unionDef);

    /* chave */

    Elemento morsa2 =
    criarElemento("Uma","Morsa",
        "Uma morsa de pelúcia.",
        "Uma morsa de pelúcia", False, False, NULL, 0,
        NULL, NULL, unionDef);
}