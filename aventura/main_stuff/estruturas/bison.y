%{
#include <stdio.h>
#include "../headers/elemento.h"
#include "../headers/lista_ligada.h"
#include "../headers/tabela_de_sim.h"

int yylex();
int yyerror(char *);

%}

%union {
    Elemento *ele;
    char *str;
}

%token <ele> OBJ INVENT
%token <ele> LOBBY SALA1 SALA2 SALA3 SALA4 SALA5
%token <str> NONE /* palavra inválida */
%token <str> NONVERBO EXAMINAR IRPARA PEGAR LARGAR QUEBRAR ATRAIR COLOCAR ALIMENTAR LIGAR TENTAR
%token EOL

%type <ele> obj


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

    | NONVERBO obj           { printf("Eu não understand o que você falou!\n"); } eol
    | NONVERBO NONE          { printf("Você quer %s o quê?\n", $1); } eol
    | NONVERBO obj NONE      { printf("Não vejo nada por aqui.\n", $3); } eol
    | NONVERBO NONE NONE     { printf("WTF?\n"); } eol
;

obj:  OBJ                    { $$ = $1; }
    | LOBBY                  { $$ = $1; }
    | SALA1                  { $$ = $1; }
    | SALA2                  { $$ = $1; }
    | SALA3                  { $$ = $1; }
    | SALA4                  { $$ = $1; }
    | SALA5                  { $$ = $1; }
;


desconhecido: NONE           { printf("O que é %s?\n", $1); } eol
;


eol: EOL                     { return 1; }
;

%%

/* Não se encaixa em nenhuma regra */
int yyerror(char *s) {
    printf("Não entendi o que disseste...\n");
    return 0;
}
