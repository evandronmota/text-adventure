avent : main.c aventureiro.c elemento.c init_salas.c introducao.c lista_ligada.c salas.c tabela_de_sim.c lex.yy.c bison.tab.c
	gcc -Wall -g -lfl -lreadline -o avent main.c aventureiro.c elemento.c init_salas.c introducao.c lista_ligada.c salas.c tabela_de_sim.c lex.yy.c bison.tab.c

lex.yy.c : flex.l
	flex flex.l

bison.tab.c : bison.y
	bison -d bison.y