#include <stdio.h>

int main() {
    int numero;

    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    if(numero % 2 == 0) {
        printf("%d é um número inteiro par.\n", numero);
    } else {
        printf("%d é um número inteiro ímpar.\n", numero);
    }

    return 0;
}
