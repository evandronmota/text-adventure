#include <stdlib.h>
#include "../headers/elemento.h"
#include "../headers/lista_ligada.h"

Lista criaL() {
    Lista l = malloc(sizeof(struct elo));
    l->nome = malloc(sizeof(char));
    if (l == NULL || l->nome==NULL)
        return NULL;
    l->nome = NULL;
    l->prox = NULL;
    l->val = NULL;
    return l;
}

void destroiL(Lista l) {
    Lista p = l->prox;  
    Lista aux;
    free(l);
    while (p != NULL) {
        aux = p->prox;
        free(p);
        p = aux;
    }
    free(p);
}

Lista insereL(Lista l, Elemento *val) {
    Lista new = criaL();
    if (new == NULL)
        return NULL;
    new->prox = l->prox;
    new->val = val;
    l->prox = new;

    return new;
}

Elemento *buscaL(Lista l, char *n) {
    Lista p = l->prox;
    while (p != NULL) {
        if (p->nome == n)
            return p->val;
        p = p->prox;
    }
    return NULL;
}

Elemento *retiraL(Lista l, Elemento *val) {
    Lista p = l->prox;
    if (p==NULL)
        return NULL;
    l->prox = p->prox;
    return p->val;
}
