#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main (void){
	setlocale(LC_ALL, "Portuguese_Brazil");
	int a, b;
	float soma1, soma2, resp;
	
	printf("Calculo segundo a forma R = (3A + 2B) / A + B. \nForne�a os valores necess�rios. ");
	printf("\nForne�a o primeiro valor:  ");
	scanf("%d", &a);
	
	printf("\nForne�a o segundo valor:  ");
	scanf("%d", &b);
	
	soma1 = (3 * a) + (2 * b);
	soma2 = (a + b);
	resp = soma1 / soma2;
	system("cls");
	
	printf("Seguindo a f�rmula, o resultado se d�: %.3f", resp);
        system("pause");
	
	return 0;
}
