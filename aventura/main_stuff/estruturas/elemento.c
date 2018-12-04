#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../headers/elemento.h"
#include "../headers/salas.h"
#include "../headers/aventureiro.h"

/* FUNÇÕES */

void nome(Elemento e) {
    /* Primeira letra do artigo vira maiúsculo */
    printf("%c%c%c %s.\n", e.artigo[0]-32, e.artigo[1], e.artigo[2], e.n);
}

int procurarAtributo(Elemento *e1, char *atributo) {
    int i;

    for (i=0; i<e1->nAtr; i++)
        if (!strcmp(e1->detalhe.atributos[i].nome, atributo))
            return i;

    return -1;
}

int tentarGLaDOS(char *key) {
    int acertou = 0;

    if (key == NULL)
        printf("Ei humano. Nós do Science Computer-Aided Enrichment Center nos preocupamos muito com o bem estar dos participantes. Nós lhe daremos uma grande fatia de bolo quando me disser a senha correta :)");
    else if (!strcmp("HNESA", key))
        printf("que coisa!! ");
    else if (!strcmp("SENHA", key)) {
        printf("Não é que nós nos divertimos juntos? Gostaria de dizer que estou prestes a abrir um alçapão em baixo de você que o jogaria em um poço de lava, mas parece que eu não fui permitida. Então esse é apenas um simples adeus. Espero que tenha aproveitada o sonho. \n\nTudo fica escuro. Você acorda em cima dos livros e lembra que ainda não entregou o EP ... ");
        acertou = 1;
        printf("****************** FIM DE JOGO ****************** \n");
        exit(0);
    }
    else
        printf("Parece que você não sabe a senha ...");

    return acertou;
}







/* VERBOS */

int examinar(Elemento *e1, Elemento *e2) {
    if (e1 == NULL)
        printf("Examinar o quê?");
    /* Curta se for conhecido, longa senão e muda atributo para conhecido */
    else if (e1->conhecido)
        printf("%s", e1->curta);
    else {
        printf("%s", e1->longa);
        e1->conhecido = True;
    }

    return (e1 == NULL ? 0 : 1);
}

int pegar(Elemento *e1, Elemento *e2) {
    int pegou = 0, x = estaNaMochila(e1);

    if (e1 == NULL)
        printf("Pegar o quê?");
    else  {
        if (e1->detalhe.atributos[0].valor.valor_estado && !x) { /* Se for um elemento pegável e não foi pego*/
            printf("Você pegou %s %s!", e1->artigo, e1->n);
            if (adicionarNaMochila(e1))
                pegou = 1;
            else
                printf("Erro ao adicionar %s %s na mochila!", e1->artigo, e1->n);
        }
        else if (x) /* Se já foi pego */
            printf("Você já pegou %s %s!", e1->artigo, e1->n);
        else /* Se não é pegável */
            printf("Você não pode pegar %s %s!", e1->artigo, e1->n);
    }

    return pegou;
}

int atrair(Elemento *e1, Elemento *e2) {
    int atraiu = 0;

    if (e1 == NULL)
        printf("Atrair o quê?");
    else if (e2 == NULL)
        printf("Atrair com o quê?");
    else {
        if (strcmp(e2->n, "Metal") == 0){
            int i = procurarAtributo(e2, "estaMagnetizado");
            if (e2->detalhe.atributos[i].valor.valor_estado == False) { 
                printf("Você não pode atrir coisas com %s %s!", e1->n, e2->n);
            }
            else {
                printf("Você atraiu %s %s com %s %s magnetizado!", e1->artigo, e1->n, e2->artigo, e2->n);
                atraiu = 1;
                pegar(e1, NULL);
            }
        }
        else
            printf("Você não pode atrair %s %s usando %s %s!", e1->artigo, e1->n, e2->artigo, e2->n);
    }

    return atraiu; 
}

int largar(Elemento *e1, Elemento *e2) {
    int largou = 0;

    if (e1 == NULL)
        printf("Largar o quê?");

    else if (estaNaMochila(e1)) { /* Se está na mochila */
        if (tirarDaMochila(e1)) {
            printf("Você largou %s %s!", e1->artigo, e1->n);
            largou = 1;
        }
        else
            printf("Erro ao tirar %s %s da mochila!", e1->artigo, e1->n);
    }

    else /* Senão está na mochila */
        printf("Você não possui %s %s!", e1->artigo, e1->n);

    return largou;
}

int quebrar(Elemento *e1, Elemento *e2) {
    int i, quebrou=0;

    /* Elementos NULL */
    if (e1 == NULL)
        printf("Quebrar o quê?");
    else {
        i = procurarAtributo(e1, "estaQuebrada");
        if (i == -1)
            printf("Você não pode quebrar %s %s!", e1->artigo, e1->n);
        else if (!e1->detalhe.atributos[i].valor.valor_estado) { /* Senão está quebrada */
            quebrou = 1;
            e1->detalhe.atributos[i].valor.valor_estado = True;
            printf("Você quebrou %s %s! ", e1->artigo, e1->n);
            if (e1->conteudo == NULL)
                printf("%c%c%c %s está vazio!", e1->artigo[0]-32, e1->artigo[1], e1->artigo[2], e1->n);
            else {
                /* Torna mensagem com letra vísivel */
                e1->conteudo->visivel = True;
                printf("%s", e1->conteudo[0].curta);
                e1->nEle--;
            }
        }
        else /* Se está quebrada */
            printf("Você já quebrou %s %s!", e1->artigo, e1->n);
    }

    return quebrou;
}

int colocar(Elemento *e1, Elemento *e2) {
    int i;
    if (e1 == NULL)
        printf("Colocar o quê?");
    else if (e2 == NULL)
        printf("Colocar onde?");
    else {
        if (strcmp(e1->n, e2->n) != 0) {
            printf("Você colocou %s %s n%s %s.", e1->artigo, e1->n, e2->artigo, e2->n);
            i = procurarAtributo(e1, "estaNaBalanca");
            if (i != -1)
                e1->detalhe.atributos[i].valor.valor_estado = True;
            adicionarElemento(e1, e2);
        }
        else
            printf("Nao é possível colocar um elemento sobre ele mesmo!");

    }

    return (e1 == NULL || e2 == NULL || e1 == e2 ? 0 : 1);
}


int alimentar(Elemento *e1, Elemento *e2) {
    int i, alimentou=0;

    if (e1 == NULL)
        printf("Alimentar o quê?");
    else if (e2 == NULL)
        printf("Alimentar com o quê?");
    else if (strcmp(e2->n, "Saco") == 0){
        i = procurarAtributo(e1, "estaFaminta"); /* Acha estaFaminta */
        if (i == -1)
            printf("Você não pode alimentar a %s!", e1->n);
        else {
            if (e1->detalhe.atributos[i].valor.valor_estado == True) { /* Senão está quebrada */
                e1->detalhe.atributos[i].valor.valor_estado = False;
                alimentou = 1;
                printf("A %s botou um ovo prateado!", e1->n);
                for (i=0; i<e1->nEle; i++)
                    if (strcmp(e1->conteudo[i].n, "Ovo")) {
                        e1->conteudo[i].visivel = True;
                        break;
                    }
            }
            else /* Se está alimentada */
                printf("Você já alimentou a %s!", e1->n);
        }
    }
    else 
        printf("Você não pode alimentar %s %s usando %s %s!", e1->artigo, e1->n, e2->artigo, e2->n);

    return alimentou;
}

int ligar(Elemento *e1, Elemento *e2) {
    int i, ligou = 0;

    if (e1 == NULL)
        printf("Ligar o quê?");
    else if (e2 == NULL) 
        printf("Parece que a bobina não liga com o fio rompido.");
    else if (!strcmp(e2->n, "Metal")) {
        i = procurarAtributo(e2, "estaMagnetizado");
        if (i == -1)
            printf("Você não pode ligar a bobina com %s %s!", e1->artigo, e1->n);
        else {
            if (e2->detalhe.atributos[i].valor.valor_estado == False) { 
                e2->detalhe.atributos[i].valor.valor_estado = True;
                ligou = 1;
                printf("A %s ligou e agora o %s está magnetizado!", e1->n, e2->n);
            }
            else 
                printf("A %s já está ligada e o %s magnetizado!", e1->n, e2->n);
        }
    }
    else printf("Não é possível ligar a bobina com %s %s.", e2->artigo, e2->n);

    return ligou;
}

int trocarLugar(Elemento *e1, Elemento *e2) {
    if (e1 == NULL)
        printf("Qual Lugar?");
    else {
        heroi->salaAtual = e1;
        printf("Você se moveu para %s %s!", e1->artigo, e1->n);
        printf("\n");
        examinar(heroi->salaAtual, NULL);
        printf("\n");
    }

    return (e1 == NULL ? 0 : 1);
}

int tentarSenha(Elemento *e, char *senha) {
    int i, acertou=0;

    if (e == NULL)
        printf("Você esqueceu de escrever a senha ...");
    else {
        if (!strcmp(e->n, "Robo")) { /* Caso especial da senha principal */
            if (tentarGLaDOS(senha))
                acertou = 1;
        }
        else {
            i = procurarAtributo(e, "senha");
            if (i == -1)
                printf("%s %s não possui uma senha!", e->artigo, e->n);
            else {
                if (!strcmp(e->detalhe.atributos[i].valor.valor_str, senha)) {
                    printf("A senha \"%s\" está correta! ", senha);
                    for (i=0; i<heroi->salaAtual->nEle; i++)
                        if (!strcmp(heroi->salaAtual->conteudo[i].n, "Letra")) {
                            heroi->salaAtual->conteudo[i].visivel = True;
                            examinar(&heroi->salaAtual->conteudo[i], NULL);
                        }
                    acertou = 1;
                }
                else printf("A senha \"%s\" está incorreta!", senha);
            }
        }
    }

    return acertou;
}

int validar(Elemento *e1, Elemento *e2) {
    if (!strcmp(e1->n, "Balança")) {
        int cont = 0;
        if (e1->nEle == 3) {
            int i;
            for (i=0; i < e1->nEle; i++) {
                if (strcmp(e1->conteudo[i].n, "Bloco1") == 0 ||
                    strcmp(e1->conteudo[i].n, "Bloco2") == 0 ||
                    strcmp(e1->conteudo[i].n, "Bloco8") == 0) 
                    cont++;
            }

            if (cont == 3) {
                heroi->salaAtual->conteudo[4].visivel = True;
                ((func)heroi->salaAtual->conteudo[4].acoes[0])(&heroi->salaAtual->conteudo[4], NULL);
                return 1;
            }
        }

        printf("Blocos errados na balança!");
    }

    return 0;
}


int olharMochila(Elemento *e1, Elemento *e2) {
    int i;

    printf("Você possui:\n");
    for (i=0; i<heroi->nMochila; i++)
        printf("-%s\n", heroi->mochila[i]->n);

    return 1;
}

Elemento *copiaEle (Elemento e) {
    Elemento *novo = malloc(sizeof(Elemento));
    novo->artigo = e.artigo;
    novo->n = e.n;
    novo->curta = e.curta;
    novo->longa = e.longa;
    novo->ativo = e.ativo;
    novo->visivel = e.visivel;
    novo->conhecido = e.conhecido;
    novo->conteudo = e.conteudo;
    novo->nEle = e.nEle; /* Número de elementos na lista de conteúdos */
    novo->nAcoes = e.nAcoes; /* Número de ações do elemento */
    novo->nAtr = e.nAtr; /* Número de atributos do elemento */
    novo->acoes = e.acoes;
    novo->transitividade = e.transitividade;
    novo->animacao = e.animacao;
    novo->detalhe = e.detalhe;

    return novo;
}