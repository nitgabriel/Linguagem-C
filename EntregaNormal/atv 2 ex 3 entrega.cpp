#include <stdio.h>

int main() {
    float peso;

    printf("Digite o peso do lutador: ");
    scanf("%f", &peso);

    if(peso < 65.0) {
        printf("Peso fornecido: %.1f\n", peso);
        printf("Este lutador pesa %.1f kg e se enquadra na categoria Ligeiro\n", peso);
    } else if(peso >= 65.0 && peso < 72.0) {
        printf("Peso fornecido: %.1f\n", peso);
        printf("Este lutador pesa %.1f kg e se enquadra na categoria Leve\n", peso);
    } else if(peso >= 72.0 && peso < 79.0) {
        printf("Peso fornecido: %.1f\n", peso);
        printf("Este lutador pesa %.1f kg e se enquadra na categoria Ligeiro\n", peso);
    } else if(peso >= 79.0 && peso < 86.0) {
        printf("Peso fornecido: %.1f\n", peso);
        printf("Este lutador pesa %.1f kg e se enquadra na categoria Meio médio\n", peso);
    } else if(peso >= 86.0 && peso < 93.0) {
        printf("Peso fornecido: %.1f\n", peso);
        printf("Este lutador pesa %.1f kg e se enquadra na categoria Médio\n", peso);
    } else if(peso >= 93.0 && peso < 100.0) {
        printf("Peso fornecido: %.1f\n", peso);
        printf("Este lutador pesa %.1f kg e se enquadra na categoria Meio pesado\n", peso);
    } else {
        printf("Peso fornecido: %.1f\n", peso);
        printf("Este lutador pesa %.1f kg e se enquadra na categoria Pesado\n", peso);
    }

    return 0;
}
