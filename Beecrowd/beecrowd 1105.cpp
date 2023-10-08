#include <stdio.h>

int main() {
    int b, n, d, c, v, reservas[21];
    while (1) {
        scanf("%d %d", &b, &n);
        if (b == 0 && n == 0) break;
        for (int i = 1; i <= b; i++) {
            scanf("%d", &reservas[i]);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d %d %d", &d, &c, &v);
            reservas[d] -= v;
            reservas[c] += v;
        }
        int possivel = 1;
        for (int i = 1; i <= b; i++) {
            if (reservas[i] < 0) {
                possivel = 0;
                break;
            }
        }
        if (possivel) {
            printf("S\n");
        } else {
            printf("N\n");
        }
    }
    return 0;
}

