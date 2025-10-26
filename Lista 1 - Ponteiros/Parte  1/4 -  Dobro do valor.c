#include <stdio.h>

void dobrar(int *num) {
    *num *= 2;
}

int main() {
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);

    dobrar(&n);
    printf("Dobro do valor: %d\n", n);
    return 0;
}
