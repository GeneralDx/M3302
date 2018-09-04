#include <stdio.h>
#include <stdlib.h>

void permut(int* adr_a,int* adr_b){
  int buf = *adr_a;
  *adr_a = *adr_b;
  *adr_b = buf;
}

int main(int argc, char const *argv[]) {
  int a=4, b=5;
  printf("Avant: a=%d, b=%d\n", a, b);
  permut(&a,&b);
  printf("Apres: a=%d, b=%d\n", a, b);

  return 0;
}
