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

void Negatif(unsigned char* image, int largeur, int hauteur){
  for(int i = 0; i< largeur*hauteur; i++){
    char change = (image[i]-128) *2;
    image[i] -= change;
  }
}

void Seuillage(unsigned char * image, int largeur, int hauteur,unsigned char seuil){
  for(int i=0; i< largeur*hauteur; i++)
    image[i]=(image[i]<seuil)?0:255;
}


void Degrade(unsigned char * image, int largeur, int hauteur){
  int x;
  for (int i = 0; i < largeur * hauteur; i++) {
    x = i % largeur;
    image[i] = (unsigned char)((256.0/(double)largeur) *(double)x);
  }
}

int main(int argc, char const *argv[]) {
  int l= 600, h=100;
  unsigned char * img = CreerImage(l, h);
  if (img == NULL)
    return -1;
  Degrade(img, l, h);
  EcrireImagePGM("degrade.pgm", img, l, h);
  free(img);
  return 0;
}
