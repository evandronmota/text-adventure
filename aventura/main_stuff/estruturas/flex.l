%{

#include <string.h>
#include "../headers/elemento.h"
#include "../headers/lista_ligada.h"
#include "../headers/tabela_de_sim.h"
#include "bison.tab.h"

/* Para readline */
#include <readline/readline.h>
#include <readline/history.h>

/* Redefinição da entrada do Flex para usar o readline */
#define YY_INPUT(buf,result,max_size) result = mygetinput(buf, max_size);

#define RESET   "\033[0m"
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */

/* Função que substitui a entrada */
static int mygetinput(char *buf, int size) {
    char *line;

    /* final de arquivo */
    if (feof(yyin))  return YY_NULL;

    /* Lê uma linha, com o prompt "> " */
    line = readline( BOLDMAGENTA "\n> " RESET);
    if(!line)        return YY_NULL;

    /* segurança */
    if(strlen(line) > size-2){
        fprintf(stderr,"input line too long\n");
        return YY_NULL;
    }

    /* copia para o buffer de entrada */
    sprintf(buf,"%s\n",line);
    /* adiciona ao histórico */
    add_history(line);

    /* libera memória */
    free(line);
    return strlen(buf);
}

%}

%option caseless

%%

\n  { return EOL; }

examinar                { return EXAMINAR; }
pegar                   { return PEGAR; }
largar                  { return LARGAR; }
quebrar                 { return QUEBRAR; }
atrair                  { return ATRAIR; }
colocar                 { return COLOCAR; }
alimentar               { return ALIMENTAR; }
ligar                   { return LIGAR; }
tentar                  { return TENTAR; }
listar                  { return LISTAR; }
ir[ ]para               { return IRPARA; }

(invent((a|á)rio)?)?    { return INVENT; }

lobby                   { yytext[0] = toupper(yytext[0]); yylval.ele = busca(tabela, yytext); return LOBBY; }
sala[ ]1                { yytext[0] = toupper(yytext[0]); yylval.ele = busca(tabela, yytext); return SALA1; }
sala[ ]2                { yytext[0] = toupper(yytext[0]); yylval.ele = busca(tabela, yytext); return SALA2; }
sala[ ]3                { yytext[0] = toupper(yytext[0]); yylval.ele = busca(tabela, yytext); return SALA3; }
sala[ ]4                { yytext[0] = toupper(yytext[0]); yylval.ele = busca(tabela, yytext); return SALA4; }
sala[ ]5                { yytext[0] = toupper(yytext[0]); yylval.ele = busca(tabela, yytext); return SALA5; }

[a-z]+r                 { yylval.str = yytext; return NONVERBO; }

[a-zçáéíóúâêîôû0-9]+[^r \n]        { 
                            yytext[0] = toupper(yytext[0]);
                            Elemento *e = busca(tabela, yytext);
                            if (e == NULL) {
                                yylval.str = yytext;
                                return NONE;
                            }
                            yylval.ele = e;
                            return OBJ; 
                        }
