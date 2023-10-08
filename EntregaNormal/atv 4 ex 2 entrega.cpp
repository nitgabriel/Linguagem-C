#include <stdio.h>

int main() {
    int num, total_positivos = 0, total_negativos = 0;

    do {
        printf("Digite um numero inteiro (0 para sair): ");
        scanf("%d", &num);

        if (num > 0) {
            total_positivos += num;
        } else if (num < 0) {
            total_negativos += num;
        }
    } while (num != 0);

    printf("Total dos positivos = %d\n", total_positivos);
    printf("Total dos negativos = %d\n", total_negativos);

    return 0;
}

