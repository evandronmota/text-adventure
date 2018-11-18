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
#include "../libraries/elemento.h"
#include "../libraries/aventureiro.h"
#include "../libraries/lista_ligada.h"
#include "../libraries/salas.h"
#include "../libraries/tabela_de_sim.h"
#include "../libraries/initSalas.h"

/* Cores */
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

/* Mensagens */
#define OK BOLDGREEN "OK\t" RESET
#define ERROR BOLDRED "ERROR\t" RESET

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
    int i, j;

    printf(CYAN "********************************\tTESTE: " BOLDWHITE "SALA %d" RESET CYAN "\t\t********************************\n" RESET, num);

    /* Descrição longa ou curta */
    if (flag)
        printf(BOLDBLUE "Descrição LONGA da sala:\n" RESET);
    else printf(BOLDBLUE "Descrição CURTA da sala:\n" RESET);
    examinar(sala, NULL);

    /* Insere todos objetos da sala na tabela */
    if (flag)
        insereObjnaTabela(tabela, name, sala);

    if (flag)
        printf(BOLDBLUE"\nLista de OBJETOS da sala:\n"RESET);
    else printf(BOLDBLUE"\nLista de AÇÕES de cada objeto:\n"RESET);

    /* Imprime todos os objetos da sala ou aplica todas as ações */
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

// Aventureiro *heroi = criaAventureiro();
int main() {

    /* FASE: 1 */
    printf(BOLDMAGENTA "################################################################\tFASE 1\t\t################################################################\n\n\n\n" RESET);

    /* TESTE: CRIAR */
    printf(CYAN "********************************\tTESTE: " BOLDWHITE "CRIAR" RESET CYAN "\t\t********************************\n" RESET);
    TabSim t = cria(17);
    printf("%s\n\n", (t != NULL ? OK "Tabela criada e sucesso na criação das listas!" : ERROR "Erro ao criar tabela!"));

    /* Criação dos elementos */
    Elemento *el0 = criaElemento("dragao com asas de fogo"); /* Elemento para testar colisão e possui dois nomes */
    Elemento *el1 = criaElemento("dragao com colisao"); /* Elemento para testar colisão */
    Elemento *el2 = criaElemento("elemento teste");

    /* TESTE: INSERIR */
    printf(CYAN "********************************\tTESTE: " BOLDWHITE "INSERIR" RESET CYAN "\t\t********************************\n" RESET);
    printf("%s\n", (insere(t, "dragao", el0) ? OK "Sucesso ao inserir " BOLDWHITE "dragao!" RESET : ERROR "Erro ao inserir " BOLDWHITE "dragao!" RESET));
    printf("%s\n", (insere(t, "feioso", el0) ? OK "Sucesso ao inserir "BOLDWHITE "feioso!" RESET : ERROR "Erro ao inserir " BOLDWHITE "feioso!" RESET));
    printf("%s\n\n", (insere(t, "gaodra", el1) ? OK "Sucesso ao inserir "BOLDWHITE "gaodra!" RESET : ERROR "Erro ao inserir " BOLDWHITE "gaodra!" RESET));

    /* TESTE: BUSCAR */
    printf(CYAN "********************************\tTESTE: " BOLDWHITE "BUSCAR" RESET CYAN "\t\t********************************\n" RESET);
    el2 = busca(t, "dragao");
    if (el2!=NULL)
        printf(OK "Sucesso ao buscar elemento: " BOLDWHITE "'%s'" RESET " a partir de " BOLDWHITE "'dragao'! " RESET "\n", el2->n);
    else printf(ERROR "Elemento a partir de " BOLDWHITE "'dragao'" RESET " não encontrado!\n");

    el2 = busca(t, "feioso");
    if (el2!=NULL)
        printf(OK "Sucesso ao buscar elemento: " BOLDWHITE "'%s'" RESET " a partir de " BOLDWHITE "'feioso'!" RESET "\n", el2->n);
    else printf(ERROR "Elemento a partir de " BOLDWHITE "'feioso'" RESET " não encontrado!\n");

    el2 = busca(t, "gaodra");
    if (el2!=NULL)
        printf(OK "Sucesso ao buscar elemento: " BOLDWHITE "'%s'" RESET " a partir de " BOLDWHITE "'gaodra'!" RESET "\n", el2->n);
    else printf(ERROR "Elemento a partir de " BOLDWHITE "'gaodra'" RESET " não encontrado!\n");
    printf("\n");

    /* TESTE: RETIRAR */
    printf(CYAN"********************************\tTESTE: " BOLDWHITE "RETIRAR" RESET CYAN "\t\t********************************\n" RESET);
    printf("%s\n", (retira(t, "dragao") ? OK "Sucesso ao retirar " BOLDWHITE "dragao!" RESET : ERROR "Erro ao retirar " BOLDWHITE "dragao!" RESET));

    printf(BOLDWHITE"\nVERIFICAÇÃO DO RETIRAR:\n" RESET);
    el2 = busca(t, "dragao");
    if (el2!=NULL)
        printf(ERROR "Sucesso ao buscar elemento: " BOLDWHITE "'%s'" RESET " a partir de " BOLDWHITE "'dragao'!" RESET "\n", el2->n);
    else printf(OK "Elemento a partir de " BOLDWHITE "'dragao'" RESET " não encontrado!\n");

    el2 = busca(t, "feioso");
    if (el2!=NULL)
        printf(OK "Sucesso ao buscar elemento: " BOLDWHITE "'%s'" RESET " a partir de " BOLDWHITE "'feioso'!" RESET "\n", el2->n);
    else printf(ERROR "Elemento a partir de " BOLDWHITE "'feioso'" RESET " não encontrado!\n");

    el2 = busca(t, "gaodra");
    if (el2!=NULL)
        printf(OK "Sucesso ao buscar elemento: " BOLDWHITE "'%s'" RESET " a partir de " BOLDWHITE "'gaodra'!" RESET "\n", el2->n);
    else printf(ERROR "Elemento a partir de " BOLDWHITE "'gaodra'" RESET " não encontrado!\n");
    printf("\n");

    destroi(t);








    /* FASE: 2 */
    printf(BOLDMAGENTA "\n\n################################################################\tFASE 2\t\t################################################################\n\n\n\n" RESET);

    /* Criar tabela e salas */
    TabSim tab = cria(97);
    Elemento *salas = inicializarSalas();

    boolean flag = True;
    int i=0;

    /* Testes */
    while (True) {
        if (!flag)
            printf("______________________________________________________________________________________________________________________________\n\n\n\n");
        printf(BOLDWHITE "TESTE DE SALAS - COMANDO: %d\n\n\n" RESET, i++);
        testarSala(&salas[1], 1, flag, tab, "Fibonacci");
        testarSala(&salas[2], 2, flag, tab, "Morse");
        testarSala(&salas[3], 3, flag, tab, "Papagaio?");
        testarSala(&salas[4], 4, flag, tab, "Pascal");
        testarSala(&salas[5], 5, flag, tab, "NePAl");

        flag = False;

        getchar(); /* Simulação de comando */
    }


    return 0;
}

/*          |^^^^^|          */
/*         d(- _ -)b         */
/*   3======| _O_ |======K   */
/*          |  |  |          */
/*          |  /\ |          */
/*          | `--´|          */
/*          |_____|          */
/*          | | | |          */
/*          | | | |          */
/*        __| | | |__        */
/*       |____| |____|       */
/*   \___________________/   */
/*     O O            O O    */
