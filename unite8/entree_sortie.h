#ifndef io_h
#define io_h
#include <stdlib.h>
#include "image.h"

#define DEBUG 	1  // utilis� en interne dans le module entree_sortie.c
#define OK 	0  // les 2 codes retour possibles ...
#define ERREUR 	1  // ... de EcrireImagePGM


int EcrireImagePGM(const char* nomFichier, const t_image im);
void AfficherImage(char* nomFichier);
t_image* LireImagePGM(const char* nomFichier);
#endif
