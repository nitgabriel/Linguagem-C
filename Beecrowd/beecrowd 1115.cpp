#include <stdio.h>

int main() {
    int x, y, i;

    do
	{
	scanf("%d %d", &x, &y);

    	if (x == 0 || y == 0){
	    break;
	    } else if (x > 0 && y > 0) {
	    printf("primeiro\n");
	    } else if (x < 0 && y > 0) {
	    printf("segundo\n");
	    } else if (x < 0 && y < 0) {
	    printf("terceiro\n");
	    } else if (x > 0 && y < 0) {
	    printf("quarto\n");
	    }
	    
    

    } while (i != 2);
    return 0;
}

