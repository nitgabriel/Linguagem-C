#include <stdio.h>

int main() {
    int numero;

    printf("Digite um n�mero inteiro: ");
    scanf("%d", &numero);

    if(numero % 2 == 0) {
        printf("%d � um n�mero inteiro par.\n", numero);
    } else {
        printf("%d � um n�mero inteiro �mpar.\n", numero);
    }

    return 0;
}
