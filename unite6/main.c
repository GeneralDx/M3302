#include <stdlib.h>
#include <stdio.h>

typedef struct Image
{
  unsigned char* pixels ;
  unsigned int largeur ;
  unsigned int hauteur ;
} t_image ;

#define DEBUG 	0  // utilis� en interne dans le module entree_sortie.c
#define OK 	0  // les 2 codes retour possibles ...
#define ERREUR 	1  // ... de EcrireImagePGM



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

t_image * CreerImage(unsigned int largeur, unsigned int hauteur){

  t_image * ret = (t_image *)malloc(sizeof(t_image));
  ret->pixels = (unsigned char *)malloc(largeur*hauteur);
  ret->largeur = largeur;
  ret->hauteur = hauteur;

  return ret;
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

void ImageUnie(t_image * image, unsigned char couleur){
  for (long i = 0; i < image->hauteur * image->largeur; i++) {
    image->pixels[i] = couleur;
  }
}

void Negatif(t_image * image){
  for(unsigned int i = 0; i< image->largeur*image->hauteur; i++){
    char change = (image->pixels[i]-128) *2;
    image->pixels[i] -= change;
  }
}

void Seuillage(t_image * image ,unsigned char seuil){
  for(unsigned int i=0; i< image->largeur*image->hauteur; i++)
    image->pixels[i]=(image->pixels[i]<seuil)?0:255;
}


void Degrade(t_image * image){
  int x;
  for (unsigned int i = 0; i < image->largeur * image->hauteur; i++) {
    x = i % image->largeur;
    image->pixels[i] = (unsigned char)((256.0/(double)image->largeur) *(double)x);
  }
}

void LibererImage(t_image* img){
  free(img->pixels);
  free(img);
  img = NULL;
}

int main(int argc, char const *argv[]) {

  t_image * img = LireImagePGM("voiron.pgm");
  if (img == NULL)
    return -1;

  Negatif(img);

  EcrireImagePGM("voironneg.pgm", *img);
  LibererImage(img);
  return 0;
}
