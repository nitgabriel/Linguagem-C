#include <stdio.h>

int main() {
    int n, i, j, k = 1;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= 3; j++) {
            printf("%d ", k); // Imprime o valor atual de k
            k++; // Incrementa o valor de k
        }
        printf("PUM\n"); // Imprime a palavra PUM ap�s a sequ�ncia de n�meros
        k++; // Incrementa k novamente para come�ar a pr�xima sequ�ncia
    }

    return 0;
}
