#include <stdio.h>
 
int main() {
    float n1, n2, n3, n4, media, exame, mediaf;
    scanf("%f %f %f %f", &n1, &n2, &n3, &n4);
    n1 = (n1/10) * 2;
    n2 = (n2/10) * 3;
    n3 = (n3/10) * 4;
    n4 = (n4/10) * 1;
    media = (n1 + n2 + n3 + n4);
    printf("Media: %.1f\n", media);
    if (media >= 7.0) {
       printf("Aluno aprovado.\n");
    } else if (media < 5.0) {
       printf("Aluno reprovado.\n");
    } else {
       printf("Aluno em exame.\n");
       scanf("%f", &exame);
       printf("Nota do exame: %.1f\n", exame);
       mediaf = (exame + media)/2;
       if (mediaf >= 5.0) {
           printf("Aluno aprovado.\n");
       } else {
           printf("Aluno reprovado.\n");
       }
       printf("Media final: %.1f\n", mediaf);    
    }
    
 
    return 0;
}
