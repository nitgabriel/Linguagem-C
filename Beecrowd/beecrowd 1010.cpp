#include <stdio.h>
 
int main() {
    int id, qtd, id2, qtd2;
    float preco, preco2, valortotal;
    
    scanf("%d %d %f", &id, &qtd, &preco);
    scanf("%d %d %f", &id2, &qtd2, &preco2);
    valortotal = ((preco * qtd) + (preco2 * qtd2));
    
    printf("VALOR A PAGAR: R$ %.2f\n", valortotal);
    
    
    return 0;
}
