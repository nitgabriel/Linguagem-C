#include <stdio.h>

int main() {
    int numero;

    printf("Digite um n�mero: ");
    scanf("%d", &numero);

    if(numero > 0) {
        printf("%d o n�mero inserido � positivo.\n", numero);
    } else if(numero < 0) {
        printf("%d o n�mero inserido � negativo.\n", numero);
    } else {
        printf("%d o n�mero inserido � zero.\n", numero);
    }

    return 0;
}
