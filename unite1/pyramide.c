#include <stdio.h>
#include <stdlib.h>

void AfficheCar(int n, char c){
  for(int i = 0; i<n; i++)
    printf("%c", c);
}


int main(int argc, char* argv[]){
  if(argc != 3){
    printf("erreur");
    return -1;
  }
  int h = atoi(argv[1]);
  //base = h *2 -1
  //nombre a n: n*2 -1
  //nombre d'espaces a n: h - 1 -n
  for(int i = 1; i<= h; i++){
    AfficheCar(h-i, ' ');
    AfficheCar(i*2-1, argv[2][0]);
    printf("\n");
  }
  return 0;
}

