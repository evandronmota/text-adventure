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


    if (e1 == NULL) /* Verbo intransitivo */
        printf("Examinar o quê?\n");
    else if (e1->conhecido)
        printf("%s\n", e1->curta);
    else {
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

/*
    Recebe dois ponteiros para elementos.
    Imprime uma mensagem avisando que o primeiro
    elemento foi retirado de cima do segundo.
    Retorna um inteiro indicando se a ação foi
    bem-sucedida.
*/
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

/* Union para objetos sem atributos */
Info unionVazia;













/*
    Cria a primeira sala com todos os objetos.
    Retorna a sala criada.
*/
Elemento criarSala1() {
    /* ------------------------------------- SALA 1 ---------------------------------------------- */

    /* Mensagem */
    func checarMensagem, checarRelogio;
    checarMensagem = checarRelogio = examinar;

    void **acoesMensagem = malloc(sizeof(func));
    acoesMensagem[0] = checarMensagem;

    Elemento mensagem1 =
    criarElemento("Uma","Mensagem",
        "Na parede há uma mensagem: 1 + 1 = 2.",
        "Na parede está escrito com tinta vermelha (ou será sangue...?): 1 + 1 = 2.", False, False, NULL, 0, 0, NULL,
        acoesMensagem, NULL, unionVazia);


    /* Chave */
    Elemento chave1 =
    criarElemento("Uma","Chave",
        "Uma chave velha.",
        "Uma chave velha e enferrujada.", False, False, NULL, 0, 0, NULL,
        NULL, NULL, unionVazia);

    Elemento *conteudoConcha = malloc(sizeof(Elemento));
    conteudoConcha[0] = chave1;


    /* Concha */
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


    /* Porta */
    Elemento porta1 =
    criarElemento("Uma", "Porta",
        "Uma porta trancada.",
        "Uma porta de ferro com fechadura dourada.", False, False, NULL, 0, 0, NULL,
        NULL, NULL, unionVazia);


    /* Ponteiro do relógio */
    Info unionPonteiro1;
    unionPonteiro1.atributos = malloc(sizeof(obj_atr));

    /*
        no chao = 0
        no relógio = 1
        com o aventureiro = 2
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


    /* Relógio */
    void **acoesRelogio = malloc(sizeof(func));
    acoesRelogio[0] = checarRelogio;

    /* Transitividade das ações do relogio */
    int *tRel = malloc(sizeof(int));
    tRel[0] = 1;

    Elemento relogio1 =
    criarElemento("Um","Relógio",
        "Relógio quebrado sem um dos ponteiros.",
        "Relógio sem o ponteiro dos minutos e com o ponteiro das horas apontando para o 8.",
        False, False, NULL, 0, 1, tRel, acoesRelogio, NULL, unionVazia);


    /* Sala 1 */
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


    /* Mensagem */
    Elemento mensagem2 =
    criarElemento("Uma","Mensagem",
        "Está escrito: \".. ... ... --- -. .- --- . -.-. --- -.. .. --. --- -- --- .-. ... .\"",
        "Numa folha de papel amassada está escrito: \".. ... ... --- -. .- --- . -.-. --- -.. .. --. --- -- --- .-. ... .\"", False, False, NULL, 0, 0, NULL,
        NULL, NULL, unionVazia);


    /* Porta */
    Elemento porta2 =
    criarElemento("Uma", "Porta",
        "Uma porta.",
        "Uma porta dourada.", False, False, NULL, 0, 0, NULL,
        NULL, NULL, unionVazia);


    /* Morsa */
    Elemento morsa2 =
    criarElemento("Uma","Pelúcia",
        "Uma morsa de pelúcia.",
        "Uma morsa de pelúcia marrom.", False, False, NULL, 0, 0, NULL,
        NULL, NULL, unionVazia);


    /* Livro */
    Elemento livro2 =
    criarElemento("Um","Livro",
        "Um livro velho. O título é \"Existem apenas -. tipos de pessoas no mundo\".",
        "Um livro velho e surpreendentemente grande. O título é \"Existem apenas 10 tipos de pessoas no mundo\".", False, False, NULL, 0, 0, NULL,
        NULL, NULL, unionVazia);


    /* Página */
    Elemento pagina2 =
    criarElemento("Uma","Página",
        "Você já tentou procurar embaixo do cofre?.",
        "Você já tentou procurar embaixo do cofre?.", False, False, NULL, 0, 0, NULL,
        NULL, NULL, unionVazia);


    /* Cofre */
    Elemento cofre2 =
    criarElemento("Um","Cofre",
        "Um cofre de ferro.",
        "Um cofre grande de ferro com uma fechadura mecânica.", False, False, NULL, 0, 0, NULL,
        NULL, NULL, unionVazia);


    /* Letra */
    Elemento letra2 =
    criarElemento("Um","Papel",
        "Há uma letra \"E\".",
        "Há uma letra \"E\".", False, False, NULL, 0, 0, NULL,
        NULL, NULL, unionVazia);


    /* Sala 2 */
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











/*
    Cria a terceira sala com todos os objetos.
    Retorna a sala criada.
*/
Elemento criarSala3(){
    /* --------------------------------------- SALA 3 --------------------------------------------- */



    /* Porta */
    Elemento porta3 =
    criarElemento("Uma", "Porta",
        "Uma porta.",
        "Uma porta de madeira.", False, False, NULL, 0, 0, 0,
        NULL, NULL, unionVazia);

    /* Ovo */
    Elemento ovo3 = 
    criarElemento("Um", "Ovo",
        "Um ovo brilhante.",
        "Um ovo feito de aço.", False, False, NULL, 0, 0, 0,
        NULL, NULL, unionVazia);

    /* Galinha */
    Elemento *conteudoGalinha3 = malloc(1*sizeof(Elemento));
    conteudoGalinha3[0] = ovo3;

    Elemento galinha3 =
    criarElemento("Uma", "Galinha",
        "Uma galinha branca.",
        "Uma galinha grande com penas brancas.", False, False, conteudoGalinha3, 0, 0, 0,
        NULL, NULL, unionVazia);

    /* Gaiola */
    Elemento *conteudoGaiola3 = malloc(1*sizeof(Elemento));
    conteudoGaiola3[0] = galinha3;

    Elemento gaiola3 =
    criarElemento("Uma", "Gaiola",
        "Uma gaiola dourada.",
        "Uma grande gaiola dourada. Há uma galinha presa nela?...", False, False, conteudoGaiola3, 0, 0, 0,
        NULL, NULL, unionVazia);

    /* Metal */
    Elemento metal3 =
    criarElemento("Um", "Metal",
        "Uma pequena barra de metal.",
        "Uma pequena barra de metal. Nela está gradado: \"Co\"", False, False, NULL, 0, 0, 0,
        NULL, NULL, unionVazia);

    /* Bobina */
    Elemento bobina3 =
    criarElemento("Uma", "Bobina",
        "Uma grande bobina elétrica.",
        "Uma grande bobina elétrica. No centro há um buraco pequeno e na lateral um botão vermelho.", 
        False, False, NULL, 0, 0, 0,
        NULL, NULL, unionVazia);

    /* Botão */
    Elemento botao3 = 
    criarElemento("Um", "Botão",
        "Um botão vermelho.",
        "Um botão grande e vermelho.", False, False, NULL, 0, 0, 0,
        NULL, NULL, unionVazia);

    /* Saco */
    Elemento saco3 = 
    criarElemento("Um", "Saco",
        "Um saco com milho.",
        "Um saco de linho com milho.", False, False, NULL, 0, 0, 0,
        NULL, NULL, unionVazia);

    /* Chave */
    Elemento chave3 = 
    criarElemento("Uma", "Chave",
        "Uma chave dourada.",
        "Uma chave pequena e dourada.", False, False, NULL, 0, 0, 0,
        NULL, NULL, unionVazia);

    /* Sala 3 */
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

    /* ------------------------------------- SALA 4 ---------------------------------------------- */

    /* Mensagem */
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


    /* Poema */
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


    /* Blocos */
    func colocarBlocoSobre = colocarSobre;
    func tirarBlocoDeCima = tirarDeCima;
    void **acoesBloco = malloc(2*sizeof(func));
    acoesBloco[0] = colocarBlocoSobre;
    acoesBloco[1] = tirarBlocoDeCima;

    int *transitBloco = malloc(sizeof(int));
    transitBloco[0] = 2;

    obj_atr estaNaBalanca;
    estaNaBalanca.nome = "estaNaBalanca";
    estaNaBalanca.valor.valor_estado = False;

    /* Bloco 0 */
    Info unionBloco0;
    unionBloco0.atributos = malloc(sizeof(obj_atr));
    unionBloco0.atributos[0] = estaNaBalanca;

    Elemento bloco0 =
    criarElemento("O", "Bloco 0",
    "Bloco com o número 0.",
    "Bloco empoeirado e com o número 0 gravado.",
    False, True, NULL, 0, 1, transitBloco,
    acoesBloco, NULL, unionBloco0);

    /* Bloco 1 */
    Info unionBloco1;
    unionBloco1.atributos = malloc(sizeof(obj_atr));
    unionBloco1.atributos[0] = estaNaBalanca;

    Elemento bloco1 =
    criarElemento("O", "Bloco 1",
    "Bloco com o número 1.",
    "Bloco empoeirado e com o número 1 gravado.",
    False, True, NULL, 0, 1, transitBloco,
    acoesBloco, NULL, unionBloco1);

    /* Bloco 2 */
    Info unionBloco2;
    unionBloco2.atributos = malloc(sizeof(obj_atr));
    unionBloco2.atributos[0] = estaNaBalanca;

    Elemento bloco2 =
    criarElemento("O", "Bloco 2",
    "Bloco com o número 2.",
    "Bloco empoeirado e com o número 2 gravado.",
    False, True, NULL, 0, 1, transitBloco,
    acoesBloco, NULL, unionBloco2);

    /* Bloco 3 */
    Info unionBloco3;
    unionBloco3.atributos = malloc(sizeof(obj_atr));
    unionBloco3.atributos[0] = estaNaBalanca;

    Elemento bloco3 =
    criarElemento("O", "Bloco 3",
    "Bloco com o número 3.",
    "Bloco empoeirado e com o número 3 gravado.",
    False, True, NULL, 0, 1, transitBloco,
    acoesBloco, NULL, unionBloco3);

    /* Bloco 4 */
    Info unionBloco4;
    unionBloco4.atributos = malloc(sizeof(obj_atr));
    unionBloco4.atributos[0] = estaNaBalanca;

    Elemento bloco4 =
    criarElemento("O", "Bloco 4",
    "Bloco com o número 4.",
    "Bloco empoeirado e com o número 4 gravado.",
    False, True, NULL, 0, 1, transitBloco,
    acoesBloco, NULL, unionBloco4);

    /* Bloco 5 */
    Info unionBloco5;
    unionBloco5.atributos = malloc(sizeof(obj_atr));
    unionBloco5.atributos[0] = estaNaBalanca;

    Elemento bloco5 =
    criarElemento("O", "Bloco 5",
    "Bloco com o número 5.",
    "Bloco empoeirado e com o número 5 gravado.",
    False, True, NULL, 0, 1, transitBloco,
    acoesBloco, NULL, unionBloco5);

    /* Bloco 6 */
    Info unionBloco6;
    unionBloco6.atributos = malloc(sizeof(obj_atr));
    unionBloco6.atributos[0] = estaNaBalanca;

    Elemento bloco6 =
    criarElemento("O", "Bloco 6",
    "Bloco com o número 6.",
    "Bloco empoeirado e com o número 6 gravado.",
    False, True, NULL, 0, 1, transitBloco,
    acoesBloco, NULL, unionBloco6);

    /* Bloco 7 */
    Info unionBloco7;
    unionBloco7.atributos = malloc(sizeof(obj_atr));
    unionBloco7.atributos[0] = estaNaBalanca;

    Elemento bloco7 =
    criarElemento("O", "Bloco 7",
    "Bloco com o número 7.",
    "Bloco empoeirado e com o número 7 gravado.",
    False, True, NULL, 0, 1, transitBloco,
    acoesBloco, NULL, unionBloco7);

    /* Bloco 8 */
    Info unionBloco8;
    unionBloco8.atributos = malloc(sizeof(obj_atr));
    unionBloco8.atributos[0] = estaNaBalanca;

    Elemento bloco8 =
    criarElemento("O", "Bloco 8",
    "Bloco com o número 8.",
    "Bloco empoeirado e com o número 8 gravado.",
    False, True, NULL, 0, 1, transitBloco,
    acoesBloco, NULL, unionBloco8);

    /* Bloco 9 */
    Info unionBloco9;
    unionBloco9.atributos = malloc(sizeof(obj_atr));
    unionBloco9.atributos[0] = estaNaBalanca;

    Elemento bloco9 =
    criarElemento("O", "Bloco 9",
    "Bloco com o número 9.",
    "Bloco empoeirado e com o número 9 gravado.",
    False, True, NULL, 0, 1, transitBloco,
    acoesBloco, NULL, unionBloco9);



    /* Balança */
    Elemento balanca =
    criarElemento("A", "Balança",
        "Balança antiga.",
        "Balança um pouco enferrujada. Aparenta ser bem antiga.",
        False, True, NULL, 0, 0, NULL,
        NULL, NULL, unionVazia);




    /* Sala 4 */
    Elemento* conteudoS4 = malloc(13*sizeof(Elemento));
    conteudoS4[0] = bloco0;
    conteudoS4[1] = bloco1;
    conteudoS4[2] = bloco2;
    conteudoS4[3] = bloco3;
    conteudoS4[4] = bloco4;
    conteudoS4[5] = bloco5;
    conteudoS4[6] = bloco6;
    conteudoS4[7] = bloco7;
    conteudoS4[8] = bloco8;
    conteudoS4[9] = bloco9;
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









/*
    Cria a quinta sala com todos os objetos.
    Retorna a sala criada.
*/
Elemento criarSala5() {

    /* ------------------------------------- SALA 5 ---------------------------------------------- */

    func checarEnigma, checarMapa, checarPoster, checarCaixa, checarLata, checarPorta;
    checarEnigma = checarMapa = checarPoster = checarCaixa = checarLata = checarPorta = examinar;




    /* Enigma */

    void **acoesEnigma = malloc(sizeof(func));
    acoesEnigma[0] = checarEnigma;

    /* Transitividade das ações do Enigma */
    int *tEnigma = malloc(sizeof(int));
    tEnigma[0] = 1;

    Elemento enigma = criarElemento("A", "mensagem", "O que o cientista disse quando encontrou 2 atomos de hélio? HeHe",
    "Um enigma", False, False, NULL, 0, 1, tEnigma, acoesEnigma, NULL, unionVazia);






    /* Mapa */

    void **acoesMapa = malloc(sizeof(func));
    acoesMapa[0] = checarMapa;

    /* Transitividade das ações do Mapa */
    int *tMapa = malloc(sizeof(int));
    tMapa[0] = 1;

    Elemento mapa = criarElemento("O", "mapa", "Qual país está faltando?", "Um mapa do mundo faltando um país",
    False, False, NULL, 0, 1, tMapa, acoesMapa, NULL, unionVazia);






    /* Poster */

    void **acoesPoster = malloc(sizeof(func));
    acoesPoster[0] = checarPoster;

    /* Transitividade das ações do Poster */
    int *tPoster = malloc(sizeof(int));
    tPoster[0] = 1;

    Elemento poster = criarElemento("O", "Poster", "Poster de Blade Runner",
    "Poster da cidade futurista de Los Angeles com muitas luzes, telões e carros voadores",
    False, False, NULL, 0 , 1, tPoster, acoesPoster, NULL, unionVazia);








    /* Caixa de fósforo */

    void **acoesCaixa = malloc(sizeof(func));
    acoesCaixa[0] = checarCaixa;

    /* Transitividade das ações do Caixa */
    int *tCaixa = malloc(sizeof(int));
    tCaixa[0] = 1;

    Elemento caixadefosforo = criarElemento("A", "Caixa de Fósoforo", "Uma caixa de fósforo", "Uma caixa de fósforo",
    False, False, NULL, 0, 1, tCaixa, acoesCaixa, NULL, unionVazia);






    /* Lata de refrigerante */

    void **acoesLata = malloc(sizeof(func));
    acoesLata[0] = checarLata;

    /* Transitividade das ações do Lata */
    int *tLata = malloc(sizeof(int));
    tLata[0] = 1;

    Elemento lataderefri = criarElemento("A", "Lata de refrigerante", "Lata de refrigerante", "Lata de refrigerante",
    False, False, NULL, 0, 1, tLata, acoesLata, NULL, unionVazia);






    /* Porta */

    void **acoesPorta = malloc(sizeof(func));
    acoesPorta[0] = checarPorta;

    /* Transitividade das ações do Porta */
    int *tPorta = malloc(sizeof(int));
    tPorta[0] = 1;

    Elemento porta = criarElemento("A", "Porta", "Porta", "Porta aberta",
    False, False, NULL, 0, 1, tPorta, acoesPorta, NULL, unionVazia);






    /* Sala 5 */
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