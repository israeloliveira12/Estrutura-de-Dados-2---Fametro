#ifndef PRODUTO_H
#define PRODUTO_H

#include <stdbool.h>

typedef struct Produto {
    char codigo[16];
    char nome[64];
    int qtd;
    float preco;
    struct Produto *prox;
} Produto;

// Funções da lista ligada
Produto* inserir_inicio(Produto *L, Produto p);                     // O(1)
Produto* inserir_ordenado_por_codigo(Produto *L, Produto p);        // O(n)
Produto* remover_por_codigo(Produto *L, const char *codigo);        // O(n)
Produto* ajustar_quantidade(Produto *L, const char *codigo, int delta_qtd); // O(n)
Produto* buscar(Produto *L, const char *codigo);                     // O(n)
void listar(Produto *L);                                             // O(n)
Produto* limpar(Produto *L);                                         // O(n)
void relatorio(Produto *L);                                          // O(n)

#endif
