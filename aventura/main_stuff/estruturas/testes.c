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
#include "../headers/introducao.h"
#include "../headers/elemento.h"
#include "../headers/aventureiro.h"
#include "../headers/lista_ligada.h"
#include "../headers/salas.h"
#include "../headers/tabela_de_sim.h"
#include "../headers/init_salas.h"

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
#define FAIL BOLDRED "FAIL\t" RESET
#define VIS BOLDCYAN "[V]\t" RESET
#define INVIS BOLDBLACK "[INV]\t" RESET



/*
    Recebe uma string. Cria um elemento com nome
    igual à string recebida. Retorna um ponteiro
    para o elemento criado.
*/
Elemento *criaElemento(char *n) { /* FASE 1 */
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
void testarSala(Elemento *sala, int num, boolean flag) {
    int i, j, ok;

    printf(CYAN "********************************\tTESTE: " BOLDWHITE "SALA %d" RESET CYAN "\t\t********************************\n" RESET, num);

    /* Trocar de sala */
    printf(BOLDBLUE "VERBO exclusivo do Aventureiro:\n" RESET);
    printf(BOLDWHITE "TROCAR DE SALA:\t" RESET);
    printf(" %s\n", (trocarLugar(sala, NULL) ? OK : FAIL));
    printf("\n");

    /* Descrição longa ou curta */
    if (flag)
        printf(BOLDBLUE "Descrição LONGA da sala:\n" RESET);
    else printf(BOLDBLUE "Descrição CURTA da sala:\n" RESET);
    examinar(sala, NULL);
    printf("\n");

    if (flag)
        printf(BOLDBLUE "\nLista de OBJETOS da sala:\n" RESET);
    else printf(BOLDBLUE "\nLista de VERBOS de cada objeto da sala:\n" RESET);

    /* Imprime todos os objetos da sala ou aplica todas as ações */
    int num_obj = sala->nEle;
    for (i=0; i < num_obj; i++) {
        Elemento *obj = &sala->conteudo[i];
        ok = 0;
        if (flag) {/* Imprime os nomes dos objetos no primeiro comando */
            if (obj->visivel)
                printf(VIS);
            else printf(INVIS);
            nome(*obj);
        }
        else { /* Verbos nos outros comandos */
            for (j=0; j < obj->nAcoes; j++) {
                switch(j) {
                    case 0 :
                        printf(BOLDWHITE "EXAMINAR:\t" RESET);
                        break;
                    case 1 :
                        printf(BOLDWHITE "PEGAR:\t\t" RESET);
                        break;
                    case 2 :
                        printf(BOLDWHITE "LARGAR:\t\t" RESET);
                        break;
                    default :
                        printf(BOLDWHITE "OUTROS:\t\t" RESET);
                }

                if (!obj->transitividade[j]) /* Transitividade = 0 */
                    printf("%s\n", (((func)obj->acoes[j])(NULL, NULL)) ? OK : FAIL);
                else if (obj->transitividade[j] == 1) { /* Transitividade = 1 */
                    if (j==1 && obj->detalhe.atributos[0].valor.valor_estado)
                        ok = 1;
                    printf(" %s\n", (((func)obj->acoes[j])(obj, NULL)) ? OK : FAIL);
                    if (ok)
                        j++;
                }
                else /* Só para testar (transitividade 2 é nele mesmo) */
                    printf(" %s\n", (((func)obj->acoes[j])(obj, obj)) ? OK : FAIL);
                /* Animação */
            }
            printf("\n");
        }
    }

    if (flag)
        printf("\n");

    /* Imprime todos os objetos na mochila do Aventureiro */
    printf(BOLDBLUE "Lista de OBJETOS com o Aventureiro:\n" RESET);

    num_obj = heroi->nMochila;
    for (i=0; i<num_obj; i++) {
        if (heroi->mochila[i]->visivel)
            printf(VIS);
        else printf(INVIS);
        nome(*heroi->mochila[i]);
    }

    /* Aplica todas as ações dos objetos na mochila do Aventureiro */
    if (!flag) {
        printf(BOLDBLUE "\nLista de VERBOS de cada objeto do Aventureiro:\n" RESET);
        num_obj = heroi->nMochila;
        while (heroi->nMochila) {
            Elemento *obj = heroi->mochila[0];
            for (j=0; j < obj->nAcoes; j++) {
                switch(j) {
                    case 0 :
                        printf(BOLDWHITE "EXAMINAR:\t" RESET);
                        break;
                    case 1 :
                        printf(BOLDWHITE "PEGAR:\t\t" RESET);
                        break;
                    case 2 :
                        printf(BOLDWHITE "LARGAR:\t\t" RESET);
                        break;
                    default :
                        printf(BOLDWHITE "OUTROS:\t\t" RESET);
                }

                if (!obj->transitividade[j]) /* Transitividade = 0 */
                    printf(" %s\n", (((func)obj->acoes[j])(NULL, NULL)) ? OK : FAIL);
                else if (obj->transitividade[j] == 1) /* Transitividade = 1 */
                    printf(" %s\n", (((func)obj->acoes[j])(obj, NULL)) ? OK : FAIL);
                else /* Só para testar (transitividade 2 é nele mesmo) */
                    printf(" %s\n", (((func)obj->acoes[j])(obj, obj)) ? OK : FAIL);
                /* Animação */
            }
            printf("\n");
        }
    }

    printf("\n\n\n");
}





int main() {

    /* FASE: 1 */
    printf(BOLDMAGENTA "################################################################\tFASE 1\t\t################################################################\n\n\n\n" RESET);


    /* TESTE: CRIAR */
    printf(CYAN "********************************\tTESTE: " BOLDWHITE "CRIAR" RESET CYAN "\t\t********************************\n" RESET);
    TabSim t = cria(17);
    printf("%s\n\n", (t != NULL ? OK "Tabela criada e sucesso na criação das listas!" : FAIL "Erro ao criar tabela!"));


    /* Criação dos elementos */
    Elemento *el0 = criaElemento("dragao com asas de fogo"); /* Elemento para testar colisão e possui dois nomes */
    Elemento *el1 = criaElemento("dragao com colisao"); /* Elemento para testar colisão */
    Elemento *el2 = criaElemento("elemento teste");


    /* TESTE: INSERIR */
    printf(CYAN "********************************\tTESTE: " BOLDWHITE "INSERIR" RESET CYAN "\t\t********************************\n" RESET);
    printf("%s\n", (insere(t, "dragao", el0) ? OK "Sucesso ao inserir " BOLDWHITE "dragao!" RESET : FAIL "Erro ao inserir " BOLDWHITE "dragao!" RESET));
    printf("%s\n", (insere(t, "feioso", el0) ? OK "Sucesso ao inserir "BOLDWHITE "feioso!" RESET : FAIL "Erro ao inserir " BOLDWHITE "feioso!" RESET));
    printf("%s\n\n", (insere(t, "gaodra", el1) ? OK "Sucesso ao inserir "BOLDWHITE "gaodra!" RESET : FAIL "Erro ao inserir " BOLDWHITE "gaodra!" RESET));


    /* TESTE: BUSCAR */
    printf(CYAN "********************************\tTESTE: " BOLDWHITE "BUSCAR" RESET CYAN "\t\t********************************\n" RESET);
    el2 = busca(t, "dragao");
    if (el2!=NULL)
        printf(OK "Sucesso ao buscar elemento: " BOLDWHITE "'%s'" RESET " a partir de " BOLDWHITE "'dragao'! " RESET "\n", el2->n);
    else printf(FAIL "Elemento a partir de " BOLDWHITE "'dragao'" RESET " não encontrado!\n");

    el2 = busca(t, "feioso");
    if (el2!=NULL)
        printf(OK "Sucesso ao buscar elemento: " BOLDWHITE "'%s'" RESET " a partir de " BOLDWHITE "'feioso'!" RESET "\n", el2->n);
    else printf(FAIL "Elemento a partir de " BOLDWHITE "'feioso'" RESET " não encontrado!\n");

    el2 = busca(t, "gaodra");
    if (el2!=NULL)
        printf(OK "Sucesso ao buscar elemento: " BOLDWHITE "'%s'" RESET " a partir de " BOLDWHITE "'gaodra'!" RESET "\n", el2->n);
    else printf(FAIL "Elemento a partir de " BOLDWHITE "'gaodra'" RESET " não encontrado!\n");
    printf("\n");


    /* TESTE: RETIRAR */
    printf(CYAN"********************************\tTESTE: " BOLDWHITE "RETIRAR" RESET CYAN "\t\t********************************\n" RESET);
    printf("%s\n", (retira(t, "dragao") ? OK "Sucesso ao retirar " BOLDWHITE "dragao!" RESET : FAIL "Erro ao retirar " BOLDWHITE "dragao!" RESET));

    /* Verificação */
    printf(BOLDWHITE"\nVERIFICAÇÃO DO RETIRAR:\n" RESET);
    el2 = busca(t, "dragao");
    if (el2!=NULL)
        printf(OK "Sucesso ao buscar elemento: " BOLDWHITE "'%s'" RESET " a partir de " BOLDWHITE "'dragao'!" RESET "\n", el2->n);
    else printf(FAIL "Elemento a partir de " BOLDWHITE "'dragao'" RESET " não encontrado!\n");

    el2 = busca(t, "feioso");
    if (el2!=NULL)
        printf(OK "Sucesso ao buscar elemento: " BOLDWHITE "'%s'" RESET " a partir de " BOLDWHITE "'feioso'!" RESET "\n", el2->n);
    else printf(FAIL "Elemento a partir de " BOLDWHITE "'feioso'" RESET " não encontrado!\n");

    el2 = busca(t, "gaodra");
    if (el2!=NULL)
        printf(OK "Sucesso ao buscar elemento: " BOLDWHITE "'%s'" RESET " a partir de " BOLDWHITE "'gaodra'!" RESET "\n", el2->n);
    else printf(FAIL "Elemento a partir de " BOLDWHITE "'gaodra'" RESET " não encontrado!\n");
    printf("\n");

    destroi(t);







    /* FASE: 2 */
    printf(BOLDMAGENTA "\n\n################################################################\tFASE 2\t\t################################################################\n\n\n\n" RESET);

    /* Introdução */
    introducao();

    printf("______________________________________________________________________________________________________________________________\n\n\n\n");

    /* Legenda */
    printf(BOLDWHITE "LEGENDA:\n\n" RESET);
    printf(VIS "- Visível\n");
    printf(INVIS "- Invisível\n\n\n");

    /* Criar tabela e salas */
    TabSim tab = cria(97);
    Elemento *salas = inicializarSalas();

    /* Criar heroi */
    criarAventureiro(salas[0]);

    boolean flag = True; /* Flag de auxílio */
    int i=0;

    /* Insere todos objetos da sala na tabela */
    /* Os nomes são dos elementos na tabela de símbolos */
    for (i=0; i<6; i++)
        insereObjnaTabela(tab, salas[i].n, &salas[i]);

    /* Testes */
    while (True) {
        printf("______________________________________________________________________________________________________________________________\n\n\n\n");
        printf(BOLDWHITE "TESTE DE SALAS - COMANDO: %d\n\n\n" RESET, i++);

        testarSala(&salas[0], 0, flag);
        testarSala(&salas[1], 1, flag);
        testarSala(&salas[2], 2, flag);
        testarSala(&salas[3], 3, flag);
        testarSala(&salas[4], 4, flag);
        testarSala(&salas[5], 5, flag);

        flag = False;

        getchar(); /* Simulação de comando */
    }


    return 0;
}
