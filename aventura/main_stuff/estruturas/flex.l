%{
#include "../headers/elemento.h"
#include "../headers/lista_ligada.h"
#include "../headers/tabela_de_sim.h"
#include "bison.tab.h"
#include <string.h>

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

lobby   { return LOBBY;}

bin(á|a)ria printf("BINARIA: %s\n", yytext);

pascal  printf("PASCAL: %s\n", yytext);

nepal   printf("NEPAL: %s\n", yytext);

fibonacci   printf("FIBONACCI: %s\n", yytext);

galinhada   printf("GALINHADA: %s\n", yytext);

[a-zA-Z]+r {
            char* txt = malloc(strlen(yytext));
            strcpy(txt, yytext);
            yylval.str = yytext;
            printf("verbo yytext: z%sz\n", yytext);
            return VERBO; }

[a-zA-Z]+[^r \n]    { Elemento *e = busca(tabela, yytext);
                        if (e == NULL) {
                            yylval.str = NULL;
                            yylval.str = yytext;
                            printf("none yytext: z%sz\n", yytext);
                            return NONE;
                        } 
                        yylval.ele = e;
                        return OBJ; 
                    }

