#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char * argv[]){
  int c = 1;
  char on = '*';
  char off = '-';
  int delay = 500;
  int num = 10;
  while(c<argc){
    if(argv[c][0] == '-'){
      switch(argv[c][1]){
      case 'a':
	on = argv[c+1][0];
	c++;
	break;
      case 'e':
	off = argv[c+1][0];
	c++;
	break;
      case 't':
	delay = atoi(argv[c+1]);
	c++;
	break;
      case 'n':
	num = atoi(argv[c+1]);
	c++;
	break;
      default:
	printf("Parametre %s inconnu\n", argv[c]);
	return -1;
	break;
      }
    }else{
      printf("Unexpected %s in input\n", argv[c]);
      return -1;
    }
    
    c++;
  }
  
  char chenillard[num+1];
  chenillard[num] = '\0';
  int ampouleAllumee = 0;
  while(0==0){//owO whats this
    for(int i = 0; i < num; i++){
      if(i == ampouleAllumee)
	chenillard[i] = on;
      else
	chenillard[i] = off;
    }
    printf("\r%s", chenillard);
    fflush(stdout);
    ampouleAllumee ++;
    ampouleAllumee %= num;
    usleep(delay*1000);
  }
  return 0; //unreachable code.
}
