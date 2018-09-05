NAME ?= $(shell bash -c 'read -p "Entrez un nom: " name; echo $$name')

imagemod: main.o entree_sortie.o
	gcc main.o entree_sortie.o -Wall -o $(NAME) 
main.o: main.c entree_sortie.h
	gcc -c main.c -Wall
