/* Aula 11 - pgm 1 
   Ordenação em Vetor de inteiros - algoritmo BubbleSort
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

int main() {
  FILE *arq;
  int *V;
  int Tam;
  int X, i;
  bool Trocou;
  
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
  Trocou = true;
  while (Trocou) {  
    Trocou = false;
    for (i = 0; i < Tam-1; i++) {
      if (V[i] > V[i+1]) {
        X = V[i];
        V[i] = V[i+1];
        V[i+1] = X;
        Trocou = true;
      }
    }
  }

  printf("\nVetor apos a ordenacao\n");
  ExibeVetor(V, Tam);
  
  printf("\n\nFim do Programa\n");
  system("pause");
  return 0;
}











