#include <stdio.h>
#include <string.h>

void inverterString(char *str) {
    int i = 0, j = strlen(str) - 1;
    while(i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int main() {
    char str[100];
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);
    if(str[strlen(str)-1]=='\n') str[strlen(str)-1]='\0';

    inverterString(str);
    printf("String invertida: %s\n", str);
    return 0;
}
