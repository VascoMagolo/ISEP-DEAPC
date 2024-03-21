letra:funcoes.o letra.o
	gcc -Wall funcoes.o letra.o -o letra

funcoes.o:funcoes.c
	gcc -Wall -c funcoes.c -o funcoes.o

letra.o:letra.c
	gcc -Wall -c letra.c -o letra.o

letexto.o:letexto.c
	gcc -Wall -c letexto.c -o letexto.o

letexto:letexto.o funcoes.o
	gcc -Wall letexto.o funcoes.o -o letexto