testes : testes.c lista_ligada.c salas.c tabela_de_sim.c init_salas.c aventureiro.c introducao.c elemento.c
	gcc -Wall -o testes testes.c lista_ligada.c salas.c tabela_de_sim.c init_salas.c aventureiro.c introducao.c elemento.c

LOADLIBES= -lfl -lreadline
CFLAGS=-Wall -g

%.c: %.y
	bison $<
	mv $*.tab.c $*.c

bison: main.o bison.o flex.o elemento.o aventureiro.o tabela_de_sim.o lista_ligada.o init_salas.o salas.o

tabela_de_sim.o : tabela_de_sim.c lista_ligada.c
		gcc -o tabela_de_sim.o tabela_de_sim.c lista_ligada.c

bison.o : bison.y
		bison -d bison.y && gcc -o bison.o bison.c elemento.c

flex.o: flex.l bison.c elemento.c
		flex flex.l && gcc -o flex.o lex.yy.c bison.c elemento.c

clean:
	rm -f bison *tab* *.o *~ bison.c bison.tgz

dist:
	tar czf bison.tgz flex.l bison.y elemento.c elemento.h main.c tabela_de_sim.c tabela_de_sim.h Makefile