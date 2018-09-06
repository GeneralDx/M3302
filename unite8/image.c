#include <stdlib.h>
#include "image.h"
t_image * CreerImage(unsigned int largeur, unsigned int hauteur){

  t_image * ret = (t_image *)malloc(sizeof(t_image));
  ret->pixels = (unsigned char *)malloc(largeur*hauteur);
  ret->largeur = largeur;
  ret->hauteur = hauteur;

  return ret;
}

void LibererImage(t_image* img){
  free(img->pixels);
  free(img);
  img = NULL;
}

int* Histogramme(t_image* image){
  int* ret = (int*)malloc(256*sizeof(int));
  for (size_t i = 0; i < image->largeur*image->hauteur; i++) {
    ret[image->pixels[i]]++;
  }
  return ret;
}
