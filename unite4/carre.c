#include <stdio.h>
#include <stdlib.h>
int Carre1(int x){
  return x*x;
}

void Carre2(int * addr_x){
  *addr_x *= *addr_x;
}
int main(int argc, char const *argv[]) {
  int i = 6;
  printf("Avant: %d\nApres: %d\n", i, Carre1(i));

  printf("Avant: %d\n", i);
  Carre2(&i);
  printf("Apres: %d\n", i);

  return 0;
}
