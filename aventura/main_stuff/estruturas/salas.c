#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/elemento.h"
#include "../headers/aventureiro.h"
#include "../headers/salas.h"


void adicionarAcao(Elemento *e, func acao, int transitividade) {
    e->nAcoes++;
    e->acoes = realloc(e->acoes, e->nAcoes * sizeof(func));
    e->acoes[e->nAcoes - 1] = acao;

    e->transitividade = realloc(e->transitividade, e->nAcoes * sizeof(int));
    e->transitividade[e->nAcoes - 1] = transitividade;
}

void adicionarAtributo(Elemento *e, obj_atr atributo) {
    e->nAtr++;
    e->detalhe.atributos = realloc(e->detalhe.atributos, e->nAtr * sizeof(obj_atr));
    e->detalhe.atributos[e->nAtr - 1] = atributo;
}

void adicionarElemento(Elemento *e1, Elemento *destino) {
    destino->nEle++;
    destino->conteudo = realloc(destino->conteudo, destino->nEle * sizeof(Elemento));
    destino->conteudo[destino->nEle - 1] = *e1;
}


/*
    Recebe os parâmetros necessários ao elemento.
    Cria um elemento com esses parâmetros.
    Retorna o elemento criado.
*/
Elemento criarElemento(boolean isObjeto, char *artigo, char *nome, char *curta,
    char *longa, Elemento *conteudo, int nEle) {

    Elemento novo;
    novo.artigo = artigo;
    novo.n = nome;
    novo.curta = curta;
    novo.longa = longa;
    novo.ativo = True; /* Todos objetos começam ativos */
    novo.visivel = True; /* Por padrão os elementos começam visiveis */
    novo.conhecido = False; /* Todos objetos começam desconhecidos */
    novo.conteudo = conteudo;
    novo.nEle = nEle;

    /* Se é objeto */
    if (isObjeto) {
        novo.nAcoes = 3; /* Começa com três verbos padrões: EXAMINAR, PEGAR e LARGAR */
        novo.nAtr = 1; /* Começa com atributo padrão: se é pegável ou não */

        novo.transitividade = malloc(3 * sizeof(int));
        novo.transitividade[0] = 1;
        novo.transitividade[1] = 1;
        novo.transitividade[2] = 1;

        novo.acoes = malloc(3 * sizeof(func));
        novo.acoes[0] = examinar;
        novo.acoes[1] = pegar;
        novo.acoes[2] = largar;
    }

    /* Se é lugar */
    else {
        novo.nAcoes = 1;
        novo.nAtr = 0;

        novo.transitividade = malloc(sizeof(int));
        novo.transitividade[0] = 1;

        novo.acoes = malloc(sizeof(func));
        novo.acoes[0] = examinar;
    }

    novo.animacao = NULL; /* Por padrão os elementos não possuem animação */

    /* Union padrão para os objetos */
    Info detalhe;

    /* Se é objeto */
    if (isObjeto) {
        detalhe.atributos = malloc(sizeof(obj_atr));

        obj_atr pegavel;
        pegavel.nome = "pegavel";
        pegavel.valor.valor_estado = True;

        detalhe.atributos[0] = pegavel;
    }

    novo.detalhe = detalhe;

    return novo;
}





Elemento criarSala0() {

    /* ------------------------------------- SALA 0 ---------------------------------------------- */

    /* Porta 1 */
    Elemento porta1 =
    criarElemento(True, "uma", "Porta 1",
        "Uma porta de ferro.",
        "Uma porta de ferro com fechadura dourada.", NULL, 0);

    porta1.detalhe.atributos[0].valor.valor_estado = False; /* Não é pegável */


    /* Porta 2 */
    Elemento porta2 =
    criarElemento(True, "uma", "Porta 2",
        "Uma porta dourada.",
        "Uma porta dourada muito velha.", NULL, 0);

    porta2.detalhe.atributos[0].valor.valor_estado = False; /* Não é pegável */


    /* Porta 3 */
    Elemento porta3 =
    criarElemento(True, "uma", "Porta 3",
        "Uma porta de madeira.",
        "Uma porta de madeira de ébano.", NULL, 0);

    porta3.detalhe.atributos[0].valor.valor_estado = False; /* Não é pegável */


    /* Porta 4 */
    Elemento porta4 =
    criarElemento(True, "uma", "Porta 4",
        "Uma porta branca.",
        "Uma porta branca cheia de lascas.", NULL, 0);

    porta4.detalhe.atributos[0].valor.valor_estado = False; /* Não é pegável */


    /* Porta 5 */
    Elemento porta5 =
    criarElemento(True, "uma", "Porta 5",
        "Uma porta vermelha.",
        "Uma porta vermelha com fechadura preta.", NULL, 0);

    porta5.detalhe.atributos[0].valor.valor_estado = False; /* Não é pegável */


    /* GLaDOS */
    Elemento GLaDOS =
    criarElemento(True, "um", "Robô",
        "Um robô com voz feminina fala com você: \n \
        \t\"Olá, seja bem-vindo ao Aperture Science Computer-Aided Enrichment Center. Você poderia me dizer a senha?\"",
        "Um robô com voz feminina fala com você: \n \
        \t\"Olá, seja bem-vindo ao Aperture Science Computer-Aided Enrichment Center. Você poderia me dizer a senha?\"", NULL, 0);

    GLaDOS.detalhe.atributos[0].valor.valor_estado = False; /* Não é pegável */
    GLaDOS.animacao = malloc(sizeof(func));
    GLaDOS.animacao = GLaDOS.acoes[0];

    obj_atr senha;
    senha.nome = "senha";
    senha.valor.valor_str = "SENHA";
    adicionarAtributo(&GLaDOS, senha);

    func tentativaGLaDOS = tentarSenha;

    adicionarAcao(&GLaDOS, tentativaGLaDOS, 3); /* Caso específico em que os argumentos do verbo são diferentes */


    /* Sala 0 */
    Elemento *conteudoS0 = malloc(6 * sizeof(Elemento));
    conteudoS0[0] = porta1;
    conteudoS0[1] = porta2;
    conteudoS0[2] = porta3;
    conteudoS0[3] = porta4;
    conteudoS0[4] = porta5;
    conteudoS0[5] = GLaDOS;

    Elemento sala0 =
    criarElemento(False, "um", "Lobby",
        "Uma sala ampla com 5 portas e circular.",
        "Uma sala ampla com 5 portas e circular. No centro há um robô branco. Ele está olhando para você ...", conteudoS0, 6);

    return sala0;
}









Elemento criarSala1() {

    /* ------------------------------------- SALA 1 ---------------------------------------------- */

    /* Mensagem */
    Elemento mensagem =
    criarElemento(True, "uma","Mensagem",
        "Na parede há uma mensagem: 1 + 1 = 2.",
        "Na parede está escrito com tinta vermelha: 1 + 1 = 2.", NULL, 0);

    mensagem.detalhe.atributos[0].valor.valor_estado = False; /* Não é pegável */


    /* Letra */
    Elemento letra =
    criarElemento(True, "uma","Letra",
        "A letra é \"H\"!",
        "Quebre a concha!",
        NULL, 0);

    letra.visivel = False; /* Não é visível */
    letra.detalhe.atributos[0].valor.valor_estado = False; /* Não é pegável */


    /* Concha */
    Elemento *conteudoConcha = malloc(sizeof(Elemento));
    conteudoConcha[0] = letra; /* Letra está dentro da concha */

    obj_atr estaQuebrada;
    estaQuebrada.nome = "estaQuebrada";
    estaQuebrada.valor.valor_estado = False;

    func quebrarConcha = quebrar;

    Elemento concha =
    criarElemento(True, "uma","Concha",
        "Uma concha em formato de espiral.",
        "Uma concha verde em formato de espiral.", conteudoConcha, 1);

    adicionarAtributo(&concha, estaQuebrada);
    adicionarAcao(&concha, quebrarConcha, 1);
    adicionarElemento(&letra, &concha);


    /* Porta */
    Elemento porta =
    criarElemento(True, "uma", "Porta",
        "Uma porta para o lobby.",
        "Uma porta de ferro com fechadura dourada para o lobby.", NULL, 0);

    porta.detalhe.atributos[0].valor.valor_estado = False; /* Não é pegável */


    /* Ponteiro do relógio */
    func colocarnoRelogio = colocar;

    Elemento ponteiro = 
    criarElemento(True, "um", "Ponteiro",
        "Um ponteiro de relógio.",
        "Um ponteiro de minutos do relógio quebrado.", NULL, 0);

    adicionarAcao(&ponteiro, colocarnoRelogio, 2);


    /* Relógio */
    Elemento relogio =
    criarElemento(True, "um","Relógio",
        "Relógio quebrado sem um dos ponteiros.",
        "Relógio sem o ponteiro dos minutos e com o ponteiro das horas apontando para o VIII.", NULL, 0);

    obj_atr senha;
    senha.nome = "senha";
    senha.valor.valor_str = "13";
    adicionarAtributo(&relogio, senha);

    func tentativaRelogio = tentarSenha;

    adicionarAcao(&relogio, tentativaRelogio, 3); /* Caso específico em que os argumentos do verbo são diferentes */


    /* Sala 1 */
    Elemento *conteudoS1 = malloc(6 * sizeof(Elemento));
    conteudoS1[0] = relogio;
    conteudoS1[1] = ponteiro;
    conteudoS1[2] = porta;
    conteudoS1[3] = concha;
    conteudoS1[4] = letra;
    conteudoS1[5] = mensagem;

    Elemento sala1 =
    criarElemento(False, "uma", "Fibonacci",
        "Uma sala empoeirada com cheiro de mofo.",
        "Uma sala empoeirada com cheiro de mofo. Há um relógio e um ponteiro no chão. Na parede está escrita uma mensagem e sob um pedestal há uma concha. Além disso, tem uma porta no fundo da sala.", conteudoS1, 6);

    return sala1;
}











Elemento criarSala2() {

    /* --------------------------------------- SALA 2 --------------------------------------------- */


    /* Mensagem */
    Elemento mensagem =
    criarElemento(True, "uma","Mensagem",
        "Está escrito: \".. ... ... --- -. .- --- . -.-. --- -.. .. --. --- -- --- .-. ... .\"",
        "Numa folha de papel amassada está escrito: \".. ... ... --- -. .- --- . -.-. --- -.. .. --. --- -- --- .-. ... .\"",
        NULL, 0);

    mensagem.detalhe.atributos[0].valor.valor_estado = False; /* Não é pegável */


    /* Porta */
    Elemento porta =
    criarElemento(True, "uma", "Porta",
        "Uma porta.",
        "Uma porta dourada.", 
        NULL, 0);

    porta.detalhe.atributos[0].valor.valor_estado = False; /* Não é pegável */


    /* Morsa */
    obj_atr estaQuebrada;
    estaQuebrada.nome = "estaQuebrada";
    estaQuebrada.valor.valor_estado = False;

    func quebrarMorsa = quebrar;
    Elemento morsa =
    criarElemento(True, "uma","Pelúcia",
        "Uma morsa de pelúcia.",
        "Uma morsa de pelúcia marrom.", 
        NULL, 0);

    adicionarAtributo(&morsa, estaQuebrada);
    adicionarAcao(&morsa, quebrarMorsa, 1);


    /* Página */
    Elemento pagina =
    criarElemento(True, "uma","Página",
        "Você já tentou procurar embaixo do cofre?",
        "Você já tentou procurar embaixo do cofre?",
        NULL, 0);

    pagina.visivel = False; /* Não é visível */


    /* Livro */
    Elemento livro =
    criarElemento(True, "um","Livro",
        "Um livro velho. O título é \"Existem apenas -. tipos de pessoas no mundo\".",
        "Um livro velho e surpreendentemente grande. O título é \"Existem apenas 10 tipos de pessoas no mundo\".", NULL, 0);

    adicionarElemento(&pagina, &livro);

    obj_atr senha;
    senha.nome = "senha";
    senha.valor.valor_str = "2094530789280";
    adicionarAtributo(&livro, senha);

    func tentativaLivro = tentarSenha;
    adicionarAcao(&livro, tentativaLivro, 3); /* Caso específico em que os argumentos do verbo são diferentes */


    /* Letra */
    Elemento letra =
    criarElemento(True, "uma","Letra",
        "A letra é \"N\"!",
        "A letra é \"N\"!",
        NULL, 0);

    letra.visivel = False; /* Não é visível */
    letra.detalhe.atributos[0].valor.valor_estado = False; /* Não é pegável */


    /* Cofre */
    Elemento cofre =
    criarElemento(True, "um", "Cofre",
        "Um cofre de ferro.",
        "Um cofre grande de ferro com uma fechadura mecânica.", NULL, 0);

    adicionarElemento(&letra, &cofre);

    obj_atr senha2;
    senha2.nome = "senha";
    senha2.valor.valor_str = "IMPOSSIVELDEDESCOBRIR";
    adicionarAtributo(&cofre, senha2);

    func tentativaCofre = tentarSenha;
    adicionarAcao(&cofre, tentativaCofre, 3); /* Caso específico em que os argumentos do verbo são diferentes */

    cofre.detalhe.atributos[0].valor.valor_estado = False; /* Não é pegável */



    /* Sala 2 */
    Elemento *conteudoS2 = malloc(7 * sizeof(Elemento));
    conteudoS2[0] = letra;
    conteudoS2[1] = cofre;
    conteudoS2[2] = livro;
    conteudoS2[3] = pagina;
    conteudoS2[4] = morsa;
    conteudoS2[5] = porta;
    conteudoS2[6] = mensagem;

    Elemento sala2 =
    criarElemento(False, "uma","Binaria",
        "Uma sala legal.",
        "Uma sala com um cofre, livro, mensagem, página, morsa de pelúcia e porta aberta.", conteudoS2, 7);

    return sala2;
}











Elemento criarSala3() {

    /* --------------------------------------- SALA 3 --------------------------------------------- */


    /* Porta */
    Elemento porta =
    criarElemento(True, "uma", "Porta",
        "Uma porta de madeira.",
        "Uma porta de madeira de ébano.", NULL, 0);

    porta.detalhe.atributos[0].valor.valor_estado = False; /* Não é pegável */


    /* Letra */
    Elemento letra = 
    criarElemento(True, "uma", "Letra",
        "A letra é \"E\"!",
        "A letra é \"E\"!",
        NULL, 0);

    letra.visivel = False; /* Não é visível */
    letra.detalhe.atributos[0].valor.valor_estado = False; /* Não é pegável */


    /* Ovo */
    Elemento *conteudoOvo = malloc(sizeof(Elemento));
    conteudoOvo[0] = letra;

    obj_atr estaQuebrado;
    estaQuebrado.nome = "estaQuebrada";
    estaQuebrado.valor.valor_estado = False;

    Elemento ovo = 
    criarElemento(True, "um", "Ovo",
        "Um ovo brilhante.",
        "Um ovo feito de aço.",
        conteudoOvo, 1);

    ovo.visivel = False; /* Não é visível */

    func quebrarOvo = quebrar, atrairOvo = atrair;

    adicionarAtributo(&ovo, estaQuebrado);
    adicionarAcao(&ovo, atrairOvo, 2);
    adicionarAcao(&ovo, quebrarOvo, 1);


    /* Galinha */
    Elemento *conteudoGalinha = malloc(sizeof(Elemento));
    conteudoGalinha[0] = ovo;

    obj_atr estaFaminta;
    estaFaminta.nome = "estaFaminta";
    estaFaminta.valor.valor_estado = True;

    func alimentarGalinha = alimentar;

    Elemento galinha =
    criarElemento(True, "uma", "Galinha",
        "Uma galinha branca.",
        "Uma galinha grande com penas brancas.", conteudoGalinha, 1);

    adicionarAtributo(&galinha, estaFaminta);
    adicionarAcao(&galinha, alimentarGalinha, 2);


    /* Gaiola */
    Elemento *conteudoGaiola = malloc(sizeof(Elemento));
    conteudoGaiola[0] = galinha;

    Elemento gaiola =
    criarElemento(True, "uma", "Gaiola",
        "Uma gaiola dourada.",
        "Uma grande gaiola dourada. Há uma galinha presa nela? ...", conteudoGaiola, 1);

    obj_atr estaMagnetizado;
    estaMagnetizado.nome = "estaMagnetizado";
    estaMagnetizado.valor.valor_estado = False;


    /* Metal */
    Elemento metal =
    criarElemento(True, "um", "Metal",
        "Uma pequena barra de metal.",
        "Uma pequena barra de metal. Nela está gradado: \"Co\"", NULL, 0);

    adicionarAtributo(&metal, estaMagnetizado);


    /* Bobina */
    func ligarBobina = ligar;
    Elemento bobina =
    criarElemento(True, "uma", "Bobina",
        "Uma grande bobina elétrica.",
        "Uma grande bobina elétrica. No um fio rompido e na lateral um botão vermelho.", NULL, 0);
    
    adicionarAcao(&bobina, ligarBobina, 2);


    // /* Botão */
    // Elemento botao = 
    // criarElemento(True, "um", "Botão",
    //     "Um botão vermelho.",
    //     "Um botão grande e vermelho.", NULL, 0);


    /* Saco */
    Elemento saco = 
    criarElemento(True, "um", "Saco",
        "Um saco com milho.",
        "Um saco de linho com milho.", NULL, 0);


    /* Sala 3 */
    Elemento *conteudoS3 = malloc(8 * sizeof(Elemento));
    conteudoS3[0] = porta;
    conteudoS3[1] = gaiola;
    conteudoS3[2] = galinha;
    conteudoS3[3] = ovo;
    conteudoS3[4] = bobina;
    conteudoS3[5] = metal;
    conteudoS3[6] = saco;
    conteudoS3[7] = letra;
    // conteudoS3[5] = botao;
    
    Elemento sala3 =
    criarElemento(False, "uma","Galinhada",
        "Uma sala circular. No centro há uma gaiola pendurada no teto e uma bobina muito grande no chão.",
        "Uma sala circular. No centro há uma gaiola pendurada no teto e uma bobina muito grande no chão. No fundo há um saco de linho e ao lado uma barra de metal.",
        conteudoS3, 8);

    return sala3;
}
















Elemento criarSala4() {

    /* ------------------------------------- SALA 4 ---------------------------------------------- */


    /* Mensagem */
    Elemento mensagem =
    criarElemento(True, "uma", "Mensagem",
        "Na parede há uma mensagem: acho que há pressão demais por aqui.",
        "Na parede está escrito em azul: acho que há pressão demais por aqui.", NULL, 0);

    mensagem.detalhe.atributos[0].valor.valor_estado = False; /* Não é pegável */


    /* Poema */
    Elemento poema =
    criarElemento(True, "um", "Poema",
        "Poema sem o sétimo verso.",
        "Poema escrito a tinta com uma caligrafia estranha. Está faltando o sétimo verso.", NULL, 0);


    /* Blocos */
    obj_atr estaNaBalanca;
    estaNaBalanca.nome = "estaNaBalanca";
    estaNaBalanca.valor.valor_estado = False;

    func colocarBlocoSobre = colocar;

    int i;
    Elemento* blocos = malloc(10 * sizeof(Elemento));
    for (i = 0; i < 10; i++) {
        char num[2];
        num[0] = i + 48;
        num[1] = '\0';

        char nome[] = "Bloco ";
        char desc1Ini[] = "Bloco com o número ";
        char desc1Fim[] = ".";
        char desc2Ini[] = "Bloco empoeirado e com o número ";
        char desc2Fim[] = " gravado.";

        char *nomeBloco = malloc(strlen(nome) + strlen(num));
        char *descCurta = malloc(strlen(desc1Ini) + strlen(num) + strlen(desc1Fim));
        char *descLonga = malloc(strlen(desc2Ini) + strlen(num) + strlen(desc2Fim));

        strcpy(nomeBloco, nome);
        strcat(nomeBloco, num);

        strcpy(descCurta, desc1Ini);
        strcat(descCurta, num);
        strcat(descCurta, desc1Fim);

        strcpy(descLonga, desc2Ini);
        strcat(descLonga, num);
        strcat(descLonga, desc2Fim);

        Elemento bloco =
        criarElemento(True, "um", nomeBloco,
            descCurta,
            descLonga,
            NULL, 0);

        adicionarAcao(&bloco, colocarBlocoSobre, 2);
        adicionarAtributo(&bloco, estaNaBalanca);

        blocos[i] = bloco;
    }


    /* Porta */
    Elemento porta =
    criarElemento(True, "uma", "Porta",
        "Uma porta branca.",
        "Uma porta branca com várias lascas.", 
        NULL, 0);

    porta.detalhe.atributos[0].valor.valor_estado = False; /* Não é pegável */


    /* Balança */
    Elemento balanca =
    criarElemento(True, "uma", "Balança",
        "Balança antiga.",
        "Balança um pouco enferrujada. Aparenta ser bem antiga.", NULL, 0);


    /* Letra */
    Elemento letra = 
    criarElemento(True, "uma", "Letra",
        "A letra é \"S\"!",
        "A letra é \"S\"!",
        NULL, 0);

    letra.visivel = False; /* Não é visível */
    letra.detalhe.atributos[0].valor.valor_estado = False; /* Não é pegável */


    /* Sala 4 */
    Elemento* conteudoS4 = malloc(15 * sizeof(Elemento));
    conteudoS4[0] = mensagem;
    conteudoS4[1] = poema;
    conteudoS4[2] = balanca;
    conteudoS4[3] = porta;
    conteudoS4[4] = letra;
    for (int i = 5; i < 15; i++)
        conteudoS4[i] = blocos[i-5];


    Elemento sala4 =
    criarElemento(False, "uma", "Pascal",
    "Uma sala triangular.",
    "Uma sala triangular. Há uma mesa com blocos, um papel com um poema no chão, uma mensagem na parede e uma balança.",
    conteudoS4, 15);

    return sala4;
}









Elemento criarSala5() {
    /* ------------------------------------- SALA 5 ---------------------------------------------- */


    /* Enigma */
    Elemento enigma =
    criarElemento(True, "uma", "Mensagem",
        "O que o cientista disse quando encontrou 2 átomos de hélio? HeHe.",
        "Um enigma.", NULL, 0);


    /* Mapa */
    Elemento mapa =
    criarElemento(True, "um", "Mapa",
        "Qual país está faltando?",
        "Um mapa do mundo faltando um país.", NULL, 0);


    obj_atr senha;
    senha.nome = "senha";
    senha.valor.valor_str = "Nepal";
    adicionarAtributo(&mapa, senha);

    func tentativaMapa = tentarSenha;

    adicionarAcao(&mapa, tentativaMapa, 3); /* Caso específico em que os argumentos do verbo são diferentes */


    /* Poster */
    Elemento poster =
    criarElemento(True, "um", "Poster",
        "Poster de Blade Runner.",
        "Poster da cidade futurista de Los Angeles com muitas luzes, telões e carros voadores.", NULL, 0);


    /* Caixa de fósforo */
    Elemento caixadefosforo =
    criarElemento(True, "uma", "Caixa de fósforo",
        "Uma caixa de fósforo.",
        "Uma caixa de fósforo.", NULL, 0);


    /* Lata de refrigerante */
    Elemento lataderefri =
    criarElemento(True, "uma", "Lata de refrigerante",
        "Lata de refrigerante.",
        "Lata de refrigerante.", NULL, 0);


    /* Porta */
    Elemento porta =
    criarElemento(True, "uma", "Porta",
        "Uma porta vermelha.",
        "Uma porta vermelha com fechadura preta.", NULL, 0);

    porta.detalhe.atributos[0].valor.valor_estado = False; /* Não é pegável */


    /* Letra */
    Elemento letra = 
    criarElemento(True, "uma", "Letra",
        "A letra é \"A\"!",
        "A letra é \"A\"!",
        NULL, 0);

    letra.visivel = False; /* Não é visível */
    letra.detalhe.atributos[0].valor.valor_estado = False; /* Não é pegável */


    /* Sala 5 */
    Elemento *conteudoS5 = malloc(7 * sizeof(Elemento));
    conteudoS5[0] = enigma;
    conteudoS5[1] = mapa;
    conteudoS5[2] = poster;
    conteudoS5[3] = caixadefosforo;
    conteudoS5[4] = lataderefri;
    conteudoS5[5] = porta;
    conteudoS5[6] = letra;

    Elemento sala5 =
    criarElemento(False, "uma", "NePAl",
        "A room.",
        "Um poster, uma caixa de fósforo, uma lata de refrigerante de guaraná, um mapa e uma porta para o lobby.", 
        conteudoS5, 7);

    return sala5;
}

void validarSala4() {
    int contBlocosNaBalanca = 0;
    int contBlocosCertos = 0;
    int i;
    int atr;
    for (i=5; i < heroi->salaAtual->nEle; i++) {
        atr = procurarAtributo(&heroi->salaAtual->conteudo[i], "estaNaBalanca");
        if (heroi->salaAtual->conteudo[i].detalhe.atributos[atr].valor.valor_estado == True) {
            contBlocosNaBalanca++;
            if (strcmp(heroi->salaAtual->conteudo[i].n, "Bloco 1") == 0 ||
                strcmp(heroi->salaAtual->conteudo[i].n, "Bloco 2") == 0 ||
                strcmp(heroi->salaAtual->conteudo[i].n, "Bloco 8") == 0) 
                contBlocosCertos++;
        }
    }

    if (contBlocosNaBalanca == 3 && contBlocosCertos == 3) {
        heroi->salaAtual->conteudo[4].visivel = True;
        ((func)heroi->salaAtual->conteudo[4].acoes[0])(&heroi->salaAtual->conteudo[4], NULL);
    }
}