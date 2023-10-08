#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define PI 3.1415

int main(void){
	setlocale (LC_ALL, "Portuguese_Brazil");
	double r, area, volume;
	
	printf("Digite um número real R, para o cálculo da área do círculo e o volume da esfera de raio R: \n");
	scanf("%lf", &r);
	
	area = PI * (r*r);
	volume = ((4/(float)3) * PI) * (r * r * r); //necessário float para divisão
	
	printf("A área do círculo de raio R=%lf é igual a: %.3lf \n\n", r, area);
	printf("O volume da esfera de raio R=%lf é igual a: %.3lf \n\n", r, volume);	
	
	system("pause");
	
	return 0;
}

