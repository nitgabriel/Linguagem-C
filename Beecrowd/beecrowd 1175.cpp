#include <stdio.h>

int main() {
    int n[20];
    int i, j, temp;

    for(i = 0; i < 20; i++) {
        scanf("%d", &n[i]);
    }

    for(i = 0, j = 20 - 1; i < j; i++, j--) {
        temp = n[i];
        n[i] = n[j];
        n[j] = temp;
    }

    for(i = 0; i < 20; i++) {
        printf("N[%d] = %d\n", i, n[i]);
    }

    return 0;
}

