#include <stdio.h>

int main() {
    int i = 0, p;
    double x;
    
    while (i<6) {
        scanf("%lf", &x);
        
        if (x > 0){
            p++;
        }
        i++;

        }
        printf("%d valores positivos\n", p);
    

    return 0;
}
