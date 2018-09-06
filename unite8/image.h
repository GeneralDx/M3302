#ifndef image_h
#define image_h
typedef struct Image
{
  unsigned char* pixels ;
  unsigned int largeur ;
  unsigned int hauteur ;
} t_image ;

t_image * CreerImage(unsigned int largeur, unsigned int hauteur);
void LibererImage(t_image* img);
int* Histogramme(t_image* image);
#endif
