#include <stdlib.h>
#include <stdio.h>
#include "entree_sortie.h"

void AfficherImage(char* nomFichier){
  char * str;
  sprintf(str, "eog %s &", nomFichier);
  system(str);
}

t_image * CreerImage(unsigned int largeur, unsigned int hauteur){

  t_image * ret = (t_image *)malloc(sizeof(t_image));
  ret->pixels = (unsigned char *)malloc(largeur*hauteur);
  ret->largeur = largeur;
  ret->hauteur = hauteur;

  return ret;
}

void ImageUnie(t_image * image, unsigned char couleur){
  for (long i = 0; i < image->hauteur * image->largeur; i++) {
    image->pixels[i] = couleur;
  }
}

void Negatif(t_image * image){
  for(unsigned int i = 0; i< image->largeur*image->hauteur; i++){
    char change = (image->pixels[i]-128) *2;
    image->pixels[i] -= change;
  }
}

void Seuillage(t_image * image ,unsigned char seuil){
  for(unsigned int i=0; i< image->largeur*image->hauteur; i++)
    image->pixels[i]=(image->pixels[i]<seuil)?0:255;
}


void Degrade(t_image * image){
  int x;
  for (unsigned int i = 0; i < image->largeur * image->hauteur; i++) {
    x = i % image->largeur;
    image->pixels[i] = (unsigned char)((256.0/(double)image->largeur) *(double)x);
  }
}

void LibererImage(t_image* img){
  free(img->pixels);
  free(img);
  img = NULL;
}

int main(int argc, char const *argv[]) {
  int l= 600, h=100;
  t_image * img = CreerImage(l, h);
  if (img == NULL)
    return -1;

  ImageUnie(img, 42);
  EcrireImagePGM("imageunie.pgm", *img);
  LibererImage(img);
  return 0;
}
