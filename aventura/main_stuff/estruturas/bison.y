%{
#include <stdio.h>
#include "../headers/elemento.h"
#include "../headers/aventureiro.h"
#include "../headers/lista_ligada.h"
#include "../headers/salas.h"
#include "../headers/tabela_de_sim.h"

int yylex();
int yyerror(char *);

func verbo;
%}

%union {
    struct ele *ele;
    char *str;
}

%token <ele> OBJ INVENT
%token <ele> LOBBY SALA1 SALA2 SALA3 SALA4 SALA5
%token <str> NONE /* palavra inválida */
%token <str> VERBO EXAMINAR IRPARA PEGAR LARGAR QUEBRAR ATRAIR COLOCAR ALIMENTAR LIGAR TENTAR
%token EOL

%type <ele> obj

%defines

%%

input: cmd | obj | desconhecido | eol
;

cmd:  EXAMINAR obj           { examinar($2, NULL);printf("\n"); } eol
    | IRPARA obj             { trocarLugar($2, NULL); }
    | PEGAR obj              { pegar($2, NULL); }
    | LARGAR obj             { largar($2, NULL); }
    | QUEBRAR obj            { quebrar($2, NULL); }
    | ATRAIR obj             { atrair($2, NULL); }
    | COLOCAR obj            { colocar($2, NULL); }
    | ALIMENTAR obj          { alimentar($2, NULL); }
    | LIGAR obj              { ligar($2, NULL); }
    | TENTAR obj NONE        { tentarSenha($2, $3); }

    | INVENT                 { olharMochila(NULL, NULL); }

    | VERBO NONE             { printf("Você quer %s o quê?\n", $1); return 1;}
    | VERBO obj NONE         { printf("Não vejo nada por aqui.\n", $3); } eol
    | VERBO NONE NONE        { printf("WTF?\n"); } eol
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


eol: EOL { return 1; }
;

%%

/* Não se encaixa em nenhuma regra */
int yyerror(char *s) {
    printf("\nERRO: %s!\n", s);
    return 0;
}
