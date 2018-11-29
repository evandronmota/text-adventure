%{
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

    /* copia para o buffer de enrtada */
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

[a-zA-Z]*[aeioAEIO]r$ {printf("VERBO: %s\n", yytext);}

[a-zA-Z]*[^r]$ {printf("Substantivo %s\n", yytext);}

%%

main() {
    yylex();

}
