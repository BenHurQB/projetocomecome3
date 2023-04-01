#include "cabecalho.h"
#include "processa.h"

void colocarcomecome(){

  int linha, coluna, posicaovalida,  i;
    
    srand(time(0));
    
    linha = 2;
    posicaovalida = 0;
    while(!posicaovalida){
      for (i=0; i<10; i++){
        coluna =  1 +  rand() % 7;
        if (x.matriz[linha][coluna] == VAZIO && x.matriz[linha][coluna + 1] == VAZIO ){
          x.matriz[linha][coluna] = COMECOME;
          posicaovalida = 1;
          break;
          }
        }
        
    }
    h.l = linha;
    h.c = coluna;
   }

void colocarfantasma(){
  int linha, coluna, posicaovalida,  i;
    
    srand(time(0));
    
    linha = 2;
    while(linha <= 3){
      
      posicaovalida = 0;
      while(!posicaovalida){
      for (i=0; i<10; i++){
        coluna =  1 +  rand() % 7;
        if (x.matriz[linha][coluna] == VAZIO && x.matriz[linha][coluna + 1] == VAZIO){
          x.matriz[linha][coluna] = FANTASMA;
            posicaovalida = 1;
            break;
          }
        }
        linha = linha + 1;
      }
    }
  }

void colocarpilula(){
  int linha, coluna, posicaovalida,  i;
    
    srand(time(0));
    
    linha = 1;
    while(linha <= 3){
      
      posicaovalida = 0;
      while(!posicaovalida){
        for (i=0; i<10; i++){
          coluna =  1 +  rand() % 7;
          if (x.matriz[linha][coluna] == VAZIO && x.matriz[linha][coluna-1] == VAZIO){
            x.matriz[linha][coluna] = PILULA;
            posicaovalida = 1;
            break;
          }
        }
      
      }
      linha = linha + 2;  
    }
 }

  void cenarioum(int linha){

    int  coluna, coluna1, coluna2;
    
    coluna = 1 + rand() % 3;
    x.matriz[linha][coluna] = PAREDE_HORIZONTAL;
    coluna = 6 + rand() % 3;
    x.matriz[linha][coluna] = PAREDE_HORIZONTAL;
    coluna1 = 3 + rand() % 2;
    x.matriz[linha+1][coluna1] = PAREDE_HORIZONTAL;
    coluna2 = 6 + rand() % 3;
    x.matriz[linha+2][coluna2] = PAREDE_HORIZONTAL;

  }

  void cenariodois(int linha){

    int  coluna, coluna1, coluna2;

    coluna = 1 + rand() % 3;
    x.matriz[linha-1][coluna] = PAREDE_HORIZONTAL;
    coluna = 6 + rand() % 3;
    x.matriz[linha-1][coluna] = PAREDE_HORIZONTAL;
    coluna1 = 3 + rand() % 2;
    x.matriz[linha][coluna1] = PAREDE_HORIZONTAL;
    coluna2 = 6 + rand() % 3;
    x.matriz[linha+1][coluna2] = PAREDE_HORIZONTAL;

    
  }

  void cenariotres(int linha){

   int  coluna, coluna1, coluna2;

    coluna = 1 + rand() % 3;
    x.matriz[linha][coluna] = PAREDE_HORIZONTAL;
    coluna = 6 + rand() % 3;
    x.matriz[linha][coluna] = PAREDE_HORIZONTAL;
    coluna1 = 3 + rand() % 2;
    x.matriz[linha-1][coluna1] = PAREDE_HORIZONTAL;
    coluna2 = 6 + rand() % 3;
    x.matriz[linha-2][coluna2] = PAREDE_HORIZONTAL;
    
  }
  void colocarparedehorizontal(){
  
   int linha, coluna, coluna1, coluna2;
    
    srand(time(0));
    linha = 1 + rand() % 2;

    if (linha == 1){
      cenarioum(linha);
    }
    else{
      if (linha == 2){
        cenariodois(linha);
      }
      else{
        cenariotres(linha);
      }
    }
    
  }
void comecarojogo(){

    colocarparedehorizontal();
    colocarpilula();
    colocarfantasma();
    colocarcomecome();

    
  }  
  