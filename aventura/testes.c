/*
MAC0216 - Técnicas de Programação
Nome: Evandro Nakayama Mota, Número USP: 10737230
Nome: Gabriel Brandão de Almeida, Número USP: 10737182 
Nome: Leonardo Alves Pereira, Número USP: 10737199

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

Elemento *criaElemento(char *n) {
    Elemento *el = malloc(sizeof(Elemento));
    el->n = malloc(80*sizeof(char));
    el->n = n;
    return el;
}

void testarSala(Elemento sala) {
    printf("OI: %s\n", sala.longa);

    int i, j;
    for (i=0; i < sala.nEle; i++) {
        Elemento obj = sala.conteudo[i];
        for (j=0; j < obj.nAcoes; j++) {
            if (obj.transitividade[j] == 0)
                ((func)obj.acoes[j])(NULL, NULL);
            else if (obj.transitividade[j] == 1)
                ((func)obj.acoes[j])(&obj, NULL);
            else 
                ((func)obj.acoes[j])(&obj, &obj);
        }
    }
}

int main() {
    // TESTE: CRIAR
    printf("TESTE: CRIAR\n");
    TabSim t = cria(17);
    printf("%s\n\n", (t!=NULL ? "Tabela criada e sucesso na criação das listas!" : "Erro ao criar tabela!"));

    // Criação dos elementos
    Elemento *el0 = criaElemento("dragao com asas de fogo"); // Elemento para testar colisão e possui dois nomes
    Elemento *el1 = criaElemento("dragao com colisao"); // Elemento para testar colisão
    Elemento *el2 = criaElemento("elemento teste");



    // TESTE: INSERIR
    printf("TESTE: INSERIR\n");
    printf("%s\n", (insere(t, "dragao", el0) ? "Sucesso ao inserir dragao!" : "Erro ao inserir dragao!"));
    printf("%s\n", (insere(t, "feioso", el0) ? "Sucesso ao inserir feioso!" : "Erro ao inserir feioso!"));
    printf("%s\n\n", (insere(t, "gaodra", el1) ? "Sucesso ao inserir gaodra!" : "Erro ao inserir gaodra!"));



    // TESTE: BUSCAR
    printf("TESTE: BUSCAR\n");
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

    // TESTE: RETIRAR
    printf("TESTE: RETIRAR\n");
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

    /* ============================================ */

    Elemento sala1 = criarSala1();
    testarSala(sala1);

    return 0;
}

    /* d(- _ -)b */