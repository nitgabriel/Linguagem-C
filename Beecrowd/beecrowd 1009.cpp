#include <stdio.h>
 
int main() {
    char nome[50];
    double salfixo, vendas, salbonus;
    
    scanf("%s", &nome);
    fflush(stdin);
    scanf("%lf", &salfixo);
    scanf("%lf", &vendas);
    
    salbonus = (salfixo + (vendas * 0.15));
    
    printf("TOTAL = R$ %.2lf\n", salbonus);

    return 0;
}
