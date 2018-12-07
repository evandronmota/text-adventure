
/* Define o tipo boolean */
typedef enum {
    False, True
} boolean;


/* Union para o tipo de atributo */
typedef union {
    boolean valor_estado;
    int valor_num;
    char *valor_str;
} atr_val;


/* Atributos de um objeto */
typedef struct {
    char *nome; /* Nome do atributo */
    atr_val valor;
} obj_atr;


/* Saídas */
typedef struct {
    struct ele *saida;
    boolean esta_fechada;
} saidas;


/*
    Union para atributos específicos de sala
    e objeto.
*/
typedef union {
    obj_atr *atributos;
    saidas **saidas;
} Info;


/* Elemento */
typedef struct ele {
    char *artigo;
    char *n;
    char *curta;
    char *longa;
    boolean isObjeto;
    boolean ativo;
    boolean visivel;
    boolean conhecido;
    struct ele *conteudo;
    int nEle; /* Número de elementos na lista de conteúdos */
    int nAcoes; /* Número de ações do elemento */
    int nAtr; /* Número de atributos do elemento */
    void **acoes;
    int *transitividade;
    /*
        0 = intransitivo
        1 = transitivo
        2 = bitransitivo
        3 = caso específico para tentarSenha (possui elemento e string como parâmetros)
    */
    void *animacao;
    Info detalhe;
} Elemento;


/* Ponteiro para as funções dos elementos */
typedef int (*func)(Elemento *e1, Elemento *e2);








/* FUNÇÕES */

/*
    Recebe um elemento. Imprime o nome do elemento
    recebido precedido de seu artigo.
*/
void nome(Elemento e);


/*
    Recebe um elemento e um atributo.
    Retorna o índice do atributo, caso não ache retorna -1.
*/
int procurarAtributo(Elemento *e1, char *atributo);


/*
    Recebe um elemento. Testa se a string key 
    corresponde a senha correta.
    Retorna um inteiro indicando se a ação foi
    bem-sucedida.
*/
int tentarGLaDOS(char *key);


/*
    Recebe dois ponteiros para elementos.
    Verifica se o objeto esta dentro da sala.
    Retorna um inteiro indicando se a ação foi
    bem-sucedida.
*/
int estaNaSala(Elemento* e, Elemento* sala);

/*
    Recebe um ponteiro para elemento.
    Retorna um inteiro indicando se validação
    ocorreu normalmente.
*/
int validar(Elemento *e);








/* VERBOS */

/*
    Recebe dois ponteiros para elementos.
    Imprime a descrição do primeiro elemento caso
    essa seja uma ação válida para ele.
    Retorna um inteiro indicando se a ação foi
    bem-sucedida.
*/
int examinar(Elemento *e1, Elemento *e2);


/*
    Recebe dois ponteiros para elementos.
    Imprime uma mensagem avisando que pegou o primeiro elemento.
    Retorna um inteiro indicando se a ação foi
    bem-sucedida.
*/
int pegar(Elemento *e1, Elemento *e2);


/*
    Recebe dois ponteiros para elementos.
    Imprime uma mensagem avisando que atraiu o primeiro elemento
    utilizando o segundo. Retorna um inteiro indicando se a ação foi
    bem-sucedida.
*/
int atrair(Elemento *e1, Elemento *e2);

/*
    Recebe dois ponteiros para elementos.
    Imprime uma mensagem avisando que o primeiro elemento
    foi largado.
    Retorna um inteiro indicando se a ação
    foi bem-sucedida.
*/
int largar(Elemento *e1, Elemento *e2);


/*
    Recebe dois ponteiros para elementos.
    Quebra o primeiro elemento com o segundo elemento.
    Retorna um inteiro indicando se a ação
    foi bem-sucedida.
*/
int quebrar(Elemento *e1, Elemento *e2);


/*
    Recebe dois ponteiros para elementos.
    Imprime uma mensagem avisando que o primeiro
    elemento foi colocado no segundo.
    Retorna um inteiro indicando se a ação foi
    bem-sucedida.
*/
int colocar(Elemento *e1, Elemento *e2);


/*
    Recebe dois ponteiros para elementos.
    Imprime uma mensagem avisando que o primeiro
    elemento foi alimentado usando o segundo.
    Retorna um inteiro indicando se a ação foi
    bem-sucedida.
*/
int alimentar(Elemento *e1, Elemento *e2);


/*
    Recebe dois ponteiros para elementos.
    Imprime uma mensagem avisando que o primeiro
    elemento foi ligado usando o segundo.
    Retorna um inteiro indicando se a ação foi
    bem-sucedida.
*/
int ligar(Elemento *e1, Elemento *e2);


/*
    Recebe um lugar.
    Retorna um inteiro indicando se a ação foi
    bem-sucedida.
*/
int trocarLugar(Elemento *e1, Elemento *e2);

/*
    Caso específico de verbo.
    Recebe um elemento e uma senha,
    verifica se a senha do elemento é igual a senha.
    Retorna um inteiro indicando se a ação foi
    bem-sucedida.
*/
int tentarSenha(Elemento *e, char *senha);


/* Recebe nada e imprime todos os itens da mochila. */
int olharMochila(Elemento *e1, Elemento *e2);


/*
    Recebe dois ponteiros para elementos.
    Lista todos os objetos dentro da sala em
    que o aventureiro está.
*/
int listarElementos(Elemento *e1, Elemento *e2);
