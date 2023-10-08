#include <stdio.h>

int main() {
    int valor, maior, menor, quantidade = 0, soma = 0;

    printf("Digite um valor positivo (0 ou negativo para sair): ");
    scanf("%d", &valor);

    maior = valor;
    menor = valor;

    while (valor > 0) {
        quantidade++;
        soma += valor;

        if (valor > maior) {
            maior = valor;
        }

        if (valor < menor) {
            menor = valor;
        }

        printf("Digite um valor positivo (0 ou negativo para sair): ");
        scanf("%d", &valor);
    }

    if (quantidade > 0) {
        float media = (float) soma / quantidade;

        printf("Maior valor: %d\n", maior);
        printf("Menor valor: %d\n", menor);
        printf("Quantidade de valores: %d\n", quantidade);
        printf("Soma dos valores: %d\n", soma);
        printf("Media dos valores: %.2f\n", media);
    } else {
        printf("Nenhum valor informado.\n");
    }

    return 0;
}
