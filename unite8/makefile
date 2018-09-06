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
debug:main.o.debug entree_sortie.o.debug image.o.debug traitement.o.debug
	gcc main.o image.o entree_sortie.o traitement.o -o main -Wall
main.o.debug: main.c image.h entree_sortie.h traitement.h
	gcc -g -c main.c -Wall
image.o.debug: image.c
	gcc -g -c image.c -Wall
entree_sortie.o.debug: entree_sortie.c image.h
	gcc -g -c entree_sortie.c -Wall
traitement.o.debug: traitement.c image.h
	gcc -g -c traitement.c -Wall
