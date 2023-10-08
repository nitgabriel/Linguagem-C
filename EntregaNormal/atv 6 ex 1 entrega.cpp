#include <stdio.h>
 
int main() {
    int A[5] = {19,23,29,31,37}, i;
 
    for (i = 0; i <= 4; i++){
    printf("O %dº numero do vetor é: %d\n", i, A[i]);
        }
    for (i = 4; i >= 0; i--){
    printf("O %dº numero do vetor é: %d\n", i, A[i]);
        }
 
    return 0;
}
