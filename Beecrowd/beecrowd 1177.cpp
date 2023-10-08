#include <stdio.h>

int main() {
    int T, N[1000], i, c;
    scanf("%d", &T);
    
    for(i=0; i<1000; i++){
        c = i % T;
        N[i] = c;
        printf("N[%d] = %d\n", i, N[i]);
    }
    
    return 0;
}

