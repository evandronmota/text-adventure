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

int checar(Elemento *e1, Elemento *e2) {
    if (e1 == NULL) {
        printf("Checar o quê?");
        return 0;
    }
    // e1!=NULL e e2!=NULL ?
    else {
        printf("%s", e1->curta);
        return 1;
    }
}

Elemento criarSala1() {
    /* mensagem */
    func checarMensagem=checar, checarRelogio=checar;

    void **acoesMensagem = malloc(sizeof(func));
    acoesMensagem[0] = checarMensagem;

    Info unionDef;

    Elemento mensagem =
    criarElemento("Mensagem",
        "Na parede há uma mensagem: 1+1=2",
        "Na parede está escrito com tinta vermelha (ou será sangue...?): 1+1 = 2", False, False, NULL,
        acoesMensagem, NULL, unionDef);

    /* chave */

    Elemento chave =
    criarElemento("Chave",
        "Uma chave velha",
        "Uma chave velha e enferrujada", False, False, NULL,
        NULL, NULL, unionDef);

    Elemento *conteudoConcha = malloc(sizeof(Elemento));
    conteudoConcha[0] = chave;

    /* concha */

    Elemento concha =
    criarElemento("Concha",
        "Uma concha em formato de espiral",
        "Uma concha verde em formato de espiral", False, False, conteudoConcha,
        NULL, NULL, unionDef);

    /* porta */

    Elemento porta =
    criarElemento("Porta",
        "Uma porta trancada",
        "Uma porta de ferro com fechadura dourada", False, False, NULL,
        NULL, NULL, unionDef);

    /* ponteiro do relogio */

    Elemento ponteiro =
    criarElemento("Ponteiro",
        "Um ponteiro de relógio",
        "Um ponteiro de minutos do relógio quebrado", False, False, NULL,
        NULL, NULL, unionDef);

    /* relogio */
    
    void **acoesRelogio = malloc(sizeof(func));
    acoesRelogio[0] = checarRelogio;

    /* para usar a funçao na lista 
    tem que fazer typecasting */

    Elemento relogio =
    criarElemento("Relogio",
        "Relógio quebrado sem um dos ponteiros",
        "Relógio sem o ponteiro dos minutos, com o ponteiro das horas \
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
        "Uma sala empoeirada com cheiro de mofo.",
        "Uma sala empoeirada com cheiro de mofo. Há um relógio e um ponteiro no chão. Na parede está escrita uma mensagem e em sob um pedestal há uma concha. Além disso, tem uma porta no fundo da sala.",
        False, False, conteudoS1, NULL, NULL, unionS1);

    return sala1;    
}