#include <stdlib.h>
#include <stdio.h>
#include "../libraries/elemento.h"
#include "../libraries/lista_ligada.h"
#include "../libraries/tabela_de_sim.h"
#include "../libraries/salas.h"

/* Insere objetos na tabela */
void insereObjnaTabela(TabSim tabela, char *nome, Elemento *sala) {
    int i;

    insere(tabela, nome, sala);

    for (i = 0; i<sala->nEle; i++)
        insere(tabela, sala->conteudo[i].n, &sala->conteudo[i]);
}

int main() {
    Elemento salaFib = criarSala1();
    Elemento salaMorse = criarSala2();
    Elemento salaPapagaio = criarSala3();
    // Elemento salaPascal = criarSala4();
    Elemento salaElementos = criarSala5();

    TabSim tab = cria(97);
    int i, j;
    boolean ok,ok2,ok3,ok4,ok5;
    ok=ok2=ok3=ok4=ok5=True;
    /* ((func)salaFib.conteudo[0].acoes[0])(&salaFib, NULL); */

    /* mundo criado */

    /* elemento da vez */
    Elemento *sala1 = &salaFib;
    Elemento *sala2 = &salaMorse;
    Elemento *sala3 = &salaPapagaio;
    // Elemento *sala4 = &salaPascal;
    Elemento *sala5 = &salaElementos;

    insereObjnaTabela(tab, "sala 1", sala1);
    insereObjnaTabela(tab, "sala 2", sala2);
    insereObjnaTabela(tab, "sala 3", sala3);
    // insereObjnaTabela(tab, "sala 4", sala4);
    insereObjnaTabela(tab, "sala 5", sala5);

    while (True) {
        /* ((func)sala1->conteudo[0].acoes[0])(&sala1->conteudo[0], NULL); */


        /* ######################################## SALA 1 ################################################ */
        printf("**************** SALA 1 ***************\n");
        examinar(sala1, NULL);
        if (ok) {
            for (i = 0; i<sala1->nEle; i++) {
                nome(sala1->conteudo[i]);
                // printf("%s\n", busca(tab, sala1->conteudo[i].n)->curta); /* Testa a busca pelo elemento na tabela */
            }
            ok = False;
        }
        for (i = 0; i<sala1->nEle; i++) {
            for (j = 0; j<sala1->conteudo[i].nAcoes; j++) {
                ((func) sala1->conteudo[i].acoes[j])(&sala1->conteudo[i], NULL);
            }
        }
        printf("\n\n");


        /* ######################################## SALA 2 ################################################ */
        printf("**************** SALA 2 ***************\n");
        examinar(sala2, NULL);
        if (ok2) {
            for (i = 0; i<sala2->nEle; i++)
                nome(sala2->conteudo[i]);
            ok2 = False;
        }
        for (i = 0; i<sala2->nEle; i++)
            for (j = 0; j<sala2->conteudo[i].nAcoes; j++)
                ((func) sala2->conteudo[i].acoes[j])(&sala2->conteudo[i], NULL);
        printf("\n\n");


        /* ######################################## SALA 3 ################################################ */
        printf("**************** SALA 3 ***************\n");
        examinar(sala3, NULL);
        if (ok3) {
            for (i = 0; i<sala3->nEle; i++)
                nome(sala3->conteudo[i]);
            ok3 = False;
        }
        for (i = 0; i<sala3->nEle; i++)
            for (j = 0; j<sala3->conteudo[i].nAcoes; j++)
                ((func) sala3->conteudo[i].acoes[j])(&sala1->conteudo[i], NULL);
        printf("\n\n");


        /* ######################################## SALA 4 ################################################ */
        // printf("**************** SALA 4 ***************\n");
        // examinar(sala4, NULL);
        // if (ok4) {
        //     for (i = 0; i<sala4->nEle; i++)
        //         nome(sala4->conteudo[i]);
        //     ok4 = False;
        // }
        // for (i = 0; i<sala4->nEle; i++)
        //     for (j = 0; j<sala4->conteudo[i].nAcoes; j++)
        //         ((func) sala4->conteudo[i].acoes[j])(&sala1->conteudo[i], NULL);
        // printf("\n\n");


        /* ######################################## SALA 5 ################################################ */
        printf("**************** SALA 5 ***************\n");
        examinar(sala5, NULL);
        if (ok5) {
            for (i = 0; i<sala5->nEle; i++)
                nome(sala5->conteudo[i]);
            ok5 = False;
        }
        for (i = 0; i<sala5->nEle; i++)
            for (j = 0; j<sala5->conteudo[i].nAcoes; j++)
                ((func) sala5->conteudo[i].acoes[j])(&sala1->conteudo[i], NULL);
        printf("\n\n");

        /* se for valido atualiza o auxiliar */
        /* se nao, manda uma msg de erro e nao atualiza o auxiliar */

        getchar(); /* simulação do comando */
    }

    return 0;
}
