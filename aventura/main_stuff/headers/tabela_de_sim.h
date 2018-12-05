/*
    A tabela de símbolos guarda seu tamanho e 
    um vetor de listas ligadas.
*/
typedef struct {
    int tam;
    Lista *elementos;
} tabSim;

/* Ponteiro para tabela de símbolos */
typedef tabSim *TabSim;

extern TabSim tabela;

/*
    Recebe o tamanho da tabela de símbolos.
    Cria a tabela de símbolos com o tamanho
    recebido. Retorna a tabela de símbolos criada.
*/
TabSim cria(int tam);


/*
    Recebe uma tabela de símbolos. Destroi a
    tabela recebida.
*/
void destroi(TabSim t);


/*
    Recebe uma tabela de símbolos, uma string e
    um ponteiro para um elemento. Insere esse
    elemento na tabela associando-o à string
    recebida. Retorna um inteiro indicando se a
    operação foi bem-sucedida.
*/
int insere(TabSim t, char *n, void *val);


/*
    Recebe uma tabela de símbolos e uma string.
    Realiza uma busca nessa tabela a partir da
    string recebida. Retorna um ponteiro para o
    elemento associado à tal string.
*/
void *busca(TabSim t, char *n);


/*
    Recebe uma tabela de símbolos e uma string.
    Remove da tabela o elemento associado à string
    recebida. Retorna um inteiro indicando se a
    operação foi bem-sucedida.
*/
int retira(TabSim t, char *n);


/* 
    Recebe um vetor com as salas inicializadas.
    Inicializa a tabela com os elementos. 
*/
void init_tabela(Elemento *salas);
