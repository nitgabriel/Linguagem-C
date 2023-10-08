/* Aula 11 - pgm 2 
   Ordenação em Vetor de inteiros - algoritmo BubbleSort implementado em função
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void ExibeVetor(int *pV, int pTam) {
  int i;
  for (i = 0; i < pTam; i++) {
    printf("%5d", pV[i]);
    if (i > 0 && i % 10 == 0)
      printf("\n");
  }
}

void BubbleSort(int *pV, int pTam) {
  int X, i;
  bool Trocou = true;
  while (Trocou) {
    Trocou = false;
    for (i = 0; i < pTam-1; i++) {
      if (pV[i] > pV[i+1]) {
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
  int *V;
  int Tam;
  int X;
  
  arq = fopen("dados.txt", "r");
  V = NULL;
  Tam = 0;
  while (fscanf(arq, "%d", &X) != EOF) {
    Tam++;
    V = (int *)realloc(V, sizeof(int) * Tam);
    V[Tam-1] = X;
  }
  fclose(arq);
  
  printf("Vetor original - sem ordem\n");
  ExibeVetor(V, Tam);
  
  // Algoritmo BubbleSort
  BubbleSort(V, Tam);

  printf("\nVetor apos a ordenacao\n");
  ExibeVetor(V, Tam);
  
  printf("\n\nFim do Programa\n");
  system("pause");
  return 0;
}











