increm:increm.o funcoes.o
	gcc -Wall increm.o funcoes.o -o increm
	
funcoes.o:funcoes.c funcoes.h
	gcc -Wall -c funcoes.c -o funcoes.o

increm.o:increm.c
	gcc -Wall -c increm.c -o increm.o

multiplica:multip.o funcoes.o
	gcc -Wall multip.o funcoes.o -o multiplica

multip.o:multip.c
	gcc -Wall -c multip.c -o multip.o
