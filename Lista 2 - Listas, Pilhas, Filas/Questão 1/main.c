#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

int main() {
    Produto *estoque = NULL;
    char comando[128];

    while (1) {
        printf("Comando: ");
        if (!fgets(comando, sizeof(comando), stdin)) break;

        if (strncmp(comando, "ADD", 3) == 0) {
            Produto p;
            sscanf(comando, "ADD %15s \"%63[^\"]\" %d %f", p.codigo, p.nome, &p.qtd, &p.preco);
            estoque = inserir_ordenado_por_codigo(estoque, p);
        } 
        else if (strncmp(comando, "UPD", 3) == 0) {
            char codigo[16];
            int delta;
            sscanf(comando, "UPD %15s %d", codigo, &delta);
            estoque = ajustar_quantidade(estoque, codigo, delta);
        } 
        else if (strncmp(comando, "DEL", 3) == 0) {
            char codigo[16];
            sscanf(comando, "DEL %15s", codigo);
            estoque = remover_por_codigo(estoque, codigo);
        } 
        else if (strncmp(comando, "FIND", 4) == 0) {
            char codigo[16];
            sscanf(comando, "FIND %15s", codigo);
            Produto *p = buscar(estoque, codigo);
            if (p) printf("%s | %s | %d | %.2f\n", p->codigo, p->nome, p->qtd, p->preco);
            else printf("Produto nao encontrado.\n");
        } 
        else if (strncmp(comando, "LIST", 4) == 0) listar(estoque);
        else if (strncmp(comando, "REL", 3) == 0) relatorio(estoque);
        else if (strncmp(comando, "EXIT", 4) == 0) break;
        else printf("Comando invalido!\n");
    }

    estoque = limpar(estoque);
    return 0;
}
