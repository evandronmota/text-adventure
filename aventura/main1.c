#include <stdlib.h>
#include <stdio.h>
#include "elemento.h"
#include "lista_ligada.h"
#include "tabela_de_sim.h"
#include "salas.h"

int main() {
    Elemento salaFib = criarSala1();
    TabSim tab = cria(97);
    int i;
    /* ((func)salaFib.conteudo[0].acoes[0])(&salaFib, NULL); */

    /* mundo criado */

    /* elemento da vez */
    Elemento *sala1 = &salaFib;
    insere(tab, "sala 1", sala1);
    for (i = 0; i<sala1->nEle; i++)
        insere(tab, sala1->conteudo[i].n, &sala1->conteudo[i]); /* Insere objetos na tabela */

    while (True) {
        ((func)sala1->conteudo[0].acoes[0])(&sala1->conteudo[0], NULL);
        examinar(sala1, NULL);
        
        for (i = 0; i<sala1->nEle; i++){
            nomear(sala1->conteudo[i]);
            printf("%s\n", busca(tab, sala1->conteudo[i].n)->curta); /* Testa a busca pelo elemento na tabela */
        }

        /* se for valido atualiza o auxiliar */
        /* se nao, manda uma msg de erro e nao atualiza o auxiliar */
        getchar();
    }

    return 0;
}
