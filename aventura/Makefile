main1 : main1.c libestat.a
		gcc -Wall -o main1 main1.c libestat.a

libestat.a : lista_ligada.o tabela_de_sim.o salas.o
		ar -rcv libestat.a lista_ligada.o tabela_de_sim.o salas.o

salas.o : salas.c
		gcc -c salas.c -o salas.o

tabela_de_sim.o : tabela_de_sim.c
		gcc -c tabela_de_sim.c -o tabela_de_sim.o

lista_ligada.o : lista_ligada.c
		gcc -c lista_ligada.c -o lista_ligada.o