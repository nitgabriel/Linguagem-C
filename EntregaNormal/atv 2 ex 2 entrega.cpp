#include <stdio.h>

int main() {
    int numero;

    printf("Digite um número: ");
    scanf("%d", &numero);

    if(numero > 0) {
        printf("%d o número inserido é positivo.\n", numero);
    } else if(numero < 0) {
        printf("%d o número inserido é negativo.\n", numero);
    } else {
        printf("%d o número inserido é zero.\n", numero);
    }

    return 0;
}
