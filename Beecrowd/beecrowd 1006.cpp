#include <stdio.h>
 
int main() {
    double A, B, C, media;
    
    scanf("%lf", &A);    
    scanf("%lf", &B);    
    scanf("%lf", &C);
     
    media = ((A * (2.0/10))+(B * (3.0/10))+ (C * (5.0/10)));
    printf("MEDIA = %.1lf\n", media);
     
    return 0;
}
