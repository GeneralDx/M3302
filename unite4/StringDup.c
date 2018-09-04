#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* StringDup(char * s){
  char* ret = (char*)malloc(strlen(s)+1);
  strcpy(ret, s);
  ret[strlen(ret)] = '\0';
  return ret;
}

int main(int argc, char const *argv[]) {
  char chaine[] = "je mange du fromage";
  char* copie = StringDup(chaine);
  printf("chaine: %s\n", chaine);
  printf("copie: %s\n", copie);
  free(copie);
  return 0;
}
