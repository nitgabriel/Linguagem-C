#include <stdio.h>

int main() {
    int i = 0, p;
    double x, m=0, p1;
    
    while (i<6) {
        scanf("%lf", &x);
        
        if (x > 0){
            p++;
            p1++;
        m += x;    
        }
        i++;

        }
        m = (m/p1);
        printf("%d valores positivos\n", p);
        printf("%.1lf\n", m);

    return 0;
}
