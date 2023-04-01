#include "cabecalho.h"
#include "processa.h"
#include "comecajogo.h"


int main(void) {
   
   char comando, continuar;
   
   continuar = 's';
   while(continuar == 's'){
     acaba = 0;
     vencedor = 1;
     lermapa();
     comecarojogo();
     
     do{
     
         imprimimapa();
         scanf(" %c", &comando);
         comando = tolower(comando);
         move(comando);
       }while(!acabou(&acaba) && !venceu(&vencedor));
      printf("\n\nDeseja jogar novamente? (s/n) ");
      scanf(" %c", &continuar);
      continuar = tolower(continuar);
      localizacomecome();
     }
  
  liberamapa();
  
  printf("\nBen Inf entretenimento!!!");
  printf("\nBy BQB");
  return 0;
  }
