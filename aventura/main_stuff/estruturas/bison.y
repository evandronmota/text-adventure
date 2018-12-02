%{
#include <stdio.h>
#include "../headers/elemento.h"
  
int yylex();
int yyerror(char *);
%}

%union {
    Elemento *ele;
    char *str;
    func verbo;
}

%token <ele> OBJ
%token <str> NONE /* palavra inválida */
%token <str> LOBBY FIBONACCI BINARIA GALINHADA PASCAL NEPAL
%token <verbo> VERBO

%type <ele> lugar

%defines

%%
cmd: VERBO              { $1(NULL, NULL); }
    | VERBO OBJ         { $1($2, NULL); }
    | VERBO OBJ OBJ     { $1($2, $3); }
    | VERBO lugar       { if(%1 == trocarLugar) {
                                %1(%2, NULL);
                            }
                        }
    | VERBO NONE        { printf("Mas o que é %s?", $2); }
    | VERBO OBJ NONE    { printf("Não vejo %s por aqui.", $3); }
    | VERBO NONE NONE   { printf("WTF?"); }
;

lugar: LOBBY        { $$ = $1; }
        | FIBONACCI { $$ = $1; }
        | BINARIA   { $$ = $1; }
        | GALINHADA { $$ = $1; }
        | PASCAL    { $$ = $1; }
        | NEPAL     { $$ = $1; }
        | NONE      { printf("Lugar inválido.\n"); $$ = NULL}
;

%%
/* Não se encaixa em nenhuma regra */
int yyerror(char *s) {
  printf("Impossível compreender.\n");
  return 0;
}
