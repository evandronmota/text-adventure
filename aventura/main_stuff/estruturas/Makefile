avent : main.c aventureiro.c elemento.c init_salas.c lista_ligada.c salas.c tabela_de_sim.c lex.yy.c bison.tab.c
	gcc -Wall -g main.c aventureiro.c elemento.c init_salas.c lista_ligada.c salas.c tabela_de_sim.c lex.yy.c bison.tab.c -o avent -lfl -lreadline

lex.yy.c : flex.l
	flex flex.l

bison.tab.c : bison.y
	bison -d bison.y

testes : testes.c lista_ligada.c salas.c tabela_de_sim.c init_salas.c aventureiro.c elemento.c
	gcc -Wall -o testes testes.c lista_ligada.c salas.c tabela_de_sim.c init_salas.c aventureiro.c elemento.c
