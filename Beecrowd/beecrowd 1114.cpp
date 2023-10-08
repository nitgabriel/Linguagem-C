#include <stdio.h>

int main() {
    int x, i;

    do
	{
	scanf("%d", &x);
        if (x != 2002) {
            printf("Senha Invalida\n");
        } else {
            printf("Acesso Permitido\n");
            break;
        }
    } while (i != 2);
    return 0;
}

