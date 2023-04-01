#include "cabecalho.h"


void imprimeparte(char desenho[4][7], int parte){
  printf("%s", desenho[parte]);
}

void imprimimapa(){
  
  char desenhofantasma[4][7] = {
      {" .-.  " },
      {"| OO| " },
      {"|   | " },
      {"'^^^' " }
  };
  char desenhoparede[4][7] = {
      {"......" },
      {"......" },
      {"......" },
      {"......" }
  };
  char desenhocomecome[4][7] = {
      {" .--. "  },
      {"/ _.-'"  },
      {"\\  '-." },
      {" '--' "  }
  };
  char desenhopilula[4][7] = {
      {"      "},
      {" .-.  "},
      {" '-'  "},
      {"      "}
  };
  char desenhovazio[4][7] = {
      {"      "},
      {"      "},
      {"      "},
      {"      "}
  };

   int i, j, parte;
  
   for (i = 0; i < x.linha; i++){
     for ( parte = 0; parte < 4; parte ++){
       for (j = 0; j < x.coluna; j++){
          switch(x.matriz[i][j]){
            case FANTASMA:
               printf("\033[31m");
              imprimeparte(desenhofantasma, parte);
               printf("\033[37m");
              break;
            case COMECOME:
              if(power){
                printf("\033[34m");
                imprimeparte(desenhocomecome, parte);
                printf("\033[37m");
                } else{
                   printf("\033[37m");
                   imprimeparte(desenhocomecome, parte);
                  }
              break;
           case PILULA:
              printf("\033[34m");
              imprimeparte(desenhopilula, parte);
              printf("\033[37m");
              break;
           case VAZIO:
              imprimeparte(desenhovazio, parte);
              break;
            case PAREDE_VERTICAL:
            case PAREDE_HORIZONTAL:
              printf("\033[32m");
              imprimeparte(desenhoparede, parte);
              printf("\033[37m");
            }
         }
     printf("\n");
      }
    }
  }
