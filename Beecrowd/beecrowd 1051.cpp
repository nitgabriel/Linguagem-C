#include <stdio.h>
 
int main() {
 double renda, taxa1 = 0.00, taxa2 = 0.00, taxa3 = 0.00, tt;
 double asc1, asc2, asc3, renda1;
    scanf("%lf", &renda);
    
    if (renda <= 2000.00){
        printf("Isento\n");
    } else if (renda > 2000.00 && renda <= 3000.00) {
        asc1 = renda - 2000.00;
        taxa1 = asc1 * 0.08;
        tt = taxa1 + taxa2 + taxa3;
        printf("R$ %.2lf\n", tt);
    } else if (renda > 3000.00 && renda <= 4500.00) {
        asc2 = renda - 3000.00;
        taxa2 = asc2 * 0.18;
        
        asc1 = renda - 2000.00;
        asc1 = asc1 - asc2;
        taxa1 = asc1 * 0.08;
        tt = taxa1 + taxa2 + taxa3;
        printf("R$ %.2lf\n", tt);
    } else if (renda > 4500.0) {
        asc3 = renda - 4500.00;
        taxa3 = asc3 * 0.28;
        
        
        asc2 = renda - 3000.00;
        asc2 = asc2 - asc3;
        taxa2 = asc2 * 0.18;
        
        
        asc1 = renda - 2000.00;
        asc1 = asc1 - asc2;
        asc1 = asc1 - asc3;
        taxa1 = asc1 * 0.080;
        tt = taxa1 + taxa2 + taxa3;
        printf("R$ %.2lf\n", tt);
    }
    
    
 
    return 0;
}
