#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main() {
    Pilha p;
    pilha_init(&p);
    char comando[128];

    while (1) {
        printf("Comando: ");
        if (!fgets(comando, sizeof(comando), stdin)) break;

        if (strncmp(comando, "CALL", 4) == 0) {
            char func[48];
            int sp;
            sscanf(comando, "CALL %47s %d", func, &sp);
            if (push(&p, func, sp))
                printf("Frame %s empilhado (SP=%d).\n", func, sp);
            else
                printf("Erro ao empilhar frame.\n");
        }
        else if (strncmp(comando, "RET", 3) == 0) {
            Frame f;
            if (pop(&p, &f))
                printf("Frame %s desempilhado (SP=%d).\n", f.func, f.sp);
            else
                printf("Pilha vazia! Nenhum frame para desempilhar.\n");
        }
        else if (strncmp(comando, "PEEK", 4) == 0) {
            Frame f;
            if (peek(&p, &f))
                printf("Topo: %s (SP=%d)\n", f.func, f.sp);
            else
                printf("Pilha vazia!\n");
        }
        else if (strncmp(comando, "TRACE", 5) == 0) {
            Frame *tmp = p.topo;
            int nivel = 0;
            if (!tmp) {
                printf("Pilha vazia!\n");
                continue;
            }
            printf("TRACE da pilha:\n");
            while (tmp) {
                printf("Nivel %d: %s (SP=%d)\n", nivel, tmp->func, tmp->sp);
                tmp = tmp->baixo;
                nivel++;
            }
        }
        else if (strncmp(comando, "EXIT", 4) == 0) break;
        else printf("Comando invalido!\n");
    }

    limpar(&p);
    return 0;
}
