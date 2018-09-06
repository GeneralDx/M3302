#include <stdlib.h>
#include <stdio.h>
#include "image.h"
#include "entree_sortie.h"
#include "traitement.h"


int main(int argc, char const *argv[]) {


  t_image * img = LireImagePGM("voiron.pgm");
  if (img == NULL)
    return -1;

  Miroir(img, 1);
  Negatif(img);
  Seuillage(img, 128);
  EcrireImagePGM("voironneg.pgm", *img);
  LibererImage(img);

  return 0;

}
