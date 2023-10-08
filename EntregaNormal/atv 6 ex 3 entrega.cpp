#include <stdio.h>

int main() {
    int V[15] = {17, 4, 53, 38, 22, 40, 25, 16, 31, 64, 45, 32, 20, 12, 29};
    int A, i, posicao = -1;

    do {
        printf("Digite um valor inteiro (0 para sair): ");
        scanf("%d", &A);

        if (A > 0) {
            for (i = 0; i < 15; i++) {
                if (V[i] == A) {
                    posicao = i;
                    break;
                }
            }

            if (posicao != -1) {
                printf("O valor %d está no vetor na posição %d\n", A, posicao);
            } else {
                printf("O valor %d não está no vetor\n", A);
            }

            posicao = -1; 
        }
    } while (A > 0);

    return 0;
}

