#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#define DIREITA 'a'
#define ESQUERDA 'd'
#define CIMA 'w'
#define BAIXO 's'
#define VAZIO   '.'
#define PAREDE_VERTICAL   '|'
#define PAREDE_HORIZONTAL '-'
#define COMECOME '@'
#define FANTASMA 'F'
#define PILULA 'P'
#define BOMBA 'b'
#define FANTASMAGHOST 'G'
typedef struct mapa MAPA;
typedef struct posicao HEROI;
struct mapa{
  char** matriz;
  int linha, coluna;
}; MAPA x;

struct posicao{
   int l;
   int c;
   int lf;
   int cf;
}; HEROI h;
FILE* f;
int acaba = 0;
int power = 0;
int vencedor = 1;
