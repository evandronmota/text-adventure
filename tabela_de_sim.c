#include <stdlib.h>
#include "elemento.h"
#include "lista_ligada.h"
#include "tabela_de_sim.h"

int hash(int tam, char *key) {
    int i, sum=0;
    for (i=0; key[i]!='\0'; i++)
        sum+=key[i];
    return sum%tam;
}

TabSim cria(int tam) {
    TabSim t = malloc(sizeof(tabSim));
    t->elementos = malloc(tam*sizeof(Lista));
    int i;
    for (i=0; i<tam; i++)
        t->elementos[i] = criaL();
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
    val->apelidos[val->posLivre++] = n;
    if(insereL(t->elementos[h], val) == NULL)
        return 0;
    return 1;
}

Elemento *busca(TabSim t, char *n) {
    int h = hash(t->tam, n);
    return buscaL(t->elementos[h], n);
}

int retira(TabSim t, char *n) {
    int h = hash(t->tam, n), i;
    Elemento *el = buscaL(t->elementos[h], n);
    for (i=0; i<el->posLivre; i++) {
        h = hash(t->tam, el->apelidos[i]);
        retiraL(t->elementos[h], buscaL(t->elementos[h], el->apelidos[i]));
    }
    free(el);

    return 0;
}
