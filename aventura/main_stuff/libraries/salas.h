/* Ponteiro para as funções dos elementos */
typedef int (*func)(Elemento *e1, Elemento *e2);

/*
    Cria o salão principal do jogo com todos os elementos.
    Retorna a sala criada. 
*/
Elemento criarSala0();


/*
    Cria a primeira sala com todos os objetos.
    Retorna a sala criada.
*/
Elemento criarSala1();


/*
    Cria a segunda sala com todos os objetos.
    Retorna a sala criada.
*/
Elemento criarSala2();


/*
    Cria a terceira sala com todos os objetos.
    Retorna a sala criada.
*/
Elemento criarSala3();


/*
    Cria a quarta sala com todos os objetos.
    Retorna a sala criada.
*/
Elemento criarSala4();


/*
    Cria a quinta sala com todos os objetos.
    Retorna a sala criada.
*/
Elemento criarSala5();


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
    Imprime uma mensagem avisando que o primeiro
    elemento foi colocado sobre o segundo.
    Retorna um inteiro indicando se a ação foi
    bem-sucedida.
*/
int colocarSobre(Elemento *e1, Elemento *e2);
