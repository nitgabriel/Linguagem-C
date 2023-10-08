#include <stdio.h>

int main() {
    int n, valor, dentro = 0, fora = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &valor);
        if (valor >= 10 && valor <= 20) {
            dentro++;
        } else {
            fora++;
        }
    }

    printf("%d in\n", dentro);
    printf("%d out\n", fora);

    return 0;
}

