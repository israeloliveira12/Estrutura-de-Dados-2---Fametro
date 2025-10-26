#include <stdio.h>

int main() {
    int valor = 10;
    int *ptr = &valor;

    printf("Valor: %d\n", valor);
    printf("Endereco da variavel: %p\n", &valor);
    printf("Valor do ponteiro: %p\n", ptr);
    printf("Valor apontado pelo ponteiro: %d\n", *ptr);

    return 0;
}
