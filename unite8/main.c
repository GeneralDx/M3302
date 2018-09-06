#include <stdlib.h>
#include <stdio.h>
#include "image.h"
#include "entree_sortie.h"
#include "traitement.h"


int main(int argc, char const *argv[]) {


  t_image * img = LireImagePGM("voiron.pgm");
  if (img == NULL)
    return -1;

  t_image * rot = Rotation(img);
  EcrireImagePGM("voironneg.pgm", *rot);
  LibererImage(img);
  LibererImage(rot);

  return 0;

}
