#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ON '*'
#define OFF '-'

#define NBAMPOULES 10
#define DELAY 500


void Temporisation(int n)
//------------------------------------------------------------------------------
// Fonction qui met n milli-secondes a s'executer
// C'est donc une temporisation de n ms
// necessite <stdio.h>
{
	clock_t start, stop ;

	n = n*CLOCKS_PER_SEC/1000 ; // clock() ne fonctionne pas forcement en milli-secondes
	start = clock() ;           // Top depart. start = l'heure de depart
	stop = start + n ;          // stop = l'heure de fin

	while(clock() < stop)       // On scrute l'heure tant qu'on n'a pas atteint la fin
	{
	} 
}


int main(){
  char chenillard[NBAMPOULES];
  int ampouleAllumee = 0;
  while(0==0){//owO whats this
    for(int i = 0; i < NBAMPOULES; i++){
      if(i == ampouleAllumee)
	chenillard[i] = ON;
      else
	chenillard[i] = OFF;
    }
    printf("\r%s", chenillard);
    fflush(stdout);
    ampouleAllumee ++;
    ampouleAllumee %= NBAMPOULES;
    Temporisation(DELAY);
  }
  return 0; //unreachable code.
}
