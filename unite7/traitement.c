#include "image.h"
#include "entree_sortie.h"
#define SEUIL1_PIXEL(val, s) (val<s?0:255)
#define SEUIL2_PIXEL(val, s) val = SEUIL1_PIXEL(val,s)

#if (DEBUG)
#include <stdio.h>
#define AFFICHER_FONCTION printf("%s\n", __func__)
#else
#define AFFICHER_FONCTION void
#endif

void ImageUnie(t_image * image, unsigned char couleur){
  AFFICHER_FONCTION;
  for (long i = 0; i < image->hauteur * image->largeur; i++) {
    image->pixels[i] = couleur;
  }
}

void Negatif(t_image * image){
  AFFICHER_FONCTION;
  for(unsigned int i = 0; i< image->largeur*image->hauteur; i++){
    char change = (image->pixels[i]-128) *2;
    image->pixels[i] -= change;
  }
}

void Seuillage(t_image * image ,unsigned char seuil){
  AFFICHER_FONCTION;
  for(unsigned int i=0; i< image->largeur*image->hauteur; i++)
    SEUIL2_PIXEL(image->pixels[i], seuil);
}


void Degrade(t_image * image){
  AFFICHER_FONCTION;
  int x;
  for (unsigned int i = 0; i < image->largeur * image->hauteur; i++) {
    x = i % image->largeur;
    image->pixels[i] = (unsigned char)((256.0/(double)image->largeur) *(double)x);
  }
}
