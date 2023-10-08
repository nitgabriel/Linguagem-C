#include <stdio.h>
 
int main() {
    int horas, num;
    float vhora, sal;
    
    scanf("%d", &num);
    scanf("%d", &horas);
    scanf("%f", &vhora);
    
    sal = horas * vhora;
    
    printf("NUMBER = %d\nSALARY = U$ %.2f\n", num,sal);
 
    return 0;
}
