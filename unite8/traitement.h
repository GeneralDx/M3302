#ifndef traitement_h
#define itraitement_h
#include "image.h"
#define MIROIR_HORIZONTAL 0
#define MIROIR_VERTICAL 1
void ImageUnie(t_image * image, unsigned char couleur);
void Negatif(t_image * image);
void Seuillage(t_image * image ,unsigned char seuil);
void Degrade(t_image * image);
void Miroir(t_image *, int type);
t_image* Rotation(t_image* image);
#endif
