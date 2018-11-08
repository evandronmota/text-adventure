#include <stdlib.h>
#include <stdio.h>
#include "elemento.h"
#include "lista_ligada.h"
#include "tabela_de_sim.h"
#include "salas.h"

int main() {
    Elemento salaFib = criarSala1();
    int i;

    /* ((func)salaFib.conteudo[0].acoes[0])(&salaFib, NULL); */

    /* mundo criado */

    /* elemento da vez */
    Elemento *aux = &salaFib;

    while (True) {
        ((func)aux->conteudo[0].acoes[0])(&aux->conteudo[0], NULL);
        examinar(aux, NULL);
        
        for (i = 0; i<aux->nEle; i++)
            nomear(aux->conteudo[i]);

        /* se for valido atualiza o auxiliar */
        /* se nao, manda uma msg de erro e nao atualiza o auxiliar */
        getchar();
    }

    return 0;
}
