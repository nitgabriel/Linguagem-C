#include <stdio.h>
#include <math.h>

int main() {
    float primeiro_termo, razao, termo_n, soma = 0;
    int n, i;

    printf("Digite o numero de termos: ");
    scanf("%d", &n);

    printf("Digite o primeiro termo: ");
    scanf("%f", &primeiro_termo);

    printf("Digite a razao: ");
    scanf("%f", &razao);

    termo_n = primeiro_termo;

    for (i = 1; i <= n; i++) {
        printf("Termo %d: %.f\n", i, termo_n);
        soma += termo_n;
        termo_n *= razao;
        }
        printf("Soma = %.f\n", soma);
        
return 0;
}
