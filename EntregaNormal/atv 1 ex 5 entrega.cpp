#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define PI 3.1415

int main(void){
	setlocale (LC_ALL, "Portuguese_Brazil");
	double r, area, volume;
	
	printf("Digite um n�mero real R, para o c�lculo da �rea do c�rculo e o volume da esfera de raio R: \n");
	scanf("%lf", &r);
	
	area = PI * (r*r);
	volume = ((4/(float)3) * PI) * (r * r * r); //necess�rio float para divis�o
	
	printf("A �rea do c�rculo de raio R=%lf � igual a: %.3lf \n\n", r, area);
	printf("O volume da esfera de raio R=%lf � igual a: %.3lf \n\n", r, volume);	
	
	system("pause");
	
	return 0;
}

