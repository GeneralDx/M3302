#include <stdio.h>
#include <stdlib.h>

int main(){
  char ch1[64] = "bonjour";
  char ch2[64] = "xxxxxxxxxxxxxxxx";
  char read = ch1[0];
  int i=0;
  while(read != '\0'){
    i++;
    read = ch1[i];
  }
  int j =0;
  i--;
  for(void; i>=0; i--){
    ch2[j] = ch1[i];
    j++;
  }
  ch2[j]='\0';
  printf(ch1);
  printf("\n");
  printf(ch2);
  
  return 0;

}
