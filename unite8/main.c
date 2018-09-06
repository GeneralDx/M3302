#include <stdlib.h>
#include <stdio.h>
#include "image.h"
#include "entree_sortie.h"
#include "traitement.h"


int main(int argc, char const *argv[]) {


  t_image * img = LireImagePGM("voiron.pgm");
  if (img == NULL)
    return -1;

  int* hist = Histogramme(img);
  t_image * histo = HistogrammeImage(hist, 300);
  EcrireImagePGM("voironneg.pgm", *histo);
  LibererImage(histo);
  LibererImage(img);
  return 0;

}
