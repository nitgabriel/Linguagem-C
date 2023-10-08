#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {
	setlocale(LC_ALL, "Portuguese_Brazil");
    float base, altura, area;
    
    printf("Digite o valor da base do triângulo: ");
    scanf("%f", &base);
    
    printf("Digite o valor da altura do triângulo: ");
    scanf("%f", &altura);
    
    area = (base * altura) / 2;
    
    printf("A área do triângulo é: %.2f\n", area);
    system("pause");
        
    return 0;
}
