#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main (void){
	setlocale(LC_ALL, "Portuguese_Brazil");
    float vHora, salBruto;
    int horasNormais, horasExtras;

    printf("Insira o valor por hora: ");
    scanf("%f", &vHora);
    printf("Insira o n�mero de horas normais: ");
    scanf("%d", &horasNormais);
    printf("Insira o n�mero de horas extras: ");
    scanf("%d", &horasExtras);

    salBruto = (horasNormais * vHora) + (horasExtras * vHora * 2);
    printf("O sal�rio bruto � de: R$ %.2f\n", salBruto);
    system("pause");

    return 0;
}

