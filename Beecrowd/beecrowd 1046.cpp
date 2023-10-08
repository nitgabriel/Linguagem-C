#include <stdio.h>

int main() {
    int hI, hF, duracao;
    
    scanf("%d", &hI);
    scanf("%d", &hF);
    
    if (hI < hF) {
        duracao = hF - hI;
    } else {
        duracao = 24 - hI + hF;
    }
    
    printf("O JOGO DUROU %d HORA(S)\n", duracao);
    
    return 0;
}

