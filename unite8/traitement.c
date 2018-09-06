#include "image.h"
#include "entree_sortie.h"
#include "traitement.h"
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

void Miroir(t_image * image, int type){
  AFFICHER_FONCTION;
  t_image buffer = *image;
  buffer.pixels = (unsigned char *)malloc(image->largeur * image->hauteur);
  for (size_t i = 0; i < image->largeur * image->hauteur; i++) {
    buffer.pixels[i] = image->pixels[i];
  }
  if (type == MIROIR_VERTICAL) {
    for (size_t x = 0; x < image->largeur; x++) {
      for (size_t y = 0; y < image->hauteur; y++) {
        image->pixels[y*image->largeur +x] = buffer.pixels[(image->hauteur - 1 - y)*image->largeur +x];
      }
    }
  } else {
    for (size_t x = 0; x < image->largeur; x++) {
      for (size_t y = 0; y < image->hauteur; y++) {
        image->pixels[y*image->largeur +x] = buffer.pixels[y*image->largeur +(image->largeur-1-x)];
      }
    }
  }
  free(buffer.pixels);
}

t_image* Rotation(t_image* image){
  t_image * ret = CreerImage(image->hauteur, image->largeur);
  for (size_t x = 0; x < image->largeur; x++) {
    for (size_t y = 0; y < image->hauteur; y++) {
      ret->pixels[x*ret->largeur +y] = image->pixels[y*image->largeur +x];
    }
  }
  return ret;
}

t_image* HistogrammeImage(int* histo, int hauteur){
  int max =0;
  for (size_t i = 0; i < 256; i++) {
    if (histo[i] > max) {
      max = histo[i];
    }
  }
  t_image* ret = CreerImage(256, hauteur);

  for (size_t x = 0; x < 256; x++) {
    for (int y = 0; y < hauteur; y++) {
      ret->pixels[y*256 + x] =( hauteur - (((double)histo[x] / (double)max)*hauteur) > y )? 0 : 255;
    }
  }
  return ret;
}
