media:funcoes.o contas.o
	gcc -Wall funcoes.o contas.o -o media

funcoes.o:funcoes.c funcoes.h
	gcc -Wall -c funcoes.c -o funcoes.o

contas.o:contas.c funcoes.h
	gcc -Wall -c contas.c -o contas.o

operacoes.o:operacoes.c funcoes.h
	gcc -Wall -c operacoes.c -o operacoes.o

menus.o:menus.c menus.h
	gcc -Wall -c menus.c -o menus.o

operacoes:menus.o operacoes.o funcoes.o
	gcc -Wall menus.o operacoes.o funcoes.o -o operacoes