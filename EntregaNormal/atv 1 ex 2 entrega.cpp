#include <stdio.h>

int main() {
    int a, b, c, d;
    int soma;
    float media;

    printf("Digite o valor de A: ");
    scanf("%d", &a);

    printf("Digite o valor de B: ");
    scanf("%d", &b);

    printf("Digite o valor de C: ");
    scanf("%d", &c);

    printf("Digite o valor de D: ");
    scanf("%d", &d);

    soma = a + b + c + d;

    media = (float)soma / 4;

    printf("Soma: %d\n", soma);
    printf("Média: %.2f\n", media);

    return 0;
}

