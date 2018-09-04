#include <stdio.h>
#include <stdlib.h>
float celsius(float f){
  return (f -32) * (5.0 /9.0);
}

int main(){
  printf("--------------------\n");
  printf("Fahrenheit\tCelsius\n");
  for(float f = 0; f <=200.0; f+=20.0){
    printf("%f\t%f\n", f, celsius(f));
  }
  return 0;
}
