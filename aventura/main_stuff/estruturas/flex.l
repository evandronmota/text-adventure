%{
#include "../headers/elemento.h"
#include "../headers/aventureiro.h"
#include "../headers/lista_ligada.h"
#include "../headers/tabela_de_sim.h"
#include "../headers/init_salas.h"
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

\n {return EOL;}

lobby   printf("LOBBY: %s\n", yytext);

bin(á|a)ria printf("BINARIA: %s\n", yytext);

pascal  printf("PASCAL: %s\n", yytext);

nepal   printf("NEPAL: %s\n", yytext);

fibonacci   printf("FICONACCI: %s\n", yytext);

galinhada   printf("GALINHADA: %s\n", yytext);

[a-zA-Z]+r { printf("verbozao");yylval.verbo = examinar;
            return VERBO;}

[a-zA-Z]+[^r\n] { Elemento* e = busca(tabela, yytext);
                    if (e != NULL) {
                        printf("OBJ");
                        yylval.ele = e;
                        return OBJ;
                    } else {
                        yylval.str = yytext;
                        printf("yylval.str: %s", yylval.str);
                        return NONE;
                    }
                }

.   printf("NONE: %s\n", yytext);

