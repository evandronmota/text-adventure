%{

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

[\t\n]

lobby   printf("LOBBY: %s\n", yytext);

bin(á|a)ria printf("BINARIA: %s\n", yytext);

pascal  printf("PASCAL: %s\n", yytext);

nepal   printf("NEPAL: %s\n", yytext);

fibonacci   printf("FICONACCI: %s\n", yytext);

galinhada   printf("GALINHADA: %s\n", yytext);

[a-zA-Z]+r printf("VERBO: %s\n", yytext);

[a-zA-Z]+[^r\n]  printf("OBJ: %s\n", yytext);

.   printf("NONE: %s\n", yytext);
