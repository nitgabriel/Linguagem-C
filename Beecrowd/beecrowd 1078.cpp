#include <stdio.h>
 
int main() {
 int N, i, t;
	scanf("%d", &N);
	
	for( i = 1; i <= 10; i++){
		t = (i * N);
		printf("%d x %d = %d\n", i, N, t);	
	}

    return 0;
}
