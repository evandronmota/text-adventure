
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
    Recebe um ponteiro para um elemento e uma função de
    ação. Adiciona essa ação à lista de ações do elemento.
*/
void adicionarAcao(Elemento *e, void* acao, int transitividade);


/*
    Recebe um ponteiro para um elemento e um atributo.
    Adiciona esse atributo à lista de atributos do elemento.
*/
void adicionarAtributo(Elemento *e, obj_atr atributo);


/* 
    Recebe dois ponteiros para elementos.
    Adiciona o segundo elemento à lista de conteúdos do
    primeiro.
*/
void adicionarElemento(Elemento *e1, Elemento *destino);
