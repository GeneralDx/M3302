#include <stdlib.h>
#include <stdio.h>
#include "entree_sortie.h"

void AfficherImage(char* nomFichier){
  char * str;
  sprintf(str, "eog %s &", nomFichier);
  system(str);
}

unsigned char * CreerImage(int largeur, int hauteur){
  return (unsigned char*)malloc(largeur*hauteur);
}

void ImageUnie(unsigned char * image, int largeur, int hauteur, unsigned char couleur){
  for (long i = 0; i < largeur*hauteur; i++) {
    image[i] = couleur;
  }
}

int main(int argc, char const *argv[]) {
  unsigned char * img = CreerImage(30, 40);
  ImageUnie(img, 30, 40, 42);
  EcrireImagePGM("imageunie.pgm", img, 30, 40);
  AfficherImage("imageunie.png");

  free(img);
  return 0;
}
