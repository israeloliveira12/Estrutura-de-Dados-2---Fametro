#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fila.h"

#define MAX_CLIENTES 1000

typedef struct {
    char id[24];
    int qtd;
} Venda;

int comparar_vendas_desc(const void *a, const void *b) {
    return ((Venda*)b)->qtd - ((Venda*)a)->qtd;
}

int main() {
    Fila fila;
    inicializar(&fila);
    char comando[128];
    int estoque = 0;

    printf("Informe estoque inicial: ");
    scanf("%d", &estoque);
    getchar(); // remover \n

    Venda atendidos[MAX_CLIENTES];
    int atendidos_count = 0;
    Cliente nao_atendidos[MAX_CLIENTES];
    int nao_count = 0;

    while (1) {
        printf("Comando: ");
        if (!fgets(comando, sizeof(comando), stdin)) break;

        if (strncmp(comando, "ADD", 3) == 0) {
            Cliente c;
            sscanf(comando, "ADD %23s %d", c.id, &c.qtd);
            enfileirar(&fila, c);
        }
        else if (strncmp(comando, "START", 5) == 0) {
            while (!vazia(&fila) && estoque > 0) {
                Cliente c;
                desenfileirar(&fila, &c);

                if (c.qtd <= estoque) {
                    printf("Venda confirmada para %s: %d ingressos\n", c.id, c.qtd);
                    atendidos[atendidos_count++] = (Venda){.qtd=c.qtd};
                    strcpy(atendidos[atendidos_count-1].id, c.id);
                    estoque -= c.qtd;
                } else {
                    printf("Estoque insuficiente para %s (pediu %d, disponiveis %d). Aceita quantidade disponivel? (S/N): ", c.id, c.qtd, estoque);
                    char resp;
                    scanf(" %c", &resp);
                    getchar();
                    if (toupper(resp) == 'S') {
                        printf("Venda confirmada para %s: %d ingressos\n", c.id, estoque);
                        atendidos[atendidos_count++] = (Venda){.qtd=estoque};
                        strcpy(atendidos[atendidos_count-1].id, c.id);
                        estoque = 0;
                    } else {
                        printf("Cliente %s nao atendido.\n", c.id);
                        nao_atendidos[nao_count++] = c;
                    }
                }

                if (estoque == 0) {
                    printf("Estoque esgotado. Parando processamento.\n");
                    break;
                }
            }
        }
        else if (strncmp(comando, "REL", 3) == 0) {
            int total_vendido = 0;
            for (int i=0; i<atendidos_count; i++) total_vendido += atendidos[i].qtd;

            printf("Total vendido: %d\n", total_vendido);
            printf("Clientes atendidos: %d\n", atendidos_count);

            // Top-3 maiores compras
            qsort(atendidos, atendidos_count, sizeof(Venda), comparar_vendas_desc);
            printf("Top-3 maiores compras:\n");
            for (int i=0; i<3 && i<atendidos_count; i++)
                printf("%s: %d\n", atendidos[i].id, atendidos[i].qtd);

            printf("Estoque restante: %d\n", estoque);

            if (nao_count > 0) {
                printf("Clientes nao atendidos:\n");
                for (int i=0; i<nao_count; i++)
                    printf("%s: %d\n", nao_atendidos[i].id, nao_atendidos[i].qtd);
            } else {
                printf("Todos os clientes foram atendidos.\n");
            }
        }
        else if (strncmp(comando, "EXIT", 4) == 0) break;
        else printf("Comando invalido!\n");
    }

    limpar(&fila);
    return 0;
}
