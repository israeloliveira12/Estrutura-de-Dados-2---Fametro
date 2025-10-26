#include <stdio.h>
#include <ctype.h>

void contarVogaisConsoantes(char *str, int *vogais, int *consoantes) {
    *vogais = *consoantes = 0;
    while(*str != '\0') {
        char c = tolower(*str);
        if(c >= 'a' && c <= 'z') {
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') (*vogais)++;
            else (*consoantes)++;
        }
        str++;
    }
}

int main() {
    char str[100];
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    int vogais, consoantes;
    contarVogaisConsoantes(str, &vogais, &consoantes);
    printf("Vogais: %d, Consoantes: %d\n", vogais, consoantes);
    return 0;
}
