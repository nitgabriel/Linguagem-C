#include <stdio.h>

int main() {
    int x;

    do {
        printf("Digite um numero inteiro (0 para sair): ");
        scanf("%d", &x);

        if (x > 0) {
            printf("%d eh positivo.\n", x);
        } else if (x < 0) {
            printf("%d eh negativo.\n", x);
        }
    } while (x != 0);

    printf("Saindo do programa...\n");

    return 0;
}

