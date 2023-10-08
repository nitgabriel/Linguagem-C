#include <stdio.h>
 
int main() {
    int N[10], V, i = 0;
 
    scanf("%d", &V);
    
    N[0] = V;
    
    for (i = 0; i <= 9; i++){
        if (i >= 1){
            N[i] = (N[i-1] * 2);
            printf("N[%d] = %d\n", i, N[i]);
        } else {
            printf("N[%d] = %d\n", i, N[i]);
        }

    }
    return 0;
}
