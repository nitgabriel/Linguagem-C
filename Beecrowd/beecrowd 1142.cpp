#include <stdio.h>

int main() {
    int n, i, j, k = 1;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= 3; j++) {
            printf("%d ", k); // Imprime o valor atual de k
            k++; // Incrementa o valor de k
        }
        printf("PUM\n"); // Imprime a palavra PUM após a sequência de números
        k++; // Incrementa k novamente para começar a próxima sequência
    }

    return 0;
}
