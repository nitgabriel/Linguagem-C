#include <stdio.h>

int main() {
    int n, i, primeiro = 0, segundo = 1, proximo;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("%d", primeiro);

        if (i < n) { 
            printf(" ");
        }

        proximo = primeiro + segundo;
        primeiro = segundo;
        segundo = proximo;
    }

    printf("\n");

    return 0;
}
