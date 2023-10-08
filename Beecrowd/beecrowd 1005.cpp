#include <stdio.h>
 
int main() {
    double A, B, media;
    
    scanf("%lf", &A);
    scanf("%lf", &B);
    
    media = (A * (3.50/11)) + (B * (7.50/11));
    printf("MEDIA = %.5lf\n", media);
 
    return 0;
}
