#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "elemento.h"
#include "salas.h"

/*
    Recebe os parâmetros necessários ao elemento.
    Cria um elemento com esses parâmetros.
    Retorna o elemento criado.
*/
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

/*
    Recebe um elemento. Imprime o nome do elemento
    recebido precedido de seu artigo.
*/
void nome(Elemento e) {   
    printf("%s %s.\n", e.artigo, e.n);
}

/*
    Recebe dois ponteiros para elementos.
    Imprime a descrição do primeiro elemento caso
    essa seja uma ação válida para ele.
    Retorna um inteiro indicando se a ação foi
    bem-sucedida.
*/
int examinar(Elemento *e1, Elemento *e2) {
    if (e1 == NULL) // verbo intransitivo
        printf("Examinar o quê?\n");
    else if (e1->conhecido) // verbo transitivo
        printf("%s\n", e1->curta);
    else { // verbo bitransitivo
        printf("%s\n", e1->longa);
        e1->conhecido = True;
    }
    return (e1 == NULL ? 0 : 1);
}

/*
    Recebe dois ponteiros para elementos.
    Imprime uma mensagem avisando que o primeiro
    elemento foi colocado sobre o segundo.
    Retorna um inteiro indicando se a ação foi
    bem-sucedida.
*/
int colocarSobre(Elemento *e1, Elemento *e2) {
    if (e1 == NULL)
        printf("Colocar o quê?\n");
    else if (e2 == NULL)
        printf("Colocar onde?\n");
    else {
        printf("Você colocou %s %s n%s %s.", e1->artigo, e1->n, e2->artigo, e2->n);
    }

    return (e1 == NULL || e2 == NULL ? 0 : 1);
}

int tirarDeCima(Elemento *e1, Elemento *e2) {
    if (e1 == NULL)
        printf("Colocar o quê?\n");
    else if (e2 == NULL)
        printf("Colocar onde?\n");
    else {
        printf("Você tirou %s %s d%s %s.", e1->artigo, e1->n, e2->artigo, e2->n);
    }

    return (e1 == NULL || e2 == NULL ? 0 : 1);
}

// union para objetos sem atributos
Info unionVazia;

/*
    Cria a primeira sala com todos os objetos.
    Retorna a sala criada.
*/
Elemento criarSala1() {
    /* ------------------------------------- SALA 1 ---------------------------------------------- */
    /*++++++++++++++++++mensagem++++++++++++++++++*/

    func checarMensagem, checarRelogio;
    checarMensagem = checarRelogio = examinar;

    void **acoesMensagem = malloc(sizeof(func));
    acoesMensagem[0] = checarMensagem;

    Elemento mensagem1 =
    criarElemento("Uma","Mensagem",
        "Na parede há uma mensagem: 1 + 1 = 2.",
        "Na parede está escrito com tinta vermelha (ou será sangue...?): 1 + 1 = 2.", False, False, NULL, 0, 0, NULL,
        acoesMensagem, NULL, unionVazia);

    /*+++++++++++++++++++chave+++++++++++++++++++*/

    Elemento chave1 =
    criarElemento("Uma","Chave",
        "Uma chave velha.",
        "Uma chave velha e enferrujada.", False, False, NULL, 0, 0, NULL,
        NULL, NULL, unionVazia);

    Elemento *conteudoConcha = malloc(sizeof(Elemento));
    conteudoConcha[0] = chave1;

    /*+++++++++++++++++++concha+++++++++++++++++++*/

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

    /*+++++++++++++++++++porta+++++++++++++++++++*/

    Elemento porta1 =
    criarElemento("Uma", "Porta",
        "Uma porta trancada.",
        "Uma porta de ferro com fechadura dourada.", False, False, NULL, 0, 0, NULL,
        NULL, NULL, unionVazia);

    /*++++++++++++ponteiro do relogio++++++++++++*/

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

    /*++++++++++++++++++relogio++++++++++++++++++*/

    void **acoesRelogio = malloc(sizeof(func));
    acoesRelogio[0] = checarRelogio;

    // transitividade das ações do relogio
    int *tRel = malloc(sizeof(int));
    tRel[0] = 1;

    Elemento relogio1 =
    criarElemento("Um","Relógio",
        "Relógio quebrado sem um dos ponteiros.",
        "Relógio sem o ponteiro dos minutos e com o ponteiro das horas apontando para o 8.",
        False, False, NULL, 0, 1, tRel, acoesRelogio, NULL, unionVazia);

    /*++++++++++++++++++sala 1++++++++++++++++++*/

    Info unionS1;

    Elemento *conteudoS1 = malloc(6*sizeof(Elemento));
    conteudoS1[0] = relogio1;
    conteudoS1[1] = ponteiro1;
    conteudoS1[2] = porta1;
    conteudoS1[3] = concha1;
    conteudoS1[4] = chave1;
    conteudoS1[5] = mensagem1;

    Elemento sala1 =
    criarElemento("Uma", "Fibonacci",
        "Uma sala empoeirada com cheiro de mofo.",
        "Uma sala empoeirada com cheiro de mofo. Há um relógio e um ponteiro no chão. Na parede está escrita uma mensagem e sob um pedestal há uma concha. Além disso, tem uma porta no fundo da sala.",
        False, False, conteudoS1, 6, 0, NULL,
        NULL, NULL, unionS1);

    return sala1;
}

/*
    Cria a segunda sala com todos os objetos.
    Retorna a sala criada.
*/
Elemento criarSala2() {
    /* --------------------------------------- SALA 2 --------------------------------------------- */
    /* .. ... ... --- -. .- --- . -.-. --- -.. .. --. --- -- --- .-. ... .
    0 0 0 0 0 0 0 0 1 1 1 1 0 0 1 1 1 1 0 1 0 1 0 1 1 1 1 0 0 0 0 1 1 0 1 1 1 1 1 1 1 1 0 1 0 0 0 0 0 */

    /*++++++++++++++++++mensagem++++++++++++++++++*/

    Elemento mensagem2 =
    criarElemento("Uma","Mensagem",
        "Está escrito: \".. ... ... --- -. .- --- . -.-. --- -.. .. --. --- -- --- .-. ... .\"",
        "Numa folha de papel amassada está escrito: \".. ... ... --- -. .- --- . -.-. --- -.. .. --. --- -- --- .-. ... .\"", False, False, NULL, 0, 0, NULL,
        NULL, NULL, unionVazia);

    /*+++++++++++++++++++porta+++++++++++++++++++*/

    Elemento porta2 =
    criarElemento("Uma", "Porta",
        "Uma porta.",
        "Uma porta dourada.", False, False, NULL, 0, 0, NULL,
        NULL, NULL, unionVazia);

    /*+++++++++++++++++++chave+++++++++++++++++++*/

    Elemento morsa2 =
    criarElemento("Uma","Pelúcia",
        "Uma morsa de pelúcia.",
        "Uma morsa de pelúcia marrom.", False, False, NULL, 0, 0, NULL,
        NULL, NULL, unionVazia);

    /*+++++++++++++++++++livro+++++++++++++++++++*/

    Elemento livro2 =
    criarElemento("Um","Livro",
        "Um livro velho. O título é \"Existem apenas -. tipos de pessoas no mundo\".",
        "Um livro velho e surpreendentemente grande. O título é \"Existem apenas 10 tipos de pessoas no mundo\".", False, False, NULL, 0, 0, NULL,
        NULL, NULL, unionVazia);

    /*++++++++++++++++++pagina++++++++++++++++++*/

    Elemento pagina2 =
    criarElemento("Uma","Página",
        "Você já tentou procurar embaixo do cofre?.",
        "Você já tentou procurar embaixo do cofre?.", False, False, NULL, 0, 0, NULL,
        NULL, NULL, unionVazia);

    /*+++++++++++++++++++cofre+++++++++++++++++++*/

    Elemento cofre2 =
    criarElemento("Um","Cofre",
        "Um cofre de ferro.",
        "Um cofre grande de ferro com uma fechadura mecânica.", False, False, NULL, 0, 0, NULL,
        NULL, NULL, unionVazia);

    /*+++++++++++++++++++letra+++++++++++++++++++*/

    Elemento letra2 =
    criarElemento("Um","Papel",
        "Há uma letra \"E\".",
        "Há uma letra \"E\".", False, False, NULL, 0, 0, NULL,
        NULL, NULL, unionVazia);

    /*++++++++++++++++++sala 2++++++++++++++++++*/

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
        "Uma sala com um cofre, livro, mensagem, pagina, morsa e porta aberta",
        False, False, conteudoS2, 6, 0, NULL,
        NULL, NULL, unionS2);

    return sala2;
}

Elemento criarSala3(){
    /* --------------------------------------- SALA 3 --------------------------------------------- */


    /* porta */

    Elemento porta3 =
    criarElemento("Uma", "Porta",
        "Uma porta.",
        "Uma porta de madeira.", False, False, NULL, 0, 0, 0,
        NULL, NULL, unionVazia);

    Elemento ovo3 = 
    criarElemento("Um", "Ovo",
        "Um ovo brilhante.",
        "Um ovo feito de aço.", False, False, NULL, 0, 0, 0,
        NULL, NULL, unionVazia);

    Elemento *conteudoGalinha3 = malloc(1*sizeof(Elemento));
    conteudoGalinha3[0] = ovo3;

    Elemento galinha3 =
    criarElemento("Uma", "Galinha",
        "Uma galinha branca.",
        "Uma galinha grande com penas brancas.", False, False, conteudoGalinha3, 0, 0, 0,
        NULL, NULL, unionVazia);

    Elemento *conteudoGaiola3 = malloc(1*sizeof(Elemento));
    conteudoGaiola3[0] = galinha3;

    Elemento gaiola3 =
    criarElemento("Uma", "Gaiola",
        "Uma gaiola dourada.",
        "Uma grande gaiola dourada. Há uma galinha presa nela?...", False, False, conteudoGaiola3, 0, 0, 0,
        NULL, NULL, unionVazia);

    Elemento metal3 =
    criarElemento("Um", "Metal",
        "Uma pequena barra de metal.",
        "Uma pequena barra de metal. Nela está gradado: \"Co\"", False, False, NULL, 0, 0, 0,
        NULL, NULL, unionVazia);

    Elemento bobina3 =
    criarElemento("Uma", "Bobina",
        "Uma grande bobina elétrica.",
        "Uma grande bobina elétrica. No centro há um buraco pequeno e na lateral um botão vermelho.", 
        False, False, NULL, 0, 0, 0,
        NULL, NULL, unionVazia);

    Elemento botao3 = 
    criarElemento("Um", "Botão",
        "Um botão vermelho.",
        "Um botão grande e vermelho.", False, False, NULL, 0, 0, 0,
        NULL, NULL, unionVazia);

    Elemento saco3 = 
    criarElemento("Um", "Saco",
        "Um saco com milho.",
        "Um saco de linho com milho.", False, False, NULL, 0, 0, 0,
        NULL, NULL, unionVazia);
    
    Elemento chave3 = 
    criarElemento("Uma", "Chave",
        "Uma chave dourada.",
        "Uma chave pequena e dourada.", False, False, NULL, 0, 0, 0,
        NULL, NULL, unionVazia);

    Info unionS3;

    Elemento *conteudoS3 = malloc(9*sizeof(Elemento));
    conteudoS3[0] = porta3;
    conteudoS3[1] = gaiola3;
    conteudoS3[2] = galinha3;
    conteudoS3[3] = ovo3;
    conteudoS3[4] = bobina3;
    conteudoS3[5] = botao3;
    conteudoS3[6] = metal3;
    conteudoS3[7] = saco3;
    conteudoS3[8] = chave3;
    
    Elemento sala3 =
    criarElemento("Uma","Galinhada",
        "Uma sala.",
        "Uma sala longa.",
        False, False, conteudoS3, 6, 0, NULL,
        NULL, NULL, unionS3);

    return sala3;
}

/*
    Cria a quarta sala com todos os objetos.
    Retorna a sala criada.
*/
Elemento criarSala4() {
    /*+++++++++++++++++mensagem+++++++++++++++++*/

    int *transitMsg = malloc(sizeof(int));
    transitMsg[0] = 1;

    func checarMensagem = examinar;
    void **acoesMsg = malloc(sizeof(func));
    acoesMsg[0] = checarMensagem;

    Elemento mensagem =
    criarElemento("A", "Mensagem",
        "Na parede há uma mensagem: acho que há pressão demais por aqui",
        "Na parede está escrito em azul: acho que há pressão demais por aqui",
        False, True, NULL, 0, 1, transitMsg,
        acoesMsg, NULL, unionVazia);

    /*+++++++++++++++++++poema+++++++++++++++++++*/

    int *transitPoema = malloc(sizeof(int));
    transitPoema[0] = 1;

    func checarPoema = examinar;    
    void **acoesPoema = malloc(sizeof(func));
    acoesPoema[0] = checarPoema;

    Elemento poema =
    criarElemento("O", "Poema",
        "Poema sem o sétimo verso.",
        "Poema escrito a tinta com uma caligrafia estranha. Está faltando o sétimo verso.",
        False, True, NULL, 0, 1, transitPoema,
        acoesPoema, NULL, unionVazia);

    /*+++++++++++++++++++blocos+++++++++++++++++++*/

    Elemento* blocos = malloc(10*sizeof(Elemento));

    for (int i = 0; i < 10; i++) {
        int *transitBloco = malloc(sizeof(int));
        transitBloco[0] = 2;

        func colocarBlocoSobre = colocarSobre;
        func tirarBlocoDeCima = tirarDeCima;
        void **acoesBloco = malloc(2*sizeof(func));
        acoesBloco[0] = colocarBlocoSobre;
        acoesBloco[1] = tirarBlocoDeCima;

        char numBloco[2];
        numBloco[0] = i + '0';
        numBloco[1] = '\0';

        char nomeBloco[10];
        char descCurta[50];
        char descLonga[50];

        strcpy(nomeBloco, "Bloco ");
        strcpy(descCurta, "Bloco com o número ");
        strcpy(descLonga, "Bloco empoeirado e com o número ");
        
        strcat(nomeBloco, numBloco);
        strcat(descCurta, numBloco);
        strcat(descLonga, numBloco);

        strcat(descCurta, ".");
        strcat(descLonga, " gravado.");

        Info unionBloco;
        unionBloco.atributos = malloc(sizeof(obj_atr));

        obj_atr estaNaBalanca;
        estaNaBalanca.nome = "estaNaBalanca";
        estaNaBalanca.valor.valor_estado = False;

        Elemento bloco =
        criarElemento("O", nomeBloco,
        descCurta,
        descLonga,
        False, True, NULL, 0, 1, transitBloco,
        acoesBloco, NULL, unionBloco);

        blocos[i] = bloco;
    }

    /*+++++++++++++++++balanca+++++++++++++++++*/

    Elemento balanca =
    criarElemento("A", "Balança",
        "Balança antiga.",
        "Balança um pouco enferrujada. Aparenta ser bem antiga.",
        False, True, NULL, 0, 0, NULL,
        NULL, NULL, unionVazia);

    /*+++++++++++++++++++sala 4+++++++++++++++++++*/

    Elemento* conteudoS4 = malloc(13*sizeof(Elemento));
    for (int i = 0; i < 10; i++) {
        conteudoS4[i] = blocos[i];
    }
    conteudoS4[10] = mensagem;
    conteudoS4[11] = poema;
    conteudoS4[12] = balanca;

    Info unionS4;

    Elemento sala4 =
    criarElemento("A", "Pascal",
    "Uma sala triangular.",
    "Uma sala triangular. Há uma mesa com blocos, um papel com um poema no chão, uma mensagem na parede e uma balança.",
    False, True, conteudoS4, 13, 0, NULL,
    NULL, NULL, unionS4);

    return sala4;
}

/* ####################################################### SALA 5 ######################################################################### */

Elemento criarSala5() {
    Elemento enigma = criarElemento("A", "mensagem", "O que o cientista disse quando encontrou 2 atomos de hélio? HeHe", "Um enigma",
    False, False, NULL, 0, 0, 0, NULL, NULL, unionVazia);

    Elemento mapa = criarElemento("O", "mapa", "Qual país está faltando?", "Um mapa do mundo faltando um país",
    False, False, NULL, 0, 0, 0, NULL, NULL, unionVazia);

    Elemento poster = criarElemento("O", "Poster", "Poster de Blade Runner",
    "Poster da cidade futurista de Los Angeles com muitas luzes, telões e carros voadores",
    False, False, NULL, 0 , 0, 0, NULL, NULL, unionVazia);

    Elemento caixadefosforo = criarElemento("A", "Caixa de Fósoforo", "Uma caixa de fósforo", "Uma caixa de fósforo", False, False, NULL, 0, 0, 0, NULL, NULL, unionVazia);

    Elemento lataderefri = criarElemento("A", "Lata de refrigerante", "Lata de refrigerante", "Lata de refrigerante", False, False, NULL, 0, 0, 0, NULL, NULL, unionVazia);

    Elemento porta = criarElemento("A", "Porta", "Porta", "Porta aberta", False, False, NULL, 0, 0, 0, NULL, NULL, unionVazia);

    Elemento *conteudoS5 = malloc(6*sizeof(Elemento));
    conteudoS5[0] = enigma;
    conteudoS5[1] = mapa;
    conteudoS5[2] = poster;
    conteudoS5[3] = caixadefosforo;
    conteudoS5[4] = lataderefri;
    conteudoS5[5] = porta;

    Elemento sala5 = criarElemento("A", "NePAl", "Salinha", "Tem um poster, uma caixa de fósforo e uma lata", 
    False, False, conteudoS5, 6, 0, 0, NULL, NULL, unionVazia);


    return sala5;
}