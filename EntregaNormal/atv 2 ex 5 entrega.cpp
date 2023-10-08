#include <stdio.h>

int main() {
    float a, b, c;

    printf("Digite os tres números a serem checados como lados do triangulo: ");
    scanf("%f %f %f", &a, &b, &c);

    if ((a + b > c) && (a + c > b) && (b + c > a)) {
        if (a == b && b == c) {
            printf("O triangulo e equilatero.\n");
        } else if (a == b || a == c || b == c) {
            printf("O triangulo e isosceles.\n");
        } else {
            printf("O triangulo e escaleno.\n");
        }
    } else {
        printf("Os lados informados nao formam um triangulo.\n");
    }

    return 0;
}
