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
%token <verbo> VERBO

%type <ele> obj
%type <ele> lugar

%defines

%%

cmd:    VERBO              { $1(NULL, NULL); }
    |   VERBO obj         { examinar($2, NULL); }
    |   VERBO obj obj     { $1($2, $3); }
    |   VERBO lugar       { if($1 == trocarLugar)
                                $1($2, NULL);                    
                        }
    |   VERBO NONE        { printf("Mas o que é %s?\n", $2); }
    |   VERBO obj NONE    { printf("Não vejo nada por aqui.\n", $3); }
    |   VERBO NONE NONE   { printf("WTF?\n"); }
;

lugar: LOBBY        { printf("testi\n"); }
        | FIBONACCI { $$ = $1; }
        | BINARIA   { $$ = $1; }
        | GALINHADA { $$ = $1; }
        | PASCAL    { $$ = $1; }
        | NEPAL     { $$ = $1; }
;

obj:    OBJ     { $$ = $1;}
;

%%
/* Não se encaixa em nenhuma regra */
int yyerror(char *s) {
    printf("Impossível compreender %s.\n", s);
    return 0;
}
