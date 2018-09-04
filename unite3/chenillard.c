#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
typedef unsigned int interrupeurs_t;

int valeurAmpoule(interrupeurs_t inter, int i){
  return (inter & (interrupeurs_t)pow(2.0, (double)8*sizeof(interrupeurs_t) -i -1)) != 0 ? 1 : 0;
}

interrupeurs_t Inversion(interrupeurs_t inter){
  return ~inter;
}

interrupeurs_t Compteur(interrupeurs_t inter){
  return inter +1;
}

interrupeurs_t RotationGauche(interrupeurs_t inte){
  interrupeurs_t inter = inte;
  if (inter >= (~(interrupeurs_t)0)-((~(interrupeurs_t)0)>>1)) { //~(interrupeurs_t)0 vaut la valeur maximale stockable dans le type.
    inter <<=1;
    inter ++;
  } else {
    inter <<=1;
  }
  return inter;
}

interrupeurs_t RotationDroite(interrupeurs_t inte){
  interrupeurs_t inter = inte;
  if (inter %2 == 1) {
    inter >>= 1;
    inter += (~(interrupeurs_t)0)-((~(interrupeurs_t)0)>>1);
  } else {
    inter >>=1;
  }
  return inter;
}


int main(int argc, char * argv[]){
  char on = 'w';
  char off = 'O';
  int delay = 100;
  char chenillard[8*sizeof(interrupeurs_t) +1] = {0};
  interrupeurs_t inter = 7;
  while(0==0){//owO whats this
    for(unsigned int i = 0; i < 8*sizeof(interrupeurs_t); i++){
      if(valeurAmpoule(inter, i) == 1)
	     chenillard[i] = on;
      else
	     chenillard[i] = off;
    }
    printf("\r%s", chenillard);
    fflush(stdout);
    inter = RotationDroite(inter);
    usleep(delay*1000);
  }
  return 0; //unreachable code.
}
