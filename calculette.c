#include <stdio.h>
#include <stdlib.h>
int main (int argc, char* argv[]){
  int a = atoi(argv[1]);
  int b = atoi(argv[3]);
  switch(argv[2][0]){
  case '+':
    printf("%d + %d = %d", a, b, a+b);
    break;
  case '-':
    printf("%d - %d = %d", a, b, a-b); 
    break;
  case 'x':
    printf("%d x %d = %d", a, b, a*b);
    break;
  case '/':
    printf("%d / %d = %f", a, b, (float)a/(float)b);
    break;
  default:
    return -1;
  }
  printf("\n");
  return 0;
}
