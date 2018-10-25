#include "elemento.h"

Elemento criarElemento(char *nome, char *curta,
    char *longa, boolean visivel, boolean conhecido,
    Elemento *conteudo, void **acoes,
    void *animacao, Info detalhe) {

    // tipo 0 = lugar;
    // tipo 1 = objeto;
    Elemento novo;

    novo.n = nome;
    novo.curta = curta;
    novo.longa = longa;
    novo.ativo = True;
    novo.visivel = visivel;
    novo.conhecido = conhecido;
    novo.conteudo = conteudo;
    novo.acoes = acoes;
    novo.animacao = animacao;
    novo.detalhe = detalhe;
}

int main() {
    Elemento relogio =
    criarElemento("Relogio",
    "Quebrado",
    "Sem o ponteiro dos minutos, com o ponteiro das horas
    apontando para o 8", False, False, NULL, NULL, NULL,
    unionaqui);


    Elemento sala1 =
    criarElemento("Fibonacci",
    "Há um ponteiro no chão",
    "Há um relógio quebrado
    e um ponteiro no chao, uma mensagem
    na parede, uma concha em um pilar e uma
    porta fechada", False, False, NULL, NULL, NULL,
    unionaqui);

    Elemento sala1;
    sala1.n = "Fibonacci";
    sala1.curta = "Há um ponteiro no chão";
    longa = "Há um relógio quebrado
    e um ponteiro no chao, uma mensagem
    na parede, uma concha em um pilar e uma
    porta fechada";
    sala1.ativo = True;
    sala1.visivel = False;
    sala1.conhecido = False;
    sala1.conteudo = malloc(5*sizeof(Elemento));
    sala1.acoes = NULL;
    sala1.animacao = NULL;

    return 0;
}
