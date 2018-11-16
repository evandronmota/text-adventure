/*
    MAC0216 - Técnicas de Programação
    Nome: Evandro Nakayama Mota         Número USP: 10737230
    Nome: Gabriel Brandão de Almeida    Número USP: 10737182 
    Nome: Leonardo Alves Pereira        Número USP: 10737199

    DECLARAMOS QUE SOMOS OS UNICOS AUTORES E RESPONSAVEIS POR ESTE PROGRAMA.  
    TODAS AS PARTES DO PROGRAMA, EXCETO AS QUE SaO BASEADAS EM MATERIAL FORNECIDO
    PELO PROFESSOR OU COPIADAS DO LIVRO OU BIBLIOTECAS, FORAM DESENVOLVIDAS 
    POR NOS. 
*/

#include <stdlib.h>
#include <stdio.h>
#include "elemento.h"
#include "lista_ligada.h"
#include "salas.h"
#include "tabela_de_sim.h"

/*
    Recebe uma string. Cria um elemento com nome
    igual à string recebida. Retorna um ponteiro
    para o elemento criado.
*/
Elemento *criaElemento(char *n) {
    Elemento *el = malloc(sizeof(Elemento));
    el->n = malloc(80*sizeof(char));
    el->n = n;
    return el;
}

/* Insere objetos na tabela */
void insereObjnaTabela(TabSim tabela, char *nome, Elemento *sala) {
    int i;

    /* Insere sala */
    insere(tabela, nome, sala);

    /* Insere todos os objetos dentro da sala */
    for (i = 0; i<sala->nEle; i++)
        insere(tabela, sala->conteudo[i].n, &sala->conteudo[i]);
}

/* Testa salas */
void testarSala(Elemento *sala, int num, boolean flag, TabSim tabela, char *name) {
    printf("********************************\tTESTE: SALA %d\t\t********************************\n", num);

    /* Descrição longa ou curta */
    examinar(sala, NULL);

    /* Insere todos objetos da sala na tabela */
    if (flag)
        insereObjnaTabela(tabela, name, sala);

    int i, j;
    for (i=0; i < sala->nEle; i++) {
        Elemento *obj = &sala->conteudo[i];
        if (flag)
            nome(*obj);
        else {
            for (j=0; j < obj->nAcoes; j++) {
                if (obj->transitividade[j] == 0)
                    ((func)obj->acoes[j])(NULL, NULL);
                else if (obj->transitividade[j] == 1)
                    ((func)obj->acoes[j])(obj, NULL);
                else 
                    ((func)obj->acoes[j])(obj, obj);
            }
        }
    }

    printf("\n\n");
}

int main() {

    /* FASE: 1 */
    printf("############################################################\tFASE 1\t############################################################\n\n");

    /* TESTE: CRIAR */
    printf("********************************\tTESTE: CRIAR\t\t********************************\n");
    TabSim t = cria(17);
    printf("%s\n\n", (t!=NULL ? "Tabela criada e sucesso na criação das listas!" : "Erro ao criar tabela!"));

    /* Criação dos elementos */
    Elemento *el0 = criaElemento("dragao com asas de fogo"); // Elemento para testar colisão e possui dois nomes
    Elemento *el1 = criaElemento("dragao com colisao"); // Elemento para testar colisão
    Elemento *el2 = criaElemento("elemento teste");

    /* TESTE: INSERIR */
    printf("********************************\tTESTE: INSERIR\t\t********************************\n");
    printf("%s\n", (insere(t, "dragao", el0) ? "Sucesso ao inserir dragao!" : "Erro ao inserir dragao!"));
    printf("%s\n", (insere(t, "feioso", el0) ? "Sucesso ao inserir feioso!" : "Erro ao inserir feioso!"));
    printf("%s\n\n", (insere(t, "gaodra", el1) ? "Sucesso ao inserir gaodra!" : "Erro ao inserir gaodra!"));

    /* TESTE: BUSCAR */
    printf("********************************\tTESTE: BUSCAR\t\t********************************\n");
    el2 = busca(t, "dragao");
    if (el2!=NULL)
        printf("Sucesso ao buscar elemento: '%s' a partir de 'dragao'!\n", el2->n);
    else printf("Elemento a partir de 'dragao' não encontrado!\n");

    el2 = busca(t, "feioso");
    if (el2!=NULL)
        printf("Sucesso ao buscar elemento: '%s' a partir de 'feioso'!\n", el2->n);
    else printf("Elemento a partir de 'feioso' não encontrado!\n");

    el2 = busca(t, "gaodra");
    if (el2!=NULL)
        printf("Sucesso ao buscar elemento: '%s' a partir de 'gaodra'!\n", el2->n);
    else printf("Elemento a partir de 'gaodra' não encontrado!\n");
    printf("\n");

    /* TESTE: RETIRAR */
    printf("********************************\tTESTE: RETIRAR\t\t********************************\n");
    printf("%s\n", (retira(t, "dragao") ? "Sucesso ao retirar dragao!" : "Erro ao retirar dragao!"));

    printf("VERIFICAÇÃO DO RETIRAR:\n");
    el2 = busca(t, "dragao");
    if (el2!=NULL)
        printf("Sucesso ao buscar elemento: '%s' a partir de 'dragao'!\n", el2->n);
    else printf("Elemento a partir de 'dragao' não encontrado!\n");

    el2 = busca(t, "feioso");
    if (el2!=NULL)
        printf("Sucesso ao buscar elemento: '%s' a partir de 'feioso'!\n", el2->n);
    else printf("Elemento a partir de 'feioso' não encontrado!\n");

    el2 = busca(t, "gaodra");
    if (el2!=NULL)
        printf("Sucesso ao buscar elemento: '%s' a partir de 'gaodra'!\n", el2->n);
    else printf("Elemento a partir de 'gaodra' não encontrado!\n");
    printf("\n");

    destroi(t);







    /* FASE: 2 */
    printf("\n\n############################################################\tFASE 2\t############################################################\n\n");

    /* Criar tabela e salas */
    TabSim tab = cria(97);
    Elemento sala1 = criarSala1();
    Elemento sala2 = criarSala2();
    Elemento sala3 = criarSala3();
    // Elemento sala4 = criarSala4();
    Elemento sala5 = criarSala5();

    boolean flag = True;

    /* Testes */
    while (True) {
        testarSala(&sala1, 1, flag, tab, "Fibonacci");
        testarSala(&sala2, 2, flag, tab, "Morse");
        testarSala(&sala3, 3, flag, tab, "Papagaio?");
        // testarSala(&sala4, 4, flag, tab, "Pascal");
        testarSala(&sala5, 5, flag, tab, "NePAl");

        flag = False;

        getchar(); /* Simulação de comando */
    }

    return 0;
}

/*          |^^^^^|          */
/*         d(- _ -)b         */
/*   0======|     |======0   */
/*          |     |          */
/*          |_____|          */
/*          | | | |          */
/*          | | | |          */
/*        __| | | |__        */
/*       |____| |____|       */
/*   \-------------------/   */
/*     O O            O O    */
