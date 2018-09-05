#ifndef traitement_h
#define itraitement_h
#include "image.h"
void ImageUnie(t_image * image, unsigned char couleur);
void Negatif(t_image * image);
void Seuillage(t_image * image ,unsigned char seuil);
void Degrade(t_image * image);
#endif
