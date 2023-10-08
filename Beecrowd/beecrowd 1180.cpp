#include <stdio.h>

int main() {
    int N, i, menorvalor, pos;
    scanf("%d", &N);
    int X[N];
    for (i = 0; i < N; i++) {
        scanf("%d", &X[i]);
        if (i == 0 || X[i] < menorvalor) {
            menorvalor = X[i];
            pos = i;
        }
    }
    printf("Menor valor: %d\n", menorvalor);
    printf("Posicao: %d\n", pos);
    return 0;
}
