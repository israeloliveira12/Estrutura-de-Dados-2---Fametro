#include <stdio.h>

void calculadora(float a, float b, float *soma, float *sub, float *mult, float *div) {
    *soma = a + b;
    *sub = a - b;
    *mult = a * b;
    *div = (b != 0) ? a / b : 0;
}

int main() {
    float x, y, soma, sub, mult, div;
    printf("Digite dois numeros: ");
    scanf("%f %f", &x, &y);

    calculadora(x, y, &soma, &sub, &mult, &div);
    printf("Soma: %.2f\nSubtracao: %.2f\nMultiplicacao: %.2f\nDivisao: %.2f\n", soma, sub, mult, div);
    return 0;
}
