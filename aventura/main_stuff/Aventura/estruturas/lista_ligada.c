#include <stdlib.h>
#include <string.h>
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

Lista insereL(Lista l, void *val) {
    Lista new = criaL();
    if (new == NULL)
        return NULL;
    new->prox = l->prox;
    new->val = val;
    l->prox = new;

    return new;
}

void *buscaL(Lista l, char *n) {
    Lista p = l->prox;
    while (p != NULL) {
        if (!strcmp(p->nome, n))
            return p->val;
        p = p->prox;
    }
    return NULL;
}

void *retiraL(Lista l, void *val) {
    Lista p = l->prox;
    if (p==NULL)
        return NULL;
    l->prox = p->prox;
    return p->val;
}
