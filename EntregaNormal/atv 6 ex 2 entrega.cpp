#include <stdio.h>

int main() {
    int vetor[10];
    int x, i;

    for (i = 0; i < 10; i++) {
        printf("Digite um valor inteiro (0 para sair): ");
        scanf("%d", &x);

        if (x == 0) {
            break;
        }

        vetor[i] = x;
    }

    printf("\nElementos do vetor:\n");

    for (i = 0; i < 10; i++) {
        if (vetor[i] != 0) {
            printf("%d\n", vetor[i]);
        }
    }

    return 0;
}

