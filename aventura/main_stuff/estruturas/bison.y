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
    func verbo;
}

%token <ele> OBJ
%token <ele> LOBBY FIBONACCI BINARIA GALINHADA PASCAL NEPAL
%token <str> NONE /* palavra inválida */
%token <str> VERBO
%token EOL

%type <ele> obj
%type <ele> lugar

%defines

%%

input: cmd | lugar | obj | desconhecido | eol
;

cmd:  VERBO             {  } eol
    | VERBO obj         { examinar($2, NULL); } eol
    | VERBO obj obj     {  } eol
    | VERBO lugar       {  } eol
    | VERBO NONE        { printf("Você quer %s o quê?\n", $1); return 1;}
    | VERBO obj NONE    { printf("Não vejo nada por aqui.\n", $3); } eol
    | VERBO NONE NONE   { printf("WTF?\n"); } eol
;

lugar: LOBBY    { printf("lobbyzao\n");
                    return 1;
                }
    | FIBONACCI { $$ = $1; }
    | BINARIA   { $$ = $1; }
    | GALINHADA { $$ = $1; }
    | PASCAL    { $$ = $1; }
    | NEPAL     { $$ = $1; }
;

obj: OBJ { $$ = $1; }
;


desconhecido: NONE  { printf("O que é %s?\n", $1); } eol
;

eol: EOL { return 1; }
;

%%
/* Não se encaixa em nenhuma regra */
int yyerror(char *s) {
    printf("Impossível compreender.\n");
    return 0;
}
