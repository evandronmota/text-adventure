%{

#include "../headers/elemento.h"
#include "../headers/lista_ligada.h"
#include "../headers/tabela_de_sim.h"
#include "bison.tab.h"

/* Para readline */
#include <readline/readline.h>
#include <readline/history.h>

/* Redefinição da entrada do Flex para usar o readline */
#define YY_INPUT(buf,result,max_size) result = mygetinput(buf, max_size);


/* Função que substitui a entrada */
static int mygetinput(char *buf, int size) {
    char *line;

    /* final de arquivo */
    if (feof(yyin))  return YY_NULL;

    /* Lê uma linha, com o prompt "> " */
    line = readline("> ");
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

(E|e)xaminar            { return EXAMINAR; }
pegar                   { return PEGAR; }
largar                  { return LARGAR; }
quebrar                 { return QUEBRAR; }
atrair                  { return ATRAIR; }
colocar                 { return COLOCAR; }
alimentar               { return ALIMENTAR; }
ligar                   { return LIGAR; }
tentar                  { return TENTAR; }
ir[ ]para               { return IRPARA; }

(i|I)(nvent((a|á)rio)?)?  { return INVENT; }

(L|l)obby               { yylval.ele = busca(tabela, yytext); return LOBBY; }
(S|s)ala[ ]1            { yylval.ele = busca(tabela, yytext); return SALA1; }
(S|s)ala[ ]2            { yylval.ele = busca(tabela, yytext); return SALA2; }
(S|s)ala[ ]3            { yylval.ele = busca(tabela, yytext); return SALA3; }
(S|s)ala[ ]4            { yylval.ele = busca(tabela, yytext); return SALA4; }
(S|s)ala[ ]5            { yylval.ele = busca(tabela, yytext); return SALA5; }

[a-zA-Z0-9]+[^r \n]        { Elemento *e = busca(tabela, yytext);
                            if (e == NULL) {
                                yylval.str = yytext;
                                return NONE;
                            } 
                            yylval.ele = e;
                            return OBJ; 
                        }
