main: main.o image.o entree_sortie.o traitement.o
	gcc -O3 main.o image.o entree_sortie.o traitement.o -o main -Wall
main.o: main.c image.h entree_sortie.h traitement.h
	gcc -O3 -c main.c -Wall
image.o: image.c
	gcc -O3 -c image.c -Wall
entree_sortie.o: entree_sortie.c image.h
	gcc -O3 -c entree_sortie.c -Wall
traitement.o: traitement.c image.h
	gcc -O3 -c traitement.c -Wall
