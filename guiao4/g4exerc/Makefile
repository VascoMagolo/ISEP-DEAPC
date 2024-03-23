all:volume1 vcone
	gcc -Wall solidos.o volume.o -o volume1 -lm
	gcc -Wall vcones.o solidos.o -o vcone -lm

volume1:solidos.o volume.o
	gcc -Wall solidos.o volume.o -o volume1 -lm

solidos.o:solidos.c
	gcc -Wall -c solidos.c -o solidos.o 

volume.o:volume.c
	gcc -Wall -c volume.c -o volume.o 

vcone:vcones.o solidos.o
	gcc -Wall vcones.o solidos.o -o vcone -lm

vcones.o:vcones.c
	gcc -Wall -c vcones.c -o vcones.o
