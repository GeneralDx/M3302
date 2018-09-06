#include <stdlib.h>
#include <stdio.h>
#include "image.h"
#include "entree_sortie.h"
#include "traitement.h"


int main(int argc, char const *argv[]) {


  // t_image * img = LireImagePGM("voiron.pgm");
  t_image * img = CreerImage(1,2);
  if (img == NULL)
    return -1;

  ImageUnie(img, 128);
  int* hist = Histogramme(img);
  for (size_t i = 0; i < 256; i++) {
    if (hist[i]>0) {
      printf("i = %ld, hist[i] = %d\n", i, hist[i]);
    }
  }
  EcrireImagePGM("voironneg.pgm", *img);
  LibererImage(img);
  return 0;

}
