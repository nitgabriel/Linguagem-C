/* Aula 11 - pgm 3 
   Ordenação em Vetor de structs - algoritmo BubbleSort implementado em função
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct TEntrada {
  int Codigo;
  int Qtde;
  double Valor;
  double Total;
};

void ExibirVetorStruct(TEntrada *pDados, int pTam) {
  int i;
  for (i = 0; i < pTam; i++) {
    printf("%6d  %4d  %8.2lf  %9.2lf\n", 
      pDados[i].Codigo,
      pDados[i].Qtde,
      pDados[i].Valor,
      pDados[i].Total
    );
  }
}

void BubbleSortCodigo(TEntrada *pV, int pTam) {
  TEntrada X; 
  int i;
  bool Trocou = true;
  while (Trocou) {
    Trocou = false;
    for (i = 0; i < pTam-1; i++) {
      if (pV[i].Codigo > pV[i+1].Codigo) {
        X = pV[i];
        pV[i] = pV[i+1];
        pV[i+1] = X;
        Trocou = true;
      }
    }
  }
}

void BubbleSortTotal(TEntrada *pV, int pTam) {
  TEntrada X; 
  int i;
  bool Trocou = true;
  while (Trocou) {
    Trocou = false;
    for (i = 0; i < pTam-1; i++) {
      if (pV[i].Total < pV[i+1].Total) {
        X = pV[i];
        pV[i] = pV[i+1];
        pV[i+1] = X;
        Trocou = true;
      }
    }
  }
}

int main() {
  FILE *arq;
  TEntrada *V;
  TEntrada aux;
  int Tam;
  int X;
  
  arq = fopen("dadosstruct.txt", "r");
  V = NULL;
  Tam = 0;
  while (fscanf(arq, "%d;%d;%lf\n", &aux.Codigo, &aux.Qtde, &aux.Valor) != EOF) {
    aux.Total = aux.Qtde * aux.Valor;
    Tam++;
    V = (TEntrada *)realloc(V, sizeof(TEntrada) * Tam);
    V[Tam-1] = aux;
  }
  fclose(arq);
  
  printf("Vetor original - sem ordem\n");
  ExibirVetorStruct(V, Tam);
  
  BubbleSortCodigo(V, Tam);
  printf("\nVetor apos a ordenacao por Codigo crescente\n");
  ExibirVetorStruct(V, Tam);
  
  BubbleSortTotal(V, Tam);
  printf("\nVetor apos a ordenacao por Total decrescente\n");
  ExibirVetorStruct(V, Tam);

  printf("\n\nFim do Programa\n");
  system("pause");
  return 0;
}











