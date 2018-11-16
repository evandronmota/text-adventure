#include <stdlib.h>
#include "../libraries/elemento.h"
#include "../libraries/lista_ligada.h"

/*
    Cria uma lista ligada. Retorna a lista criada.
*/
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

/*
    Recebe uma lista ligada. Destroi a lista
    recebida.
*/
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

/*
    Recebe uma lista ligada e um ponteiro para
    um elemento. Insere nessa lista o elemento
    recebido.
*/
Lista insereL(Lista l, Elemento *val) {
    Lista new = criaL();
    if (new == NULL)
        return NULL;
    new->next = l->next;
    new->val = val;
    l->next = new;

    return new;
}

/*
    Recebe uma lista ligada e uma string. Realiza
    uma busca nessa lista a partir da string
    recebida. Retorna um ponteiro para o elemento
    associado a tal string, em caso de sucesso, ou
    NULL, caso contrário.
*/
Elemento *buscaL(Lista l, char *n) {
    Lista p = l->next;
    while (p != NULL) {
        if (p->nome == n)
            return p->val;
        p = p->next;
    }
    return NULL;
}

/*
    Recebe uma lista ligada e um ponteiro para um
    elemento. Remove esse elemento da lista recebida.
    Retorna um ponteiro para tal elemento, em caso
    de sucesso, ou NULL, caso contrário.
*/
Elemento *retiraL(Lista l, Elemento *val) {
    Lista p = l->next;
    if (p==NULL)
        return NULL;
    l->next = p->next;
    return p->val;
}
