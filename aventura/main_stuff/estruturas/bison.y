%{
#include <stdio.h>
#include "../headers/elemento.h"
#include "../headers/lista_ligada.h"
#include "../headers/tabela_de_sim.h"

int yylex();
int yyerror(char *);

func verbo;
%}

%union {
    Elemento *ele;
    char *str;
}

%token <ele> OBJ
%token <ele> LOBBY FIBONACCI BINARIA GALINHADA PASCAL NEPAL
%token <str> VERBO NONE /* palavra inválida */
%token EOL

%type <ele> obj
%type <ele> lugar


%%

input: EOL | cmd | lugar | obj
;

cmd:  VERBO             { printf("%s?\n", $1); } eol
    | VERBO obj         { printf("VERBO---%s?\n", $1);
                            printf("yylval: nadaaa\n");
                            return 1;
                        }
    | VERBO obj obj     {  } eol
    | VERBO lugar       {  } eol
    | VERBO NONE        { printf("Você quer z%sz o quê?\n", $1);} eol
    | VERBO obj NONE    { printf("Não vejo nada por aqui.\n"); } eol
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
