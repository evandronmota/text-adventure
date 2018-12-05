%{
#include <stdio.h>
#include "../headers/elemento.h"
#include "../headers/aventureiro.h"
#include "../headers/lista_ligada.h"
#include "../headers/salas.h"
#include "../headers/tabela_de_sim.h"

int yylex();
int yyerror(char *);

%}

%union {
    struct ele *ele;
    char *str;
}

%token <ele> OBJ INVENT
%token <ele> LOBBY SALA1 SALA2 SALA3 SALA4 SALA5
%token <str> NONE /* palavra inválida */
%token <str> NONVERBO EXAMINAR IRPARA PEGAR LARGAR QUEBRAR ATRAIR COLOCAR ALIMENTAR LIGAR TENTAR
%token EOL

%type <ele> obj

%defines

%%

input: cmd | obj | desconhecido | eol
;

cmd:  EXAMINAR obj           { examinar($2, NULL); } eol
    | IRPARA obj             { trocarLugar($2, NULL); } eol
    | PEGAR obj              { pegar($2, NULL); } eol
    | LARGAR obj             { largar($2, NULL); } eol
    | QUEBRAR obj            { quebrar($2, NULL); } eol
    | ATRAIR obj NONE obj    { atrair($2, $4); } eol
    | COLOCAR obj NONE obj   { colocar($2, $4); } eol
    | ALIMENTAR obj NONE obj { alimentar($2, $4); } eol
    | LIGAR obj NONE obj     { ligar($2, $4); } eol
    | TENTAR obj NONE        { tentarSenha($2, $3); } eol

    | INVENT                 { olharMochila(NULL, NULL); } eol

    | NONVERBO obj           { printf("Eu não understand o que você falou!"); } eol
    | NONVERBO NONE          { printf("Você quer %s o quê?", $1); } eol
    | NONVERBO obj NONE      { printf("Não vejo nada por aqui.", $3); } eol
    | NONVERBO NONE NONE     { printf("WTF?"); } eol
;


obj:  OBJ                    { $$ = $1; }
    | LOBBY                  { $$ = $1; }
    | SALA1                  { $$ = $1; }
    | SALA2                  { $$ = $1; }
    | SALA3                  { $$ = $1; }
    | SALA4                  { $$ = $1; }
    | SALA5                  { $$ = $1; }
;


desconhecido: NONE           { printf("O que é %s?", $1); } eol
;


eol: EOL { printf("\n"); return 1; }
;

%%

/* Não se encaixa em nenhuma regra */
int yyerror(char *s) {
    printf("Algo de certo não está errado ...\n");
    return 0;
}
