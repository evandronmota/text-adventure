#include <stdlib.h>
#include <stdio.h>
#include "elemento.h"
#include "salas.h"

Elemento criarElemento(char *artigo, char *nome, char *curta,
    char *longa, boolean visivel, boolean conhecido,
    Elemento *conteudo, int nEle, int nAcoes, int *transitividade,
    void **acoes, void *animacao, Info detalhe) {

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
    novo.nAcoes = nAcoes;
    novo.transitividade = transitividade;
    novo.acoes = acoes;
    novo.animacao = animacao;
    novo.detalhe = detalhe;

    return novo;
}

void nomear(Elemento e) {   
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

Info unionVazia;

Elemento criarSala1() {
    /* ------------------------------------- SALA 1 ---------------------------------------------- */
    /* mensagem */

    func checarMensagem, checarRelogio;
    checarMensagem = checarRelogio = examinar;

    void **acoesMensagem = malloc(sizeof(func));
    acoesMensagem[0] = checarMensagem;

    Elemento mensagem1 =
    criarElemento("Uma","Mensagem",
        "Na parede há uma mensagem: 1 + 1 = 2.",
        "Na parede está escrito com tinta vermelha (ou será sangue...?): 1 + 1 = 2.", False, False, NULL, 0, 0, NULL,
        acoesMensagem, NULL, unionVazia);

    /* chave */

    Elemento chave1 =
    criarElemento("Uma","Chave",
        "Uma chave velha.",
        "Uma chave velha e enferrujada.", False, False, NULL, 0, 0, NULL,
        NULL, NULL, unionVazia);

    Elemento *conteudoConcha = malloc(sizeof(Elemento));
    conteudoConcha[0] = chave1;

    /* concha */

    Info unionConcha1;
    unionConcha1.atributos = malloc(sizeof(obj_atr));

    obj_atr estaQuebrada;
    estaQuebrada.nome = "estaQuebrada";
    estaQuebrada.valor.valor_estado = False;

    unionConcha1.atributos[0] = estaQuebrada;

    Elemento concha1 =
    criarElemento("Uma","Concha",
        "Uma concha em formato de espiral.",
        "Uma concha verde em formato de espiral.", False, False, conteudoConcha, 0, 0, NULL,
        NULL, NULL, unionConcha1);

    /* porta */

    Elemento porta1 =
    criarElemento("Uma", "Porta",
        "Uma porta trancada.",
        "Uma porta de ferro com fechadura dourada.", False, False, NULL, 0, 0, NULL,
        NULL, NULL, unionVazia);

    /* ponteiro do relogio */

    Info unionPonteiro1;
    unionPonteiro1.atributos = malloc(sizeof(obj_atr));

    /*
    no chao = 0
    no relogio = 1
    com o cara = 2
    */

    obj_atr comQuem;
    comQuem.nome = "comQuem";
    comQuem.valor.valor_num = 0;

    unionPonteiro1.atributos[0] = comQuem;

    Elemento ponteiro1 = 
    criarElemento("Um", "Ponteiro",
        "Um ponteiro de relógio.",
        "Um ponteiro de minutos do relógio quebrado.", False, False, NULL, 0, 0, NULL,
        NULL, NULL, unionPonteiro1);

    /* relogio */

    void **acoesRelogio = malloc(sizeof(func));
    acoesRelogio[0] = checarRelogio;
    int *tRel = malloc(sizeof(int));
    tRel[0] = 1;

    /* para usar a funçao na lista
    tem que fazer typecasting */

    Elemento relogio1 =
    criarElemento("Um","Relógio",
        "Relógio quebrado sem um dos ponteiros.",
        "Relógio sem o ponteiro dos minutos e com o ponteiro das horas apontando para o 8.",
        False, False, NULL, 0, 1, tRel, acoesRelogio, NULL, unionVazia);

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
        False, False, conteudoS1, 6, 0, NULL, NULL, NULL, unionS1);

    return sala1;
}

Elemento criarSala2(){
    /* --------------------------------------- SALA 2 --------------------------------------------- */
    /* .. ... ... --- -. .- --- . -.-. --- -.. .. --. --- -- --- .-. ... .
    0 0 0 0 0 0 0 0 1 1 1 1 0 0 1 1 1 1 0 1 0 1 0 1 1 1 1 0 0 0 0 1 1 0 1 1 1 1 1 1 1 1 0 1 0 0 0 0 0 */

    /* mensagem */

    Elemento mensagem2 =
    criarElemento("Uma","Mensagem",
        "Está escrito: \".. ... ... --- -. .- --- . -.-. --- -.. .. --. --- -- --- .-. ... .\"",
        "Numa folha de papel amassada está escrito: \".. ... ... --- -. .- --- . -.-. --- -.. .. --. --- -- --- .-. ... .\"", False, False, NULL, 0, 0, NULL,
        NULL, NULL, unionVazia);

    /* porta */

    Elemento porta2 =
    criarElemento("Uma", "Porta",
        "Uma porta.",
        "Uma porta dourada.", False, False, NULL, 0, 0, NULL,
        NULL, NULL, unionVazia);

    /* chave */

    Elemento morsa2 =
    criarElemento("Uma","Pelúcia",
        "Uma morsa de pelúcia.",
        "Uma morsa de pelúcia marrom.", False, False, NULL, 0, 0, NULL,
        NULL, NULL, unionVazia);

    /* livro */

    Elemento livro2 =
    criarElemento("Um","Livro",
        "Um livro velho. O título é \"Existem apenas -. tipos de pessoas no mundo\".",
        "Um livro velho e surpreendentemente grande. O título é \"Existem apenas 10 tipos de pessoas no mundo\".", False, False, NULL, 0, 0, NULL,
        NULL, NULL, unionVazia);

    /* pagina */

    Elemento pagina2 =
    criarElemento("Uma","Página",
        "Você já tentou procurar embaixo do cofre?.",
        "Você já tentou procurar embaixo do cofre?.", False, False, NULL, 0, 0, NULL,
        NULL, NULL, unionVazia);

    /* cofre */

    Elemento cofre2 =
    criarElemento("Um","Cofre",
        "Um cofre de ferro.",
        "Um cofre grande de ferro com uma fechadura mecânica.", False, False, NULL, 0, 0, NULL,
        NULL, NULL, unionVazia);

    /* letra */

    Elemento letra2 =
    criarElemento("Um","Papel",
        "Há uma letra \"E\".",
        "Há uma letra \"E\".", False, False, NULL, 0, 0, NULL,
        NULL, NULL, unionVazia);

    Info unionS2;

    Elemento *conteudoS2 = malloc(7*sizeof(Elemento));
    conteudoS2[0] = letra2;
    conteudoS2[1] = cofre2;
    conteudoS2[2] = livro2;
    conteudoS2[3] = pagina2;
    conteudoS2[4] = morsa2;
    conteudoS2[5] = porta2;
    conteudoS2[6] = mensagem2;

    Elemento sala2 =
    criarElemento("Uma","Binaria",
        "Uma sala.",
        "Uma sala.",
        False, False, conteudoS2, 6, 0, NULL, NULL, NULL, unionS2);

    return sala2;

}

// Elemento criarSala3(){
//     /* --------------------------------------- SALA 3 --------------------------------------------- */

//     Info unionVazia;

//     /* porta */

//     Elemento porta3 =
//     criarElemento("Uma", "Porta",
//         "Uma porta.",
//         "Uma porta de madeira.", False, False, NULL, 0,
//         NULL, NULL, unionVazia);

//     Elemento gaiola3 =
//     criarElemento("Uma", "Gaiola",
//         "Há um papagaio na gaiola.",
//         "Há um papagaio verde e tagarela na gaiola.", False, False, NULL, 0,
//         NULL, NULL, unionVazia);

//     Elemento papagaio3 =
//     criarElemento("Um", "Papagaio",
//         "Papagaio verde.",
//         "Papagaio verde e tagarela. Ele não para de falar.", False, False, NULL, 0,
//         NULL, NULL, unionVazia);

//     Elemento ima3 =
//     criarElemento("Um", "Ima",
//         "Papagaio verde.",
//         "Papagaio verde e tagarela. Ele não para de falar.", False, False, NULL, 0,
//         NULL, NULL, unionVazia);

//     Elemento tiraDaquiDps;

//     return tiraDaquiDps;
// }
