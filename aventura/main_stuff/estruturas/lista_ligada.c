#include <stdlib.h>
#include "../headers/elemento.h"
#include "../headers/lista_ligada.h"

Lista criaL() {
    Lista l = malloc(sizeof(struct elo));
    l->nome = malloc(sizeof(char));
    if (l == NULL || l->nome==NULL)
        return NULL;
    l->nome = NULL;
    l->next = NULL;
    l->val = NULL;
    return l;
}

void destroiL(Lista l) {
    Lista p = l->next;  
    Lista aux;
    free(l);
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
    while (p != NULL) {
        if (p->nome == n)
            return p->val;
        p = p->next;
    }
    return NULL;
}

Elemento *retiraL(Lista l, Elemento *val) {
    Lista p = l->next;
    if (p==NULL)
        return NULL;
    l->next = p->next;
    return p->val;
}
