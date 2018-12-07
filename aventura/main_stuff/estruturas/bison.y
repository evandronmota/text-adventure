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
%token <str> NONVERBO EXAMINAR IRPARA PEGAR LARGAR QUEBRAR ATRAIR COLOCAR ALIMENTAR LIGAR TENTAR LISTAR DEFINIR
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
    | TENTAR obj obj         { printf("%s não é uma senha! ", $3->n); } eol
    | LISTAR                 { listarElementos(NULL, NULL); } eol

    | INVENT                 { olharMochila(NULL, NULL); } eol

    | NONVERBO obj           { printf("Eu não understand o que você falou!"); } eol
    | NONVERBO obj NONE obj  { printf("Você não pode fazer isso!"); } eol
    | NONVERBO obj obj       { printf("Acho melhor você reler as instruções!"); } eol
    | NONVERBO NONE          { printf("Você quer %s o quê?", $1); } eol
    | NONVERBO NONE NONE     { printf("WTF?"); } eol

    | DEFINIR EXAMINAR       { printf("É um verbo!"); } eol
    | DEFINIR PEGAR          { printf("É um verbo!"); } eol
    | DEFINIR LARGAR         { printf("É um verbo!"); } eol
    | DEFINIR QUEBRAR        { printf("É um verbo!"); } eol
    | DEFINIR ATRAIR         { printf("É um verbo!"); } eol
    | DEFINIR COLOCAR        { printf("É um verbo!"); } eol
    | DEFINIR ALIMENTAR      { printf("É um verbo!"); } eol
    | DEFINIR LIGAR          { printf("É um verbo!"); } eol
    | DEFINIR TENTAR         { printf("É um verbo!"); } eol
    | DEFINIR LISTAR         { printf("É um verbo!"); } eol
    | DEFINIR DEFINIR        { printf("É um verbo!"); } eol
    | DEFINIR NONE           { printf("Isso não existe!"); } eol
    | DEFINIR NONVERBO       { printf("Isso não existe!"); } eol
    | DEFINIR obj            { printf("É um substantivo!"); } eol
    | DEFINIR INVENT         { printf("É um substantivo!"); } eol
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


eol: EOL                     { printf("\n"); return 1; }
;


%%

/* Não se encaixa em nenhuma regra */
int yyerror(char *s) {
    printf("Não entendi o que você disse ...");
    return 0;
}
