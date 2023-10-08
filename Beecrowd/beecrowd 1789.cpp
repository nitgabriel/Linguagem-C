#include <stdio.h>

int main() {
    int n, v, i, max, nivel;
    while (scanf("%d", &n) != EOF) {
        max = 0;
        for (i = 1; i <= n; i++) {
            scanf("%d", &v);
            if (v > max) {
                max = v;
            }
        }
        if (max < 10) {
            nivel = 1;
        } else if (max < 20) {
            nivel = 2;
        } else {
            nivel = 3;
        }
        printf("%d\n", nivel);
    }
    return 0;
}
