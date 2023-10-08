#include <stdio.h>
 
int main() {
    double X, N[100], Y;
    int i;
    
    scanf("%lf", &X);
    
    N[0] = X;
    
        for(i=0; i<= 99; i++){
            if(i>0){
           N[i] = (N[i-1] / 2);
            printf("N[%d] = %.4lf\n", i, N[i]);
            } else {
            printf("N[0] = %.4lf\n", N[0]);    
            }
        }
 


    return 0;
}
