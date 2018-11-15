// ponteiro para as funções dos elementos
typedef int (*func)(Elemento *e1, Elemento *e2);

// funções
Elemento criarSala1();
Elemento criarSala2();
Elemento criarSala3();
Elemento criarSala4();
Elemento criarSala5();
int examinar(Elemento *e1, Elemento *e2);
int colocarSobre(Elemento *e1, Elemento *e2);
void nome(Elemento e);
