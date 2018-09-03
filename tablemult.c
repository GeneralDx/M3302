#include <stdio.h>
#include <stdlib.h>

int main(){
  printf("table de quoi? ");
  int num;
  scanf("%d", &num);
  for(int i = 0; i<=10 ; i++){
    printf("%d x %d = %d\n", i, num, i*num);
  }
  return 0;
}
