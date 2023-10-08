#include <stdio.h>

int main() {
    int n, i, menor = 101, posicao = 0, valor;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &valor);
        if (valor < menor) {
            menor = valor;
            posicao = i;
        }
    }
    printf("%d\n", posicao);
    return 0;
}

