#include <stdio.h>

int main() {
    int n = 1, i, c = 0;
    double k, g;

    while(n == 1){
	
	scanf("%d", &i);
		if (i > 0){
			c += i;
			g++;
		} else {
			n = 2;
		}

    }

		k = (c/g);
		printf("%.2lf\n", k);
    
    return 0;
}

