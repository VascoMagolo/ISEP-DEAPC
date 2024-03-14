maior3:funcoes.o maior2.o
	gcc -Wall funcoes.o maior2.o -o maior3

funcoes.o:funcoes.c funcoes.h
	gcc -Wall -c funcoes.c -o funcoes.o

maior2.o:maior2.c funcoes.h
	gcc -Wall -c maior2.c -o maior2.o