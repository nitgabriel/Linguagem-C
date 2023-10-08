#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main (void){
	setlocale(LC_ALL, "Portuguese_Brazil");
	int a, b;
	float soma1, soma2, resp;
	
	printf("Calculo segundo a forma R = (3A + 2B) / A + B. \nForneça os valores necessários. ");
	printf("\nForneça o primeiro valor:  ");
	scanf("%d", &a);
	
	printf("\nForneça o segundo valor:  ");
	scanf("%d", &b);
	
	soma1 = (3 * a) + (2 * b);
	soma2 = (a + b);
	resp = soma1 / soma2;
	system("cls");
	
	printf("Seguindo a fórmula, o resultado se dá: %.3f", resp);
        system("pause");
	
	return 0;
}
