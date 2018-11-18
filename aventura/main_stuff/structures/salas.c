#include <stdlib.h>
#include <stdio.h>
#include "../libraries/elemento.h"
#include "../libraries/aventureiro.h"
#include "../libraries/salas.h"


/*
    Recebe um ponteiro para um elemento e uma função de
    ação. Adiciona essa ação à lista de ações do elemento.
*/
void adicionarAcao(Elemento *e, func acao, int transitividade) {
    e->nAcoes++;
    e->acoes = realloc(e->acoes, e->nAcoes*sizeof(func));
    e->acoes[e->nAcoes-1] = acao;

    e->transitividade = realloc(e->transitividade, e->nAcoes*sizeof(int));
    e->transitividade[e->nAcoes-1] = transitividade;
}

/*
    Recebe um ponteiro para um elemento e um atributo.
    Adiciona esse atributo à lista de atributos do elemento.
*/
void adicionarAtributo(Elemento *e, obj_atr atributo) {
    e->nAtr++;
    e->detalhe.atributos = realloc(e->detalhe.atributos, e->nAtr*sizeof(obj_atr));
    e->detalhe.atributos[e->nAtr-1] = atributo;
}

/* 
    Recebe dois ponteiros para elementos.
    Adiciona o segundo elemento à lista de conteúdos do
    primeiro.
*/
void adicionarElemento(Elemento *contem, Elemento *contido) {
    contido->nEle++;
    contido->conteudo = realloc(contido->conteudo, contido->nEle*sizeof(Elemento));
    contido->conteudo[contido->nEle-1] = *contem;
}

/*
    Recebe os parâmetros necessários ao elemento.
    Cria um elemento com esses parâmetros.
    Retorna o elemento criado.
*/
Elemento criarElemento(int isObjeto, char *artigo, char *nome, char *curta,
    char *longa, boolean visivel, boolean conhecido,
    Elemento *conteudo, int nEle, void *animacao) {

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
    novo.nAcoes = 3;
    novo.nAtr = 2;
    novo.transitividade = malloc(3*sizeof(int));
    novo.transitividade[0] = 1;
    novo.transitividade[1] = 1;
    novo.transitividade[2] = 1;

    novo.acoes = malloc(3*sizeof(func));
    novo.acoes[0] = examinar;
    novo.acoes[1] = pegar;
    novo.acoes[2] = largar;

    novo.animacao = animacao;

    /* Union padrao para os objetos */
    Info detalhe;
    if (isObjeto) {
        detalhe.atributos = malloc(2 * sizeof(obj_atr));

        obj_atr pegavel;
        pegavel.nome = "pegavel";
        pegavel.valor.valor_estado = True;

        obj_atr largavel;
        largavel.nome = "largavel";
        largavel.valor.valor_estado = True;

        detalhe.atributos[0] = pegavel;
        detalhe.atributos[1] = largavel;
    }

    novo.detalhe = detalhe;

    return novo;
}


void nome(Elemento e) {   
    printf("%c%c%c %s.\n", e.artigo[0]-32, e.artigo[1], e.artigo[2], e.n);
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

    return (e1 == NULL ? 0 : 1);
}

int pegar(Elemento *e1, Elemento *e2) {
    if (e1 == NULL)
        printf("Pegar o quê?\n");
    else  {
        if (e1->detalhe.atributos[1].valor.valor_estado)
            printf("Você pegou %s %s.\n", e1->artigo, e1->n);
        else printf("Você não pode pegar %s %s.\n", e1->artigo, e1->n);
    }

    return (e1 == NULL ? 0 : 1);
}

int largar(Elemento *e1, Elemento *e2) {
    if (e1 == NULL)
        printf("Largar o quê?\n");
    else {
        if (e2 == NULL)
            printf("Você largou %s %s.\n", e1->artigo, e1->n);
        else
            printf("Você %s %s n%s %s.\n", e1->artigo, e1->n, e2->artigo, e2->n);
    }

    return (e1 == NULL ? 0 : 1);
}

/* Quebrar elemento e1 com elemento e2 */
int quebrar(Elemento *e1, Elemento *e2) {
    int i;

    /* Elementos NULL */
    if (e1 == NULL)
        printf("Quebrar o quê?\n");
    else {
        /* Quebrar sem elemento e2 */
        if (e2 == NULL) {
            for (i=0; i<e1->nAtr; i++) { /* Procura atributo */
                if (e1->detalhe.atributos[i].nome == "estaQuebrada") { /* Acha estaQuebrada */
                    if (e1->detalhe.atributos[i].valor.valor_estado == False) { /* Se não está quebrada */
                        e1->detalhe.atributos[i].valor.valor_estado = True;
                        printf("Você quebrou %s %s!\n", e1->artigo, e1->n);
                        if (e1->n == "Concha") {
                            /* Colocar na mochila do Aventureiro */
                            e1->nEle--;
                            free(e1->conteudo);
                        }

                    }
                    else /* Se está quebrada */
                        printf("Você já quebrou %s %s!\n", e1->artigo, e1->n);
                    break;
                }
            }
        }
        // else {
        //     /* Quebrar com algo */
        // }
    }

    return (e1 == NULL ? 0 : 1);
}

int colocarSobre(Elemento *e1, Elemento *e2) {
    if (e1 == NULL)
        printf("Colocar o quê?\n");
    else if (e2 == NULL)
        printf("Colocar onde?\n");
    else {
        printf("Você colocou %s %s n%s %s.\n", e1->artigo, e1->n, e2->artigo, e2->n);
        adicionarElemento(e1, e2);
    }

    return (e1 == NULL || e2 == NULL ? 0 : 1);
}


Elemento criarSala0() {
    /* ------------------------------------- SALA 0 ---------------------------------------------- */

    /* Porta 1 */
    Elemento porta1 =
    criarElemento(1, "uma", "Porta 1",
        "Uma porta de ferro.",
        "Uma porta de ferro com fechadura dourada.",
        False, False, NULL, 0,
        NULL);

    porta1.detalhe.atributos[0].valor.valor_estado = False;
    porta1.detalhe.atributos[1].valor.valor_estado = False;

    /* Porta 2 */
    Elemento porta2 =
    criarElemento(1, "uma", "Porta 2",
        "Uma porta dourada.",
        "Uma porta dourada muito velha.",
        False, False, NULL, 0,
        NULL);

    porta2.detalhe.atributos[0].valor.valor_estado = False;
    porta2.detalhe.atributos[1].valor.valor_estado = False;

    /* Porta 3 */
    Elemento porta3 =
    criarElemento(1, "uma", "Porta 3",
        "Uma porta de madeira.",
        "Uma porta de madeira de ébano.",
        False, False, NULL, 0,
        NULL);

    porta3.detalhe.atributos[0].valor.valor_estado = False;
    porta3.detalhe.atributos[1].valor.valor_estado = False;

    /* Porta 4 */
    Elemento porta4 =
    criarElemento(1, "uma", "Porta 4",
        "Uma porta branca.",
        "Uma porta branca cheia de lascas.",
        False, False, NULL, 0,
        NULL);

    porta4.detalhe.atributos[0].valor.valor_estado = False;
    porta4.detalhe.atributos[1].valor.valor_estado = False;

    /* Porta 5 */
    Elemento porta5 =
    criarElemento(1, "uma", "Porta 5",
        "Uma porta vermelha.",
        "Uma porta vermelha com fechadura preta.",
        False, False, NULL, 0,
        NULL);

    porta5.detalhe.atributos[0].valor.valor_estado = False;
    porta5.detalhe.atributos[1].valor.valor_estado = False;

    /* GLaDOS */
    Elemento GLaDOS =
    criarElemento(1, "um", "Robô",
        "Um robô com voz feminina.",
        "Um robô com voz feminina fala com você: \
        \n \"Olá, seja bem-vindo ao Aperture Science Computer-Aided Enrichment Center. Você poderia me dizer a senha?\"",
        False, False, NULL, 0,
        NULL);


    /* Sala 0 */
    Elemento *conteudoS0 = malloc(6 * sizeof(Elemento));
    conteudoS0[0] = porta1;
    conteudoS0[1] = porta2;
    conteudoS0[2] = porta3;
    conteudoS0[3] = porta4;
    conteudoS0[4] = porta5;
    conteudoS0[5] = GLaDOS;

    Elemento sala0 =
    criarElemento(0, "um", "Lobby",
        "Uma sala ampla com 5 portas e circular.",
        "Uma sala ampla com 5 portas e circular. No centro há um robô branco. Ele está olhando para você ...",
        False, False, conteudoS0, 0,
        NULL);

    return sala0;
}









Elemento criarSala1() {
    /* ------------------------------------- SALA 1 ---------------------------------------------- */

    /* Mensagem */
    func checarMensagem, checarRelogio;
    checarMensagem = checarRelogio = examinar;

    Elemento mensagem =
    criarElemento(1, "uma","Mensagem",
        "Na parede há uma mensagem: 1 + 1 = 2.",
        "Na parede está escrito com tinta vermelha: 1 + 1 = 2.",
        False, False, NULL, 0,
        NULL);

    mensagem.detalhe.atributos[0].valor.valor_estado = False;
    mensagem.detalhe.atributos[1].valor.valor_estado = False;

    /* Letra */
    Elemento letra =
    criarElemento(1, "uma","Letra",
        "Uma letra A.",
        "Uma letra A de madeira.",
        False, False, NULL, 0,
        NULL);

    Elemento *conteudoConcha = malloc(sizeof(Elemento));
    conteudoConcha[0] = letra;


    /* Concha */
    obj_atr estaQuebrada;
    estaQuebrada.nome = "estaQuebrada";
    estaQuebrada.valor.valor_estado = False;

    func quebrarConcha = quebrar;

    Elemento concha =
    criarElemento(1, "uma","Concha",
        "Uma concha em formato de espiral.",
        "Uma concha verde em formato de espiral.",
        False, False, conteudoConcha, 1,
        NULL);

    adicionarAtributo(&concha, estaQuebrada);
    adicionarAcao(&concha, quebrarConcha, 1);

    /* Porta */
    Elemento porta =
    criarElemento(1, "uma", "Porta",
        "Uma porta para o lobby.",
        "Uma porta de ferro com fechadura dourada para o lobby.",
        False, False, NULL, 0,
        NULL);

    porta.detalhe.atributos[0].valor.valor_estado = False;
    porta.detalhe.atributos[1].valor.valor_estado = False;

    


    /* Ponteiro do relógio */

    /*
        no chão = 0
        no relógio = 1
        com o aventureiro = 2
    */

    obj_atr comQuem;
    comQuem.nome = "comQuem";
    comQuem.valor.valor_num = 0;

    func colocarnoRelogio = colocarSobre;

    Elemento ponteiro = 
    criarElemento(1, "um", "Ponteiro",
        "Um ponteiro de relógio.",
        "Um ponteiro de minutos do relógio quebrado.",
        False, False, NULL, 0,
        NULL);

    adicionarAtributo(&ponteiro, comQuem);
    adicionarAcao(&ponteiro, colocarnoRelogio, 2);


    /* Relógio */
    Elemento relogio =
    criarElemento(1, "um","Relógio",
        "Relógio quebrado sem um dos ponteiros.",
        "Relógio sem o ponteiro dos minutos e com o ponteiro das horas apontando para o VIII.",
        False, False, NULL, 0, 
        NULL);


    /* Sala 1 */
    Elemento *conteudoS1 = malloc(6*sizeof(Elemento));
    conteudoS1[0] = relogio;
    conteudoS1[1] = ponteiro;
    conteudoS1[2] = porta;
    conteudoS1[3] = concha;
    conteudoS1[4] = letra;
    conteudoS1[5] = mensagem;

    Elemento sala1 =
    criarElemento(0, "uma", "Fibonacci",
        "Uma sala empoeirada com cheiro de mofo.",
        "Uma sala empoeirada com cheiro de mofo. Há um relógio e um ponteiro no chão. Na parede está escrita uma mensagem e sob um pedestal há uma concha. Além disso, tem uma porta no fundo da sala.",
        False, False, conteudoS1, 6,
        NULL);

    return sala1;
}











Elemento criarSala2() {
    /* --------------------------------------- SALA 2 --------------------------------------------- */
    /* .. ... ... --- -. .- --- . -.-. --- -.. .. --. --- -- --- .-. ... .
    0 0 0 0 0 0 0 0 1 1 1 1 0 0 1 1 1 1 0 1 0 1 0 1 1 1 1 0 0 0 0 1 1 0 1 1 1 1 1 1 1 1 0 1 0 0 0 0 0 */


    /* Mensagem */
    Elemento mensagem =
    criarElemento(1, "uma","Mensagem",
        "Está escrito: \".. ... ... --- -. .- --- . -.-. --- -.. .. --. --- -- --- .-. ... .\"",
        "Numa folha de papel amassada está escrito: \".. ... ... --- -. .- --- . -.-. --- -.. .. --. --- -- --- .-. ... .\"", False, False, NULL, 0,
        NULL);

    mensagem.detalhe.atributos[0].valor.valor_estado = False;
    mensagem.detalhe.atributos[1].valor.valor_estado = False;

    /* Porta */
    Elemento porta =
    criarElemento(1, "uma", "Porta",
        "Uma porta.",
        "Uma porta dourada.", 
        False, False, NULL, 0,
        NULL);

    porta.detalhe.atributos[0].valor.valor_estado = False;
    porta.detalhe.atributos[1].valor.valor_estado = False;


    /* Morsa */
    obj_atr estaQuebrada;
    estaQuebrada.nome = "estaQuebrada";
    estaQuebrada.valor.valor_estado = False;

    func quebrarMorsa = quebrar;
    Elemento morsa =
    criarElemento(1, "uma","Pelúcia",
        "Uma morsa de pelúcia.",
        "Uma morsa de pelúcia marrom.", 
        False, False, NULL, 0,
        NULL);

    adicionarAtributo(&morsa, estaQuebrada);
    adicionarAcao(&morsa, quebrarMorsa, 1);

    /* Livro */
    Elemento livro =
    criarElemento(1, "um","Livro",
        "Um livro velho. O título é \"Existem apenas -. tipos de pessoas no mundo\".",
        "Um livro velho e surpreendentemente grande. O título é \"Existem apenas 10 tipos de pessoas no mundo\".",
        False, False, NULL, 0,
        NULL);


    /* Página */
    Elemento pagina =
    criarElemento(1, "uma","Página",
        "Você já tentou procurar embaixo do cofre?.",
        "Você já tentou procurar embaixo do cofre?.",
        False, False, NULL, 0,
        NULL);


    /* Cofre */
    Elemento cofre =
    criarElemento(1, "um","Cofre",
        "Um cofre de ferro.",
        "Um cofre grande de ferro com uma fechadura mecânica.",
        False, False, NULL, 0,
        NULL);


    /* Letra */
    Elemento letra =
    criarElemento(1, "uma","Letra",
        "Uma letra \"B\".",
        "Uma letra \"B\" de madeira.",
        False, False, NULL, 0,
        NULL);


    /* Sala 2 */
    

    Elemento *conteudoS2 = malloc(7*sizeof(Elemento));
    conteudoS2[0] = letra;
    conteudoS2[1] = cofre;
    conteudoS2[2] = livro;
    conteudoS2[3] = pagina;
    conteudoS2[4] = morsa;
    conteudoS2[5] = porta;
    conteudoS2[6] = mensagem;

    Elemento sala2 =
    criarElemento(0, "uma","Binaria",
        "Uma sala legal.",
        "Uma sala com um cofre, livro, mensagem, página, morsa e porta aberta",
        False, False, conteudoS2, 7,
        NULL);

    return sala2;
}











Elemento criarSala3(){
    /* --------------------------------------- SALA 3 --------------------------------------------- */



    /* Porta */
    Elemento porta =
    criarElemento(1, "uma", "Porta",
        "Uma porta.",
        "Uma porta de madeira.",
        False, False, NULL, 0,
        NULL);

    porta.detalhe.atributos[0].valor.valor_estado = False;
    porta.detalhe.atributos[1].valor.valor_estado = False;

    /* Letra */
    Elemento letra = 
    criarElemento(1, "uma", "Letra",
        "Uma letra \"R\".",
        "Uma letra \"R\".",
        False, False, NULL, 0,
        NULL);

    Elemento *conteudoOvo = malloc(1*sizeof(Elemento));
    conteudoOvo[0] = letra;

    /* Ovo */
    Elemento ovo = 
    criarElemento(1, "um", "Ovo",
        "Um ovo brilhante.",
        "Um ovo feito de aço.",
        False, False, conteudoOvo, 1,
        NULL);

    /* Galinha */
    Elemento *conteudoGalinha = malloc(1*sizeof(Elemento));
    conteudoGalinha[0] = ovo;

    Elemento galinha =
    criarElemento(1, "uma", "Galinha",
        "Uma galinha branca.",
        "Uma galinha grande com penas brancas.",
        False, False, conteudoGalinha, 1,
        NULL);

    /* Gaiola */
    Elemento *conteudoGaiola = malloc(1*sizeof(Elemento));
    conteudoGaiola[0] = galinha;

    Elemento gaiola =
    criarElemento(1, "uma", "Gaiola",
        "Uma gaiola dourada.",
        "Uma grande gaiola dourada. Há uma galinha presa nela?...",
        False, False, conteudoGaiola, 1,
        NULL);

    /* Metal */
    Elemento metal =
    criarElemento(1, "um", "Metal",
        "Uma pequena barra de metal.",
        "Uma pequena barra de metal. Nela está gradado: \"Co\"",
        False, False, NULL, 0,
        NULL);

    /* Bobina */
    Elemento bobina =
    criarElemento(1, "uma", "Bobina",
        "Uma grande bobina elétrica.",
        "Uma grande bobina elétrica. No centro há um buraco pequeno e na lateral um botão vermelho.",
        False, False, NULL, 0,
        NULL);

    /* Botão */
    Elemento botao = 
    criarElemento(1, "um", "Botão",
        "Um botão vermelho.",
        "Um botão grande e vermelho.",
        False, False, NULL, 0,
        NULL);

    /* Saco */
    Elemento saco = 
    criarElemento(1, "um", "Saco",
        "Um saco com milho.",
        "Um saco de linho com milho.",
        False, False, NULL, 0,
        NULL);


    /* Sala 3 */
    

    Elemento *conteudoS3 = malloc(10*sizeof(Elemento));
    conteudoS3[0] = porta;
    conteudoS3[1] = gaiola;
    conteudoS3[2] = galinha;
    conteudoS3[3] = ovo;
    conteudoS3[4] = bobina;
    conteudoS3[5] = botao;
    conteudoS3[6] = metal;
    conteudoS3[7] = saco;
    conteudoS3[8] = chave;
    conteudoS3[9] = letra;
    
    Elemento sala3 =
    criarElemento(0, "uma","Galinhada",
        "Uma sala circular. No centro há uma gaiola pendurada no teto e uma bobina muito grande no chão.",
        "Uma sala circular. No centro há uma gaiola pendurada no teto e uma bobina muito grande no chão. No fundo há um saco de de linho e ao lado uma barra de metal.",
        False, False, conteudoS3, 10,
        NULL);

    return sala3;
}
















Elemento criarSala4() {

    /* ------------------------------------- SALA 4 ---------------------------------------------- */

    /* Mensagem */
    Elemento mensagem =
    criarElemento(1, "uma", "Mensagem",
        "Na parede há uma mensagem: acho que há pressão demais por aqui",
        "Na parede está escrito em azul: acho que há pressão demais por aqui",
        False, True, NULL, 0,
        NULL);

    mensagem.detalhe.atributos[0].valor.valor_estado = False;
    mensagem.detalhe.atributos[1].valor.valor_estado = False;


    /* Poema */
    Elemento poema =
    criarElemento(1, "um", "Poema",
        "Poema sem o sétimo verso.",
        "Poema escrito a tinta com uma caligrafia estranha. Está faltando o sétimo verso.",
        False, True, NULL, 0,
        NULL);


    /* Blocos */
    obj_atr estaNaBalanca;
    estaNaBalanca.nome = "estaNaBalanca";
    estaNaBalanca.valor.valor_estado = False;

    func colocarBlocoSobre = colocarSobre;
    func tirarBlocoDeCima = pegar;


    /* Bloco 0 */
    
    
    

    Elemento bloco0 =
    criarElemento(1, "um", "Bloco 0",
        "Bloco com o número 0.",
        "Bloco empoeirado e com o número 0 gravado.",
        False, True, NULL, 0,
        NULL);


    adicionarAcao(&bloco0 ,colocarBlocoSobre, 2);
    adicionarAtributo(&bloco0, estaNaBalanca);



    /* Bloco 1 */
    
    
    // return mensagem;
    

    Elemento bloco1 =
    criarElemento(1, "um", "Bloco 1",
        "Bloco com o número 1.",
        "Bloco empoeirado e com o número 1 gravado.",
        False, True, NULL, 0,
        NULL);
    

    adicionarAcao(&bloco1 ,colocarBlocoSobre, 2);
    adicionarAtributo(&bloco1, estaNaBalanca);
    


    
    
    


    /* Bloco 2 */
    



    Elemento bloco2 =
    criarElemento(1, "um", "Bloco 2",
        "Bloco com o número 2.",
        "Bloco empoeirado e com o número 2 gravado.",
        False, True, NULL, 0,
        NULL);


    adicionarAcao(&bloco2 ,colocarBlocoSobre, 2);
    adicionarAtributo(&bloco2, estaNaBalanca);
    


    
    



    /* Bloco 3 */
    
    
    

    Elemento bloco3 =
    criarElemento(1, "um", "Bloco 3",
        "Bloco com o número 3.",
        "Bloco empoeirado e com o número 3 gravado.",
        False, True, NULL, 0,
        NULL);


    adicionarAcao(&bloco3 ,colocarBlocoSobre, 2);
    adicionarAtributo(&bloco3, estaNaBalanca);
    


    
    



    /* Bloco 4 */
    
    
    

    Elemento bloco4 =
    criarElemento(1, "um", "Bloco 4",
        "Bloco com o número 4.",
        "Bloco empoeirado e com o número 4 gravado.",
        False, True, NULL, 0,
        NULL);


    adicionarAcao(&bloco4 ,colocarBlocoSobre, 2);
    adicionarAtributo(&bloco4, estaNaBalanca);
    


    
    



    /* Bloco 5 */
    
    
    

    Elemento bloco5 =
    criarElemento(1, "um", "Bloco 5",
        "Bloco com o número 5.",
        "Bloco empoeirado e com o número 5 gravado.",
        False, True, NULL, 0,
        NULL);


    adicionarAcao(&bloco5 ,colocarBlocoSobre, 2);
    adicionarAtributo(&bloco5, estaNaBalanca);
    


    
    



    /* Bloco 6 */
    
    
    

    Elemento bloco6 =
    criarElemento(1, "um", "Bloco 6",
        "Bloco com o número 6.",
        "Bloco empoeirado e com o número 6 gravado.",
        False, True, NULL, 0,
        NULL);


    adicionarAcao(&bloco6 ,colocarBlocoSobre, 2);
    adicionarAtributo(&bloco6, estaNaBalanca);
    


    
    



    /* Bloco 7 */
    
    
    

    Elemento bloco7 =
    criarElemento(1, "um", "Bloco 7",
        "Bloco com o número 7.",
        "Bloco empoeirado e com o número 7 gravado.",
        False, True, NULL, 0,
        NULL);


    adicionarAcao(&bloco7 ,colocarBlocoSobre, 2);
    adicionarAtributo(&bloco7, estaNaBalanca);
    


    
    



    /* Bloco 8 */
    
    
    

    Elemento bloco8 =
    criarElemento(1, "um", "Bloco 8",
        "Bloco com o número 8.",
        "Bloco empoeirado e com o número 8 gravado.",
        False, True, NULL, 0,
        NULL);


    adicionarAcao(&bloco8 ,colocarBlocoSobre, 2);
    adicionarAtributo(&bloco8, estaNaBalanca);
    


    
    



    /* Bloco 9 */
    
    
    

    Elemento bloco9 =
    criarElemento(1, "um", "Bloco 9",
        "Bloco com o número 9.",
        "Bloco empoeirado e com o número 9 gravado.",
        False, True, NULL, 0,
        NULL);


    adicionarAcao(&bloco9 ,colocarBlocoSobre, 2);
    adicionarAtributo(&bloco9, estaNaBalanca);
    


    
    

    /* Porta */
    Elemento porta =
    criarElemento(1, "uma", "Porta",
        "Uma porta branca.",
        "Uma porta branca com várias lascas.", 
        False, True, NULL, 0,
        NULL);

    porta.detalhe.atributos[0].valor.valor_estado = False;
    porta.detalhe.atributos[1].valor.valor_estado = False;


    /* Balança */
    Elemento balanca =
    criarElemento(1, "uma", "Balança",
        "Balança antiga.",
        "Balança um pouco enferrujada. Aparenta ser bem antiga.",
        False, True, NULL, 0,
        NULL);




    /* Sala 4 */
    Elemento* conteudoS4 = malloc(14*sizeof(Elemento));
    conteudoS4[0] = mensagem;
    conteudoS4[1] = poema;
    conteudoS4[2] = balanca;
    conteudoS4[3] = porta;
    conteudoS4[4] = bloco0;
    conteudoS4[5] = bloco1;
    conteudoS4[6] = bloco2;
    conteudoS4[7] = bloco3;
    conteudoS4[8] = bloco4;
    conteudoS4[9] = bloco5;
    conteudoS4[10] = bloco6;
    conteudoS4[11] = bloco7;
    conteudoS4[12] = bloco8;
    conteudoS4[13] = bloco9;

    

    Elemento sala4 =
    criarElemento(0, "uma", "Pascal",
    "Uma sala triangular.",
    "Uma sala triangular. Há uma mesa com blocos, um papel com um poema no chão, uma mensagem na parede e uma balança.",
    False, True, conteudoS4, 14,
    NULL);

    return sala4;
}









Elemento criarSala5() {

    /* ------------------------------------- SALA 5 ---------------------------------------------- */

    func checarEnigma, checarMapa, checarPoster, checarCaixa, checarLata, checarPorta;
    checarEnigma = checarMapa = checarPoster = checarCaixa = checarLata = checarPorta = examinar;

    /* Enigma */
    Elemento enigma =
    criarElemento(1, "uma", "mensagem",
        "O que o cientista disse quando encontrou 2 atomos de hélio? HeHe.",
        "Um enigma.",
        False, False, NULL, 0,
        NULL);

    /* Mapa */
    Elemento mapa =
    criarElemento(1, "um", "mapa",
        "Qual país está faltando?",
        "Um mapa do mundo faltando um país.",
        False, False, NULL, 0,
        NULL);

    /* Poster */
    Elemento poster =
    criarElemento(1, "um", "Poster",
        "Poster de Blade Runner.",
        "Poster da cidade futurista de Los Angeles com muitas luzes, telões e carros voadores.",
        False, False, NULL, 0,
        NULL);

    /* Caixa de fósforo */
    Elemento caixadefosforo =
    criarElemento(1, "uma", "Caixa de Fósoforo",
        "Uma caixa de fósforo.",
        "Uma caixa de fósforo.",
        False, False, NULL, 0,
        NULL);

    /* Lata de refrigerante */
    Elemento lataderefri =
    criarElemento(1, "uma", "Lata de refrigerante.",
        "Lata de refrigerante.",
        "Lata de refrigerante.",
        False, False, NULL, 0,
        NULL);

    /* Porta */
    Elemento porta =
    criarElemento(1, "uma", "Porta",
        "Uma porta vermelha.",
        "Uma porta vermelha com fechadura preta.",
        False, False, NULL, 0,
        NULL);

    porta.detalhe.atributos[0].valor.valor_estado = False;
    porta.detalhe.atributos[1].valor.valor_estado = False;

    /* Sala 5 */
    Elemento *conteudoS5 = malloc(6*sizeof(Elemento));
    conteudoS5[0] = enigma;
    conteudoS5[1] = mapa;
    conteudoS5[2] = poster;
    conteudoS5[3] = caixadefosforo;
    conteudoS5[4] = lataderefri;
    conteudoS5[5] = porta;

    Elemento sala5 =
    criarElemento(0, "uma", "NePAl",
        "A room.",
        "Tem um poster, uma caixa de fósforo e uma lata.", 
        False, False, conteudoS5, 6,
        NULL);

    return sala5;
}
