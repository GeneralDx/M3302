#include <stdio.h>
#include "image.h"
#include "entree_sortie.h"

int EcrireImagePGM(const char* nomFichier, const t_image im){
  FILE * f = fopen(nomFichier, "w");
  if(f){
    fprintf(f, "P5\n%d %d\n255\n", im.largeur, im.hauteur);
    fwrite(im.pixels,1, im.largeur*im.hauteur, f);
    fclose(f);
    return OK;
  }else
    return ERREUR;
}

void AfficherImage(char* nomFichier){
  char * str;
  sprintf(str, "eog %s &", nomFichier);
  system(str);
}

t_image* LireImagePGM(const char* nomFichier){
  FILE *f;
  f = fopen (nomFichier,"r");
  if (f!=NULL)
  {
    unsigned int l,h;
    fscanf(f,"P5\n%d %d\n255\n", &l, &h);
    t_image * ret = CreerImage(l, h);
    fread(ret->pixels, 1, l*h, f);
    ret->hauteur = h;
    ret->largeur = l;
    return ret;
    fclose (f);
  }
  return NULL;
}
