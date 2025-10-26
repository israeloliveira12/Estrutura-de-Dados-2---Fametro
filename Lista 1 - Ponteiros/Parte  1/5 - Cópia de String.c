#include <stdio.h>

void copiarString(char *origem, char *destino) {
    while(*origem != '\0') {
        *destino = *origem;
        origem++;
        destino++;
    }
    *destino = '\0';
}

int main() {
    char str1[100], str2[100];
    printf("Digite uma string: ");
    fgets(str1, sizeof(str1), stdin);
    
    // Remove o '\n' se existir
    if(str1[strlen(str1)-1] == '\n') str1[strlen(str1)-1] = '\0';
    
    copiarString(str1, str2);
    printf("String copiada: %s\n", str2);
    return 0;
}
