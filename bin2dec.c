#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void bin2dec(char bin[], char dec[]){
  int ret = 0;
  for(int i = strlen(bin); i>=0; i--){
    if(bin[i] == '1')
      ret += (int)pow((double)2, (double)(strlen(bin) - i));
  }
  sprintf(dec, "%d", ret);
}

int main(){
  char bin[64];
  char dec[64];
  printf("donner une nombre en binaire : ");
  scanf("%s", &bin);
  bin2dec(bin, dec);
  printf("<%s>2 = <%s>10\n", bin, dec);
  return 0;
}
