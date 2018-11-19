#include <stdlib.h>
#include "../headers/elemento.h"
#include "../headers/lista_ligada.h"
#include "../headers/tabela_de_sim.h"

/* 
    Recebe o tamanho da tabela de símbolos e uma
    string. Gera um número entre 0 e tam-1 
    (inclusive) a partir da string recebida.
    Retorna o número gerado.
*/
int hash(int tam, char *chave) {
    int i, soma=0;
    for (i=0; chave[i]!='\0'; i++)
        soma+=chave[i];
    return soma%tam;
}

TabSim cria(int tam) {
    TabSim t = malloc(sizeof(tabSim));
    t->elementos = malloc(tam*sizeof(Lista));
    if (t==NULL || t->elementos==NULL)
        return NULL;
    int i;
    for (i=0; i<tam; i++) {
        t->elementos[i] = criaL();
        if (t->elementos[i]==NULL)
            return NULL;
    }
    t->tam = tam;
    return t;
}

void destroi(TabSim t) {
    int i;
    for (i=0; i < t->tam; i++)
        destroiL(t->elementos[i]);
    free(t);
}

int insere(TabSim t, char *n, Elemento *val) {
    int h = hash(t->tam, n);
    Lista l = insereL(t->elementos[h], val);
    if (l == NULL)
        return 0;
    l->nome = n;
    return 1;
}

Elemento *busca(TabSim t, char *n) {
    int h = hash(t->tam, n);
    return buscaL(t->elementos[h], n);
}

int retira(TabSim t, char *n) {
    int h = hash(t->tam, n);
    Elemento *el = busca(t, n);
    if (el==NULL)
        return 0;
    Lista l = t->elementos[h];

    Lista p = l->next;
    while (p != NULL) {
        if (p->nome == n) {
            if (retiraL(l, el)==NULL) {
                free(p->nome);
                return 0;
            }
            return 1;
        }
        l = p;
        p = p->next;
    }

    return 0;
}