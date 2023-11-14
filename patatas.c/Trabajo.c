#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "colaDeDatos.h"

int main(){
  int multiplicador, guarda, numero;
  FILE *StressLevelDataset;
  
  while(!feof(f))
  {
    fread(&multiplicador,sizeof(int),1,f);
    fread(&guarda,sizeof(int),1,f);
    if (guarda != ';')
    {
      multiplicador = multiplicador*10;
      multiplicador += guarda;
      fread(&guarda, sizeof(int),1,f);
    }
  }
   			if(n>0){
   				printf("%c", x);
   			}
   }
  
}
