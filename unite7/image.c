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
