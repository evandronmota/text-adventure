#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../headers/elemento.h"
#include "../headers/aventureiro.h"

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
                printf("Erro ao adicionar %s %s na mochila!\n", e1->artigo, e1->n);
        }
        else if (x) /* Se já foi pego */
            printf("Você já pegou %s %s!", e1->artigo, e1->n);
        else /* Se não é pegável */
            printf("Você não pode pegar %s %s!", e1->artigo, e1->n);
    }

    return pegou;
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
            printf("Erro ao tirar %s %s da mochila!\n", e1->artigo, e1->n);
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
            printf("Você quebrou %s %s!", e1->artigo, e1->n);
            if (!strcmp(e1->n, "Concha")) {
                /* Torna mensagem com letra vísivel */
                e1->conteudo->visivel = True;
                e1->nEle--;
            }
        }
        else /* Se está quebrada */
            printf("Você já quebrou %s %s!", e1->artigo, e1->n);
    }



    return quebrou;
}

int colocar(Elemento *e1, Elemento *e2) {
    if (e1 == NULL)
        printf("Colocar o quê?");
    else if (e2 == NULL)
        printf("Colocar onde?");
    else {
        printf("Você colocou %s %s n%s %s.", e1->artigo, e1->n, e2->artigo, e2->n);
        int i = procurarAtributo(e1, "estaNaBalanca");
        e1->detalhe.atributos[i].valor.valor_estado = True;
        //adicionarElemento(e1, e2);
    }

    return (e1 == NULL || e2 == NULL ? 0 : 1);
}

int alimentar(Elemento *e1, Elemento *e2) {
    if (e1 == NULL)
        printf("Alimentar o quê?");
    else if (e2 == NULL)
        printf("Alimentar com o quê?");
    else {
        int i;
        for (i=0; i<e1->nAtr; i++) { /* Procura atributo */
            if (strcmp(e1->detalhe.atributos[i].nome, "estaFaminta")==0) { /* Acha estaFaminta */
                if (e1->detalhe.atributos[i].valor.valor_estado == True) { /* Senão está quebrada */
                    e1->detalhe.atributos[i].valor.valor_estado = False;
                    printf("A %s botou um ovo prateado!", e1->n);
                    for (i=0; i<e1->nEle; i++)
                        if (strcmp(e1->conteudo[i].n, "Ovo")){
                            e1->conteudo[i].visivel = True;
                            break;
                        }
                }
                else /* Se está alimentada */
                    printf("Você já alimentou a %s!", e1->n);
                break;
            }
        }
    }

    return (e1 == NULL || e2 == NULL ? 0 : 1);
}

int ligar(Elemento *e1, Elemento *e2) {
    if (e1 == NULL)
        printf("Ligar o quê?");
    else if (e2 == NULL) 
        printf("Parece que a bobina não liga com o fio rompido.");
    else if (strcmp(e2->n, "Metal") == 0) {
        int i;
        for (i=0; i<e2->nAtr; i++) { /* Procura atributo */
            if (strcmp(e1->detalhe.atributos[i].nome, "estaMagnetizado")==0) { 
                if (e1->detalhe.atributos[i].valor.valor_estado == False) { /* Senão está quebrada */
                    e1->detalhe.atributos[i].valor.valor_estado = True;
                    printf("A %s ligou e agora o %s está magnetizado!", e1->n, e2->n);
                }
                else 
                    printf("A %s já está ligada e o %s magnetizado!", e1->n, e2->n);
                break;
            }
        }
    }
    else printf("Não é possível fazer isso!");

    return (e1 == NULL || e2 == NULL ? 0 : 1);
}

int trocarLugar(Elemento *e1, Elemento *e2) {
    if (e1 == NULL)
        printf("Qual Lugar?");
    else {
        heroi->salaAtual = e1;
        printf("Você se moveu para %s %s!", e1->artigo, e1->n);
    }

    return (e1 == NULL ? 0 : 1);
}
