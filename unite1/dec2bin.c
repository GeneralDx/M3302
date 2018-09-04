#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dec2bin(char dec[], char bin[]){
  int deci = atoi(dec);
  char binbuf[64];
  int i = 0;
  while(deci > 0){
    if(deci%2 == 1)
      binbuf[i]='1';
    else
      binbuf[i]='0';
    deci >>=1;
    i++;
  }
  binbuf[i] = '\0';
  for(i =0; i<strlen(binbuf); i++)
    bin[i] = binbuf[strlen(binbuf)-1 -i];
  bin[i] = '\0';
}

int main(){
  char bin[64], dec[64];
  printf("donner un nombre decimal: ");
  scanf("%s", &dec);
  dec2bin(dec,bin);
  printf("<%s>10 = <%s>2\n", dec, bin);
  return 0;
}
