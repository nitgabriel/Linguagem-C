#include <stdio.h>

int main() {
    int qtd, id;
    double valor;
    
    scanf("%d", &id);
    scanf("%d", &qtd);
    
    if (id == 1) {
    valor = (4.00 * qtd);
    printf("Total: R$ %.2f\n", valor);
    } else{
    if (id == 2) {
    valor = (4.50 * qtd);
    printf("Total: R$ %.2lf\n", valor);    
    } else if (id == 3) {
    valor = (5.00 * qtd);
    printf("Total: R$ %.2lf\n", valor);    
    } else if (id == 4) {
    valor = (2.00 * qtd);
    printf("Total: R$ %.2lf\n", valor);    
    }else {
    valor = (1.50 * qtd);
    printf("Total: R$ %.2lf\n", valor);    
          }    
      }   
        
    
    
    return 0;
}
