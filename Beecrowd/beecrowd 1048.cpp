#include <stdio.h>

int main() {
    float sal, nsal, reajuste;
    int percentual;

    scanf("%f", &sal);

    if (sal <= 400.0) {
        percentual = 15;
    } else if (sal <= 800.0) {
        percentual = 12;
    } else if (sal <= 1200.0) {
        percentual = 10;
    } else if (sal <= 2000.00) {
        percentual = 7;
    } else if (sal > 2000.00) {
        percentual = 4;
    }

    reajuste = sal * percentual / 100.0;
    nsal = sal + reajuste;

    printf("Novo salario: %.2f\n", nsal);
    printf("Reajuste ganho: %.2f\n", reajuste);
    printf("Em percentual: %d %%\n", percentual);

    return 0;
}
