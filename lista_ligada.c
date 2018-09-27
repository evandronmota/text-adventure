#include "elemento.h"
#include <stdlib.h>
#include "lista_ligada.h"

Lista criaL() {
    Lista l = malloc(sizeof(struct node));
    if (l == NULL)
        return NULL;
    l->next = NULL;
    l->val = NULL;
    return l;
}

void destroiL(Lista l) {
    Lista p = l->next;  
    free(l);
    Lista aux;
    while (p != NULL) {
        aux = p->next;
        free(p);
        p = aux;
    }
    free(p);
}

Lista insereL(Lista l, Elemento *val) {
    Lista new = criaL();
    if (new == NULL)
        return NULL;
    new->next = l->next;
    new->val = val;
    l->next = new;

    return new;
}

Elemento *buscaL(Lista l, char *n) {
    Lista p = l->next;
    int i;
    while (p != NULL) {
        for (i=0; i < p->val->posLivre; i++)
            if (p->val->nicks[i] == n)
                return p->val;
        p = p->next;
    }
    return NULL;
}

Elemento *retiraL(Lista l, Elemento *val) {
    Lista p = l->next;
    Lista anterior = l;
    while (p != NULL) {
        if (p->val->n == val->n) {
            anterior->next = p->next;
            return p->val;
        }
        anterior = p;
        p = p->next;
    }
    return NULL;
}
