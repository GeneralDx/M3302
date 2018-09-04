
imagemod: main.o entree_sortie.o
	read -p "entrez un nom: " name
	gcc main.o entree_sortie.o -Wall -o $name 
main.o: main.c entree_sortie.h
	gcc -c main.c -Wall
