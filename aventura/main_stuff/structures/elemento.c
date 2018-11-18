#include <stdlib.h>
#include <stdio.h>
#include "../libraries/elemento.h"

void nome(Elemento e) {   
    printf("%c%c%c %s.\n", e.artigo[0]-32, e.artigo[1], e.artigo[2], e.n);
}

int examinar(Elemento *e1, Elemento *e2) {
    if (e1 == NULL)
        printf("Examinar o quê?\n");
    else if (e1->conhecido)
        printf("%s\n", e1->curta);
    else {
        printf("%s\n", e1->longa);
        e1->conhecido = True;
    }

    return (e1 == NULL ? 0 : 1);
}

int pegar(Elemento *e1, Elemento *e2) {
    if (e1 == NULL)
        printf("Pegar o quê?\n");
    else  {
        if (e1->detalhe.atributos[1].valor.valor_estado)
            printf("Você pegou %s %s.\n", e1->artigo, e1->n);
        else printf("Você não pode pegar %s %s.\n", e1->artigo, e1->n);
    }

    return (e1 == NULL ? 0 : 1);
}

int largar(Elemento *e1, Elemento *e2) {
    if (e1 == NULL)
        printf("Largar o quê?\n");
    else {
        if (e2 == NULL)
            printf("Você largou %s %s.\n", e1->artigo, e1->n);
        else
            printf("Você %s %s n%s %s.\n", e1->artigo, e1->n, e2->artigo, e2->n);
    }

    return (e1 == NULL ? 0 : 1);
}

int quebrar(Elemento *e1, Elemento *e2) {
    int i;

    /* Elementos NULL */
    if (e1 == NULL)
        printf("Quebrar o quê?\n");
    else {
        /* Quebrar sem elemento e2 */
        if (e2 == NULL) {
            for (i=0; i<e1->nAtr; i++) { /* Procura atributo */
                if (e1->detalhe.atributos[i].nome == "estaQuebrada") { /* Acha estaQuebrada */
                    if (e1->detalhe.atributos[i].valor.valor_estado == False) { /* Se não está quebrada */
                        e1->detalhe.atributos[i].valor.valor_estado = True;
                        printf("Você quebrou %s %s!\n", e1->artigo, e1->n);
                        if (e1->n == "Concha") {
                            /* Colocar na mochila do Aventureiro */
                            e1->nEle--;
                            free(e1->conteudo);
                        }

                    }
                    else /* Se está quebrada */
                        printf("Você já quebrou %s %s!\n", e1->artigo, e1->n);
                    break;
                }
            }
        }
        // else {
        //     /* Quebrar com algo */
        // }
    }

    return (e1 == NULL ? 0 : 1);
}

int colocarSobre(Elemento *e1, Elemento *e2) {
    if (e1 == NULL)
        printf("Colocar o quê?\n");
    else if (e2 == NULL)
        printf("Colocar onde?\n");
    else {
        printf("Você colocou %s %s n%s %s.\n", e1->artigo, e1->n, e2->artigo, e2->n);
        adicionarElemento(e1, e2);
    }

    return (e1 == NULL || e2 == NULL ? 0 : 1);
}

// int ligar(Elemento *e1, Elemento *e2) {
//     if (e1 == NULL)
//         printf("Ligar o quê?\n");
//     else {
//         if (e2 != NULL)
            
//         else {
//             printf("Não é possível fazer isso.\n")
//         }
//     }

//     return (e1 == NULL || e2 == NULL ? 0 : 1);
// }