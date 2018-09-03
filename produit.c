#include <stdio.h>
#include <stdlib.h>
int main(){
  printf("saisissez deux nombres separes par une virgule\n");
  int n1, n2;
  scanf("%d,%d", &n1, &n2);
  printf("%d x %d = %d ", n1, n2, n1*n2);
  return 0;
}
