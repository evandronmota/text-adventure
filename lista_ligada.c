#include "elemento.h"
#include <stdlib.h>
#include "lista_ligada.h"

Lista criaL() {
    Lista l = malloc(sizeof(struct no));
    if (l == NULL)
        return NULL;
    l->prox = NULL;
    l->val = NULL;
    return l;
}

void destroiL(Lista l) {
    Lista p = l->prox;  
    free(l);
    Lista aux;
    while (p != NULL) {
        aux = p->prox;
        free(p);
        p = aux;
    }
    free(p);
}

Lista insereL(Lista l, Elemento *val) {
    Lista novo = criaL();
    if (novo == NULL)
        return NULL;
    novo->prox = l->prox;
    novo->val = val;
    l->prox = novo;

    return novo;
}

Elemento *buscaL(Lista l, char *n) {
    Lista p = l->prox;
    int i;
    while (p != NULL) {
        for (i=0; i < p->val->posLivre; i++)
            if (p->val->apelidos[i] == n)
                return p->val;
        p = p->prox;
    }
    return NULL;
}

Elemento *retiraL(Lista l, Elemento *val) {
    Lista p = l->prox;
    Lista anterior = l;
    while (p != NULL) {
        if (p->val->n == val->n) {
            anterior->prox = p->prox;
            return p->val;
        }
        anterior = p;
        p = p->prox;
    }
    return NULL;
}
