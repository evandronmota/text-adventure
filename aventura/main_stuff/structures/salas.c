#include <stdlib.h>
#include <stdio.h>
#include "../libraries/elemento.h"
#include "../libraries/salas.h"

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
    Imprime uma mensagem avisando que pegou o primeiro elemento.
    Retorna um inteiro indicando se a ação foi
    bem-sucedida.
*/
int pegar(Elemento *e1, Elemento *e2) {
    if (e1 == NULL)
        printf("Pegar o quê?\n");
    else 
        printf("Você pegou %s %s.", e1->artigo, e1->n);

    return (e1 == NULL ? 0 : 1);
}


/*
    Recebe os parâmetros necessários ao elemento.
    Cria um elemento com esses parâmetros.
    Retorna o elemento criado.
*/
Elemento criarElemento(char *artigo, char *nome, char *curta,
    char *longa, boolean visivel, boolean conhecido,
    Elemento *conteudo, int nEle, int nAcoes,
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
    novo.nAcoes = nAcoes;
    novo.transitividade = malloc(5*sizeof(int));
    novo.transitividade[0] = 1;
    novo.transitividade[1] = 1;
    novo.transitividade[2] = 1;

    novo.acoes = malloc(10*sizeof(func));
    novo.acoes[0] = examinar;
    novo.acoes[1] = pegar;
    /*novo.acoes[2] = largar;*/

    novo.animacao = animacao;
    novo.detalhe = detalhe;

    return novo;
}


/* Union para objetos sem atributos */
Info unionVazia;










/*
    Cria o salão principal do jogo com todos os elementos.
    Retorna a sala criada. 
*/
Elemento criarSala0() {
    Elemento porta1 =
    criarElemento("Uma", "Porta 1",
        "Uma porta de ferro.",
        "Uma porta de ferro com fechadura dourada.",
        False, False, NULL, 0, 0,
        NULL, unionVazia);

    Elemento porta2 =
    criarElemento("Uma", "Porta 2",
        "Uma porta dourada.",
        "Uma porta dourada muito velha.",
        False, False, NULL, 0, 0,
        NULL, unionVazia);

    Elemento porta3 =
    criarElemento("Uma", "Porta 3",
        "Uma porta de madeira.",
        "Uma porta de madeira de ébano.",
        False, False, NULL, 0, 0,
        NULL, unionVazia);

    Elemento porta4 =
    criarElemento("Uma", "Porta 4",
        "Uma porta branca.",
        "Uma porta branca cheia de lascas.",
        False, False, NULL, 0, 0,
        NULL, unionVazia);

    Elemento porta5 =
    criarElemento("Uma", "Porta 5",
        "Uma porta vermelha.",
        "Uma porta vermelha com fechadura preta.",
        False, False, NULL, 0, 0,
        NULL, unionVazia);

    Elemento glados =
    criarElemento("Um", "Robô",
        "Um robô com voz feminina.",
        "Um robô com voz feminina fala com você: \
        \n \"Olá, seja bem-vindo ao Aperture Science Computer-Aided Enrichment Center. Você poderia me dizer a senha?\"",
        False, False, NULL, 0, 0,
        NULL, unionVazia);

    Info unionS1;

    Elemento *conteudoS0 = malloc(6*sizeof(Elemento));
    conteudoS0[0] = porta1;
    conteudoS0[1] = porta2;
    conteudoS0[2] = porta3;
    conteudoS0[3] = porta4;
    conteudoS0[4] = porta5;
    conteudoS0[5] = glados;

    Elemento sala0 =
    criarElemento("Um", "Lobby",
        "Uma sala ampla com e circular.",
        "Uma sala ampla com e circular. No centro há um robô branco. Ele está olhando pra você...",
        False, False, conteudoS0, 6, 0,
        NULL, unionS1);

    return sala0;
}









/*
    Cria a primeira sala com todos os objetos.
    Retorna a sala criada.
*/
Elemento criarSala1() {
    /* ------------------------------------- SALA 1 ---------------------------------------------- */

    /* Mensagem */
    func checarMensagem, checarRelogio;
    checarMensagem = checarRelogio = examinar;

    Elemento mensagem =
    criarElemento("Uma","Mensagem",
        "Na parede há uma mensagem: 1 + 1 = 2.",
        "Na parede está escrito com tinta vermelha (ou será sangue...?): 1 + 1 = 2.",
        False, False, NULL, 0, 0,
        NULL, unionVazia);


    /* Chave */
    Elemento letra =
    criarElemento("Uma","Letra",
        "Uma letra A.",
        "Uma letra A de madeira.",
        False, False, NULL, 0, 0,
        NULL, unionVazia);

    Elemento *conteudoConcha = malloc(sizeof(Elemento));
    conteudoConcha[0] = letra;


    /* Concha */
    Info unionConcha;
    unionConcha.atributos = malloc(sizeof(obj_atr));

    obj_atr estaQuebrada;
    estaQuebrada.nome = "estaQuebrada";
    estaQuebrada.valor.valor_estado = False;

    unionConcha.atributos[0] = estaQuebrada;

    Elemento concha =
    criarElemento("Uma","Concha",
        "Uma concha em formato de espiral.",
        "Uma concha verde em formato de espiral.",
        False, False, conteudoConcha, 0, 0,
        NULL, unionConcha);


    /* Porta */
    Elemento porta =
    criarElemento("Uma", "Porta",
        "Uma porta trancada.",
        "Uma porta de ferro com fechadura dourada.",
        False, False, NULL, 0, 0,
        NULL, unionVazia);


    /* Ponteiro do relógio */
    Info unionPonteiro;
    unionPonteiro.atributos = malloc(sizeof(obj_atr));

    /*
        no chao = 0
        no relógio = 1
        com o aventureiro = 2
    */

    obj_atr comQuem;
    comQuem.nome = "comQuem";
    comQuem.valor.valor_num = 0;

    unionPonteiro.atributos[0] = comQuem;

    Elemento ponteiro = 
    criarElemento("Um", "Ponteiro",
        "Um ponteiro de relógio.",
        "Um ponteiro de minutos do relógio quebrado.",
        False, False, NULL, 0, 0,
        NULL, unionPonteiro);


    /* Relógio */
    Elemento relogio =
    criarElemento("Um","Relógio",
        "Relógio quebrado sem um dos ponteiros.",
        "Relógio sem o ponteiro dos minutos e com o ponteiro das horas apontando para o 8.",
        False, False, NULL, 0, 1, 
        NULL, unionVazia);


    /* Sala 1 */
    Info unionS1;

    Elemento *conteudoS1 = malloc(6*sizeof(Elemento));
    conteudoS1[0] = relogio;
    conteudoS1[1] = ponteiro;
    conteudoS1[2] = porta;
    conteudoS1[3] = concha;
    conteudoS1[4] = letra;
    conteudoS1[5] = mensagem;

    Elemento sala1 =
    criarElemento("Uma", "Fibonacci",
        "Uma sala empoeirada com cheiro de mofo.",
        "Uma sala empoeirada com cheiro de mofo. Há um relógio e um ponteiro no chão. Na parede está escrita uma mensagem e sob um pedestal há uma concha. Além disso, tem uma porta no fundo da sala.",
        False, False, conteudoS1, 6, 0,
        NULL, unionS1);

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
    Elemento mensagem =
    criarElemento("Uma","Mensagem",
        "Está escrito: \".. ... ... --- -. .- --- . -.-. --- -.. .. --. --- -- --- .-. ... .\"",
        "Numa folha de papel amassada está escrito: \".. ... ... --- -. .- --- . -.-. --- -.. .. --. --- -- --- .-. ... .\"", False, False, NULL, 0, 0,
        NULL, unionVazia);


    /* Porta */
    Elemento porta =
    criarElemento("Uma", "Porta",
        "Uma porta.",
        "Uma porta dourada.", 
        False, False, NULL, 0, 0,
        NULL, unionVazia);


    /* Morsa */
    Elemento morsa =
    criarElemento("Uma","Pelúcia",
        "Uma morsa de pelúcia.",
        "Uma morsa de pelúcia marrom.", 
        False, False, NULL, 0, 0,
        NULL, unionVazia);


    /* Livro */
    Elemento livro =
    criarElemento("Um","Livro",
        "Um livro velho. O título é \"Existem apenas -. tipos de pessoas no mundo\".",
        "Um livro velho e surpreendentemente grande. O título é \"Existem apenas 10 tipos de pessoas no mundo\".",
        False, False, NULL, 0, 0,
        NULL, unionVazia);


    /* Página */
    Elemento pagina =
    criarElemento("Uma","Página",
        "Você já tentou procurar embaixo do cofre?.",
        "Você já tentou procurar embaixo do cofre?.",
        False, False, NULL, 0, 0,
        NULL, unionVazia);


    /* Cofre */
    Elemento cofre =
    criarElemento("Um","Cofre",
        "Um cofre de ferro.",
        "Um cofre grande de ferro com uma fechadura mecânica.",
        False, False, NULL, 0, 0,
        NULL, unionVazia);


    /* Letra */
    Elemento letra =
    criarElemento("Uma","Letra",
        "Uma letra \"B\".",
        "Uma letra \"B\" de madeira.",
        False, False, NULL, 0, 0,
        NULL, unionVazia);


    /* Sala 2 */
    Info unionS2;

    Elemento *conteudoS2 = malloc(7*sizeof(Elemento));
    conteudoS2[0] = letra;
    conteudoS2[1] = cofre;
    conteudoS2[2] = livro;
    conteudoS2[3] = pagina;
    conteudoS2[4] = morsa;
    conteudoS2[5] = porta;
    conteudoS2[6] = mensagem;

    Elemento sala2 =
    criarElemento("Uma","Binaria",
        "Uma sala.",
        "Uma sala com um cofre, livro, mensagem, pagina, morsa e porta aberta",
        False, False, conteudoS2, 7, 0,
        NULL, unionS2);

    return sala2;
}











/*
    Cria a terceira sala com todos os objetos.
    Retorna a sala criada.
*/
Elemento criarSala3(){
    /* --------------------------------------- SALA 3 --------------------------------------------- */



    /* Porta */
    Elemento porta =
    criarElemento("Uma", "Porta",
        "Uma porta.",
        "Uma porta de madeira.",
        False, False, NULL, 0, 0,
        NULL, unionVazia);

    /* Letra */
    Elemento letra = 
    criarElemento("Uma", "Letra",
        "Uma letra \"R\".",
        "Uma letra \"R\".",
        False, False, NULL, 0, 0,
        NULL, unionVazia);

    Elemento *conteudoOvo = malloc(1*sizeof(Elemento));
    conteudoOvo[0] = letra;

    /* Ovo */
    Elemento ovo = 
    criarElemento("Um", "Ovo",
        "Um ovo brilhante.",
        "Um ovo feito de aço.",
        False, False, conteudoOvo, 0, 0,
        NULL, unionVazia);

    /* Galinha */
    Elemento *conteudoGalinha = malloc(1*sizeof(Elemento));
    conteudoGalinha[0] = ovo;

    Elemento galinha =
    criarElemento("Uma", "Galinha",
        "Uma galinha branca.",
        "Uma galinha grande com penas brancas.",
        False, False, conteudoGalinha, 0, 0,
        NULL, unionVazia);

    /* Gaiola */
    Elemento *conteudoGaiola = malloc(1*sizeof(Elemento));
    conteudoGaiola[0] = galinha;

    Elemento gaiola =
    criarElemento("Uma", "Gaiola",
        "Uma gaiola dourada.",
        "Uma grande gaiola dourada. Há uma galinha presa nela?...",
        False, False, conteudoGaiola, 0, 0,
        NULL, unionVazia);

    /* Metal */
    Elemento metal =
    criarElemento("Um", "Metal",
        "Uma pequena barra de metal.",
        "Uma pequena barra de metal. Nela está gradado: \"Co\"",
        False, False, NULL, 0, 0,
        NULL, unionVazia);

    /* Bobina */
    Elemento bobina =
    criarElemento("Uma", "Bobina",
        "Uma grande bobina elétrica.",
        "Uma grande bobina elétrica. No centro há um buraco pequeno e na lateral um botão vermelho.",
        False, False, NULL, 0, 0,
        NULL, unionVazia);

    /* Botão */
    Elemento botao = 
    criarElemento("Um", "Botão",
        "Um botão vermelho.",
        "Um botão grande e vermelho.",
        False, False, NULL, 0, 0,
        NULL, unionVazia);

    /* Saco */
    Elemento saco = 
    criarElemento("Um", "Saco",
        "Um saco com milho.",
        "Um saco de linho com milho.",
        False, False, NULL, 0, 0,
        NULL, unionVazia);

    /* Chave */
    Elemento chave = 
    criarElemento("Uma", "Chave",
        "Uma chave dourada.",
        "Uma chave pequena e dourada.",
        False, False, NULL, 0, 0,
        NULL, unionVazia);

    /* Sala 3 */
    Info unionS3;

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
    criarElemento("Uma","Galinhada",
        "Uma sala.",
        "Uma sala longa.",
        False, False, conteudoS3, 10, 0,
        NULL, unionS3);

    return sala3;
}
















/*
    Cria a quarta sala com todos os objetos.
    Retorna a sala criada.
*/
Elemento criarSala4() {

    /* ------------------------------------- SALA 4 ---------------------------------------------- */

    /* Mensagem */
    Elemento mensagem =
    criarElemento("A", "Mensagem",
        "Na parede há uma mensagem: acho que há pressão demais por aqui",
        "Na parede está escrito em azul: acho que há pressão demais por aqui",
        False, True, NULL, 0, 1,
        NULL, unionVazia);


    /* Poema */
    Elemento poema =
    criarElemento("O", "Poema",
        "Poema sem o sétimo verso.",
        "Poema escrito a tinta com uma caligrafia estranha. Está faltando o sétimo verso.",
        False, True, NULL, 0, 1,
        NULL, unionVazia);


    /* Blocos */
    obj_atr estaNaBalanca;
    estaNaBalanca.nome = "estaNaBalanca";
    estaNaBalanca.valor.valor_estado = False;

    func colocarBlocoSobre = colocarSobre;
    func tirarBlocoDeCima = pegar;



    /* Bloco 0 */
    Info unionBloco0;
    unionBloco0.atributos = malloc(sizeof(obj_atr));
    unionBloco0.atributos[0] = estaNaBalanca;

    Elemento bloco0 =
    criarElemento("O", "Bloco 0",
        "Bloco com o número 0.",
        "Bloco empoeirado e com o número 0 gravado.",
        False, True, NULL, 0, 1,
        NULL, unionBloco0);

    bloco0.acoes = realloc(bloco0.acoes, 5*sizeof(func));
    bloco0.acoes[3] = colocarBlocoSobre;
    bloco0.acoes[4] = tirarBlocoDeCima;

    bloco0.transitividade = realloc(bloco0.transitividade, 5*sizeof(int));
    bloco0.transitividade[3] = 2;
    bloco0.transitividade[4] = 2;



    /* Bloco 1 */
    Info unionBloco1;
    unionBloco1.atributos = malloc(sizeof(obj_atr));
    unionBloco1.atributos[0] = estaNaBalanca;

    Elemento bloco1 =
    criarElemento("O", "Bloco 1",
        "Bloco com o número 1.",
        "Bloco empoeirado e com o número 1 gravado.",
        False, True, NULL, 0, 1,
        NULL, unionBloco1);
    
    bloco1.acoes = realloc(bloco1.acoes, 5*sizeof(func));
    bloco1.acoes[3] = colocarBlocoSobre;
    bloco1.acoes[4] = tirarBlocoDeCima;

    bloco1.transitividade = realloc(bloco1.transitividade, 5*sizeof(int));
    bloco1.transitividade[3] = 2;
    bloco1.transitividade[4] = 2;
    


    /* Bloco 2 */
    Info unionBloco2;
    unionBloco2.atributos = malloc(sizeof(obj_atr));
    unionBloco2.atributos[0] = estaNaBalanca;

    Elemento bloco2 =
    criarElemento("O", "Bloco 2",
        "Bloco com o número 2.",
        "Bloco empoeirado e com o número 2 gravado.",
        False, True, NULL, 0, 1,
        NULL, unionBloco2);

    bloco2.acoes = realloc(bloco2.acoes, 5*sizeof(func));
    bloco2.acoes[3] = colocarBlocoSobre;
    bloco2.acoes[4] = tirarBlocoDeCima;

    bloco2.transitividade = realloc(bloco2.transitividade, 5*sizeof(int));
    bloco2.transitividade[3] = 2;
    bloco2.transitividade[4] = 2;



    /* Bloco 3 */
    Info unionBloco3;
    unionBloco3.atributos = malloc(sizeof(obj_atr));
    unionBloco3.atributos[0] = estaNaBalanca;

    Elemento bloco3 =
    criarElemento("O", "Bloco 3",
        "Bloco com o número 3.",
        "Bloco empoeirado e com o número 3 gravado.",
        False, True, NULL, 0, 1,
        NULL, unionBloco3);

    bloco3.acoes = realloc(bloco3.acoes, 5*sizeof(func));
    bloco3.acoes[3] = colocarBlocoSobre;
    bloco3.acoes[4] = tirarBlocoDeCima;

    bloco3.transitividade = realloc(bloco3.transitividade, 5*sizeof(int));
    bloco3.transitividade[3] = 2;
    bloco3.transitividade[4] = 2;



    /* Bloco 4 */
    Info unionBloco4;
    unionBloco4.atributos = malloc(sizeof(obj_atr));
    unionBloco4.atributos[0] = estaNaBalanca;

    Elemento bloco4 =
    criarElemento("O", "Bloco 4",
        "Bloco com o número 4.",
        "Bloco empoeirado e com o número 4 gravado.",
        False, True, NULL, 0, 1,
        NULL, unionBloco4);

    bloco4.acoes = realloc(bloco4.acoes, 5*sizeof(func));
    bloco4.acoes[3] = colocarBlocoSobre;
    bloco4.acoes[4] = tirarBlocoDeCima;

    bloco4.transitividade = realloc(bloco4.transitividade, 5*sizeof(int));
    bloco4.transitividade[3] = 2;
    bloco4.transitividade[4] = 2;



    /* Bloco 5 */
    Info unionBloco5;
    unionBloco5.atributos = malloc(sizeof(obj_atr));
    unionBloco5.atributos[0] = estaNaBalanca;

    Elemento bloco5 =
    criarElemento("O", "Bloco 5",
        "Bloco com o número 5.",
        "Bloco empoeirado e com o número 5 gravado.",
        False, True, NULL, 0, 1,
        NULL, unionBloco5);

    bloco5.acoes = realloc(bloco5.acoes, 5*sizeof(func));
    bloco5.acoes[3] = colocarBlocoSobre;
    bloco5.acoes[4] = tirarBlocoDeCima;

    bloco5.transitividade = realloc(bloco5.transitividade, 5*sizeof(int));
    bloco5.transitividade[3] = 2;
    bloco5.transitividade[4] = 2;



    /* Bloco 6 */
    Info unionBloco6;
    unionBloco6.atributos = malloc(sizeof(obj_atr));
    unionBloco6.atributos[0] = estaNaBalanca;

    Elemento bloco6 =
    criarElemento("O", "Bloco 6",
        "Bloco com o número 6.",
        "Bloco empoeirado e com o número 6 gravado.",
        False, True, NULL, 0, 1,
        NULL, unionBloco6);

    bloco6.acoes = realloc(bloco6.acoes, 5*sizeof(func));
    bloco6.acoes[3] = colocarBlocoSobre;
    bloco6.acoes[4] = tirarBlocoDeCima;

    bloco6.transitividade = realloc(bloco6.transitividade, 5*sizeof(int));
    bloco6.transitividade[3] = 2;
    bloco6.transitividade[4] = 2;



    /* Bloco 7 */
    Info unionBloco7;
    unionBloco7.atributos = malloc(sizeof(obj_atr));
    unionBloco7.atributos[0] = estaNaBalanca;

    Elemento bloco7 =
    criarElemento("O", "Bloco 7",
        "Bloco com o número 7.",
        "Bloco empoeirado e com o número 7 gravado.",
        False, True, NULL, 0, 1,
        NULL, unionBloco7);

    bloco7.acoes = realloc(bloco7.acoes, 5*sizeof(func));
    bloco7.acoes[3] = colocarBlocoSobre;
    bloco7.acoes[4] = tirarBlocoDeCima;

    bloco7.transitividade = realloc(bloco7.transitividade, 5*sizeof(int));
    bloco7.transitividade[3] = 2;
    bloco7.transitividade[4] = 2;



    /* Bloco 8 */
    Info unionBloco8;
    unionBloco8.atributos = malloc(sizeof(obj_atr));
    unionBloco8.atributos[0] = estaNaBalanca;

    Elemento bloco8 =
    criarElemento("O", "Bloco 8",
        "Bloco com o número 8.",
        "Bloco empoeirado e com o número 8 gravado.",
        False, True, NULL, 0, 1,
        NULL, unionBloco8);

    bloco8.acoes = realloc(bloco8.acoes, 5*sizeof(func));
    bloco8.acoes[3] = colocarBlocoSobre;
    bloco8.acoes[4] = tirarBlocoDeCima;

    bloco8.transitividade = realloc(bloco8.transitividade, 5*sizeof(int));
    bloco8.transitividade[3] = 2;
    bloco8.transitividade[4] = 2;



    /* Bloco 9 */
    Info unionBloco9;
    unionBloco9.atributos = malloc(sizeof(obj_atr));
    unionBloco9.atributos[0] = estaNaBalanca;

    Elemento bloco9 =
    criarElemento("O", "Bloco 9",
        "Bloco com o número 9.",
        "Bloco empoeirado e com o número 9 gravado.",
        False, True, NULL, 0, 1,
        NULL, unionBloco9);

    bloco9.acoes = realloc(bloco9.acoes, 5*sizeof(func));
    bloco9.acoes[3] = colocarBlocoSobre;
    bloco9.acoes[4] = tirarBlocoDeCima;

    bloco9.transitividade = realloc(bloco9.transitividade, 5*sizeof(int));
    bloco9.transitividade[3] = 2;
    bloco9.transitividade[4] = 2;

    /* Porta */
    Elemento porta =
    criarElemento("Uma", "Porta",
        "Uma porta branca.",
        "Uma porta branca com várias lascas.", 
        False, True, NULL, 0, 0,
        NULL, unionVazia);


    /* Balança */
    Elemento balanca =
    criarElemento("A", "Balança",
        "Balança antiga.",
        "Balança um pouco enferrujada. Aparenta ser bem antiga.",
        False, True, NULL, 0, 0,
        NULL, unionVazia);




    /* Sala 4 */
    Elemento* conteudoS4 = malloc(14*sizeof(Elemento));
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
    conteudoS4[13] = porta;

    Info unionS4;

    Elemento sala4 =
    criarElemento("A", "Pascal",
    "Uma sala triangular.",
    "Uma sala triangular. Há uma mesa com blocos, um papel com um poema no chão, uma mensagem na parede e uma balança.",
    False, True, conteudoS4, 14, 0,
    NULL, unionS4);

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
    Elemento enigma =
    criarElemento("A", "mensagem",
        "O que o cientista disse quando encontrou 2 atomos de hélio? HeHe",
        "Um enigma",
        False, False, NULL, 0, 1,
        NULL, unionVazia);






    /* Mapa */
    Elemento mapa =
    criarElemento("O", "mapa",
        "Qual país está faltando?",
        "Um mapa do mundo faltando um país",
        False, False, NULL, 0, 1,
        NULL, unionVazia);






    /* Poster */
    Elemento poster =
    criarElemento("O", "Poster",
        "Poster de Blade Runner",
        "Poster da cidade futurista de Los Angeles com muitas luzes, telões e carros voadores",
        False, False, NULL, 0 , 1,
        NULL, unionVazia);








    /* Caixa de fósforo */
    Elemento caixadefosforo =
    criarElemento("A", "Caixa de Fósoforo",
        "Uma caixa de fósforo",
        "Uma caixa de fósforo",
        False, False, NULL, 0, 1,
        NULL, unionVazia);






    /* Lata de refrigerante */
    Elemento lataderefri =
    criarElemento("A", "Lata de refrigerante",
        "Lata de refrigerante",
        "Lata de refrigerante",
        False, False, NULL, 0, 1,
        NULL, unionVazia);






    /* Porta */
    Elemento porta =
    criarElemento("A", "Porta",
        "Uma porta vermelha.",
        "Uma porta vermelha com fechadura preta.",
        False, False, NULL, 0, 1,
        NULL, unionVazia);






    /* Sala 5 */
    Elemento *conteudoS5 = malloc(6*sizeof(Elemento));
    conteudoS5[0] = enigma;
    conteudoS5[1] = mapa;
    conteudoS5[2] = poster;
    conteudoS5[3] = caixadefosforo;
    conteudoS5[4] = lataderefri;
    conteudoS5[5] = porta;

    Elemento sala5 =
    criarElemento("A", "NePAl",
        "Salinha",
        "Tem um poster, uma caixa de fósforo e uma lata", 
        False, False, conteudoS5, 6, 0,
        NULL, unionVazia);

    return sala5;
}
