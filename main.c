#include "elemento.h"

Elemento criarElemento(char *nome, char *curta,
    char *longa, boolean visivel, boolean conhecido,
    Elemento *conteudo, void **acoes,
    void *animacao, Info detalhe) {

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

typedef void (*checar)(boolean);
void checarRelogio(boolean estaComPonteiro) {
    printf("São 8 horas e ... minutos.\n");
    if (estaComPonteiro)
        printf("Que horas são?\n");   
}

int main() {
    Elemento chave =
    criarElemento("Chave",
        "Chave velha",
        "Chave velha e suja", False, False, NULL,
        NULL, NULL, unionaqui);

    Elemento *conteudoConcha = malloc(sizeof(Elemento));
    conteudoConcha[0] = chave;

    Elemento concha =
    criarElemento("Concha",
        "Concha espiralada",
        "Concha espiralada e oca", False, False, conteudoConcha,
        NULL, NULL, unionaqui);

    Elemento porta =
    criarElemento("Porta",
        "Porta trancada",
        "Porta oxidada e trancada", False, False, NULL,
        NULL, NULL, unionaqui);

    Elemento ponteiro =
    criarElemento("Ponteiro",
        "Ponteiro dos minutos",
        "Ponteiro dos minutos no chão", False, False, NULL,
        NULL, NULL, unionaqui);

    void **acoesRelogio = malloc(sizeof(checar));
    acoesRelogio[0] = checarRelogio;

    Elemento relogio =
    criarElemento("Relogio",
        "Minutos inoperantes",
        "Sem o ponteiro dos minutos, com o ponteiro das horas
        apontando para o 8", False, False, NULL,
        NULL, NULL, unionaqui);


    Info unionS1;
    unionS1.saidas = malloc(sizeof(Elemento));
    unionS1.saidas[0] = sala2;

    Elemento *conteudoS1 = malloc(5*sizeof(Elemento));
    conteudoS1[0] = relogio;
    conteudoS1[1] = ponteiro;
    conteudoS1[2] = porta;
    conteudoS1[3] = concha;
    conteudoS1[4] = chave;

    Elemento sala1 =
    criarElemento("Fibonacci",
        "Há um ponteiro no chão",
        "Há um relógio quebrado
        e um ponteiro no chao, uma mensagem
        na parede, uma concha em um pilar e uma
        porta fechada", False, False, conteudoS1, NULL, NULL,
        unionS1);

    return 0;
}
