#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "image.h"
#include "entree_sortie.h"
#include "traitement.h"


int main(int argc, char const *argv[]) {
  clock_t start = clock();

  for (size_t i = 0; i < 10; i++) {
    t_image * img = LireImagePGM("voiron.pgm");
    if (img == NULL)
      return -1;

    Seuillage(img, 128);

    EcrireImagePGM("voironneg.pgm", *img);
    LibererImage(img);
  }
  printf("temps ecoule:%ld\n", clock() - start);
  return 0;

}
