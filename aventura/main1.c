#include <stdlib.h>
#include <stdio.h>
#include "elemento.h"
//#include "tabela_de_sim.h"
#include "lista_ligada.h"
#include "salas.h"

int main() {
    Elemento salaFib = criarSala1();
    int i;

    /* 
    conteudoS1[0] = relogio;
    conteudoS1[1] = ponteiro;
    conteudoS1[2] = porta;
    conteudoS1[3] = concha;
    conteudoS1[4] = chave;
    */

    // ((func)salaFib.conteudo[0].acoes[0])(&salaFib, NULL);


    /* mundo criado */


    // elemento da vez
    Elemento *aux = &salaFib;


    // while (True) {
    for (i=0; i<2; i++) { // MOSTRA DESCRIÇÃO DUAS VEZES PARA TESTAR LONGA E CURTA
        descricao(*aux);
        
        aux->conhecido = True;

        // recebe comando
        // scanf()

        // se for valido atualiza o auxiliar

        // se nao, manda uma msg de erro e nao atualiza o auxiliar

    }

    return 0;
}
