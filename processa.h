#pragma once
#include "cabecalho.h"
#include "tela.h"
#include "telajogo.h"
#include "explodebomba.h"
//finaliza o jogo com jogador como vencedor
int venceu(int *vencedor){
  if (*vencedor == 0){
        imprimimapa();
        telaganhou();
        return 1;
        
     }
  
 return 0;
}
//finaliza o jogo com jogador como perdedor
int acabou(int *acaba){
    
    if (*acaba == 1){
        telaperdeu();
        return 1;
        
     }
  
 return 0;
  }

//movimenta fisicamente o fantamas na matriz
void movimentarfantasma(int posicao, int lf, int cf){

     switch (posicao){
        case 0:
          h.lf--;
          break;
        case 1:
          h.lf ++;
          break;
        case 2:
          h.cf --;
          break;
        case 3:
          h.cf ++;
          break;
      } 
   }

//verifica se o espaco é vazio ou comecome para o fantasma se movimentar
int ehvalido(int lf, int cf){

  if (x.matriz[h.lf][h.cf] == VAZIO || x.matriz[h.lf][h.cf] == COMECOME){
      return 1;
    }
  return 0;
}
//verifica se o espaco é o comecome
int ehcomecome(int lf, int cf){

  if (x.matriz[h.lf][h.cf] == COMECOME ){
    return 1;
    }
  return 0;
  }
// verifica se o espaco é vazio
int ehvazio(int lf, int cf){

    if (x.matriz[h.lf][h.cf] == VAZIO ){
        return 1;
      }
  return 0;
}
//movimenta fisicamente o fantasma na matriz depois de todas os testes
void andarmatrizfantasma(int lf, int cf, int i, int j){
  
   x.matriz[i][j] = VAZIO;
   x.matriz[h.lf][h.cf] = FANTASMA;
  
}

// transforma o fantasma em ghost para podermos movimentar na matriz uma vez cada um na rodada
void transformafantasmaemcomghost(){

  int i,j;

  for(i=1; i<x.linha; i++){
      for(j=1; j<x.coluna; j++){
          if (x.matriz[i][j] == FANTASMA){
              x.matriz[i][j] = FANTASMAGHOST;
                }
        }
    }
}
//movimentar qualquer ghost uma vez na matriz, transformando em outra constante fantasma para garantir um movimento e 01 vez de cada fantasma
int transformaghostemfantasma(int i, int j){

  
   if (x.matriz[i][j] == FANTASMAGHOST){
          x.matriz[i][j] = FANTASMA;
          return 1;
     }
  return 0;
}
//verifica se existe fantasma e declarar vendedor
void pesquisaseexistefantasma(){

  int i, j;
  vencedor = 0;
    for(i=1; i<x.linha; i++){
      for(j=1; j<x.coluna; j++){
          if (x.matriz[i][j] == FANTASMA ){
            vencedor = 1;
            
          }
       }

      }
  
}
//localizar os fantasmas na matriz
void localizafantasma(){

  int i, j, posicao, posicaovalida;
  srand(time(0)); 
   
  transformafantasmaemcomghost();
    for(i=1; i<x.linha; i++){
      posicaovalida = 0;
      for(j=1; j<x.coluna; j++){
         if (transformaghostemfantasma(i,j)){
         while (!posicaovalida){
          posicao = rand() % 4;
          h.lf = i;
          h.cf = j;
          movimentarfantasma(posicao, h.lf, h.cf);
          if(ehvalido(h.lf, h.cf)){
            if(ehcomecome(h.lf, h.cf)){
              andarmatrizfantasma(h.lf, h.cf,i,j);
              imprimimapa();
              acaba = 1;
              }
              andarmatrizfantasma(h.lf, h.cf,i,j);
              posicaovalida = 1;
                
            }
          }
             
        }
          
      }
    }
    pesquisaseexistefantasma();
  }


//verificar se o comando é válido digitado pelo jogador
void direcao(char comando){

  if (comando != DIREITA && comando != ESQUERDA && comando != BAIXO && comando != CIMA){
    return ;
  }
  
}
//movimenta o comecome na matriz, uma casa por vez
void andarmatriz(int proximal, int proximac){

    if (x.matriz[proximal][proximac] == PILULA ){
          power = 1;
          x.matriz[h.l][h.c] = VAZIO;
          x.matriz[proximal][proximac] = COMECOME;
          
          }
        else {
          if (x.matriz[proximal][proximac] != VAZIO ){
            return ;
            }
             else{
               x.matriz[h.l][h.c] = VAZIO;
               x.matriz[proximal][proximac] = COMECOME;
               }
            }  
      h.l = proximal;
      h.c = proximac;
  
  }
//explodi bomba destruindo apenas fantasma ate 03 casas para cima, para baixo, para direita e para esquerda. Lotes foram separados por funcoes próprias
 
//move fisicamente na planilha o comecome
void move(char comando){

  int proximal, proximac;

  proximal = h.l;
  proximac = h.c;
  
      
  switch (comando){
    case DIREITA:
      proximac--;
      break;         
    case CIMA:
      proximal--;
      break; 
    case BAIXO:
      proximal++;
      break; 
    case ESQUERDA:
      proximac++;
      break; 
    case BOMBA:
      explodibomba();
      break;
    }
    
    andarmatriz(proximal, proximac);
    localizafantasma();
 }

void abriarquivo(){

   f = fopen("mapa.txt", "r");
   if (f == 0){
    printf("Erro na leitura do mapa...");
    exit(1);
   }
   fscanf(f,"%d %d", &x.linha, &x.coluna);

}

void alocamapa(){

  int i;
  
    x.matriz = (char**) malloc(sizeof (char* ) * (x.linha));
   for(i=0; i<x.linha; i++){
      x.matriz[i] =(char*)malloc(sizeof (char) * (x.coluna));
     }
  
}
 
void lermapa(){

  int i, j;
  f = fopen("mapa.txt", "r");
   if (f == 0){
      printf("Erro na leitura do mapa...");
      exit(1);
     }
   fscanf(f,"%d %d", &x.linha, &x.coluna);

   alocamapa();
   
   for (i = 0; i < x.linha; i++){
     for (j = 0; j < x.coluna; j++){
         fscanf(f, " %c", &x.matriz[i][j]);
      }
    }
  
  
  
  fclose(f);
}

  

void liberamapa(){

  int i;
  
  for(i=0; i<x.linha; i++){
    free(x.matriz[i]);
    }
  free(x.matriz);
  
 }

  
  
