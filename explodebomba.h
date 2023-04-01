#include "cabecalho.h"
#include "processa.h"

//localizar o comecome na matriz
void localizacomecome(){
  
  int i, j;
  for(i=1; i<x.linha; i++){
    for(j=1; j<x.coluna; j++){
      if (x.matriz[i][j] == COMECOME){
         h.l = i;
         h.c = j;
         break;
        }
    }
  }
}
void explodibombadireita(){

    int i;
    for (i=1; i<=3; i++){
      if (h.c + i< x.coluna) {
         if (x.matriz[h.l][h.c + i] == PAREDE_HORIZONTAL){
            break;
           }
         else{
             if ( x.matriz[h.l][h.c + i] == FANTASMA ){
                 x.matriz[h.l][h.c + i] = VAZIO;
            }
           }  
  
        }
    }
  }
void explodibambaesquerda(){

    int i;
    for (i=1; i<=3; i++){
      if (h.c - i< x.coluna) {
         if (x.matriz[h.l][h.c - i] == PAREDE_HORIZONTAL){
            break;
           }
         else{
             if ( x.matriz[h.l][h.c - i] == FANTASMA ){
                 x.matriz[h.l][h.c - i] = VAZIO;
            }
           }  
  
        }
    }
  }
void explodibombabaixo(){

    int i;
    for (i=1; i<=3; i++){
      if (h.l + i< x.coluna) {
        if (x.matriz[h.l + i][h.c] == PAREDE_HORIZONTAL){
            break;
           }
         else{
             if ( x.matriz[h.l + i][h.c] == FANTASMA ){
                 x.matriz[h.l + i][h.c] = VAZIO;
            }
           }  
  
        }
    }
  }
void explodibombacima(){

  int i;
  for (i=1; i<=3; i++){
    if (h.l - i< x.coluna) {
          if (x.matriz[h.l - i][h.c] == PAREDE_HORIZONTAL){
            break;
           }
         else{
             if ( x.matriz[h.l - i][h.c] == FANTASMA ){
                 x.matriz[h.l - i][h.c] = VAZIO;
            }
           }  
  
        }
    }
  }



void explodibomba(){

  
  
  if(power == 1){
    localizacomecome();
    //esplode bomba 03 casas para dir, esq, acima e abaixo
     explodibombadireita();
     explodibambaesquerda();
     explodibombabaixo();
     explodibombacima();
    
     telaboomm();
     
    }else{
      printf("\n\nBomba Não esta Armada!!!!");
      printf ("\n\nCOMA UMA PASTILHA!!!\n\n");
      
    }
    power = 0;
  
}   
   