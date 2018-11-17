/* Ponteiro para as funções dos elementos */
typedef int (*func)(Elemento *e1, Elemento *e2);

/* Funções */
Elemento criarSala0();
Elemento criarSala1();
Elemento criarSala2();
Elemento criarSala3();
Elemento criarSala4();
Elemento criarSala5();
int examinar(Elemento *e1, Elemento *e2);
int pegar(Elemento *e1, Elemento *e2);
int largar(Elemento *e1, Elemento *e2);
int colocarSobre(Elemento *e1, Elemento *e2);
int tirarDeCima(Elemento *e1, Elemento *e2);
void nome(Elemento e);
