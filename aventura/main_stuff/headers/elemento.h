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

/*
    Union para atributos específicos de sala
    e objeto.
*/
typedef union {
    obj_atr *atributos;
    struct ele **saidas;
} Info;

/* Elemento */
typedef struct ele {
    char *artigo;
    char *n;
    char *curta;
    char *longa;
    boolean ativo;
    boolean visivel;
    boolean conhecido;
    struct ele* conteudo;
    int nEle; /* Número de elementos na lista de conteúdos */
    int nAcoes; /* Número de ações do elemento */
    int nAtr; /* Número de atributos do elemento */
    void **acoes;
    int *transitividade;
    /*
        0 = intransitivo
        1 = transitivo
        2 = bitransitivo
    */
    void *animacao;
    Info detalhe;
} Elemento;

/*
    Recebe um elemento. Imprime o nome do elemento
    recebido precedido de seu artigo.
*/
void nome(Elemento e);


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
    elemento foi colocado sobre o segundo.
    Retorna um inteiro indicando se a ação foi
    bem-sucedida.
*/
int colocarSobre(Elemento *e1, Elemento *e2);

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