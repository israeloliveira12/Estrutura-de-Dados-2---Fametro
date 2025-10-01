#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

// Inserir no início
Produto* inserir_inicio(Produto *L, Produto p) {
    Produto *novo = (Produto*) malloc(sizeof(Produto));
    if (!novo) return L; // falha alocação
    *novo = p;
    novo->prox = L;
    return novo;
}

// Inserir ordenado por código (atualiza qtd e preco se existir)
Produto* inserir_ordenado_por_codigo(Produto *L, Produto p) {
    Produto *atual = L, *ant = NULL;

    while (atual && strcmp(atual->codigo, p.codigo) < 0) {
        ant = atual;
        atual = atual->prox;
    }

    if (atual && strcmp(atual->codigo, p.codigo) == 0) {
        atual->qtd += p.qtd;
        atual->preco = p.preco;
        return L;
    }

    Produto *novo = (Produto*) malloc(sizeof(Produto));
    if (!novo) return L;
    *novo = p;
    novo->prox = atual;

    if (!ant) return novo; // novo no início
    ant->prox = novo;
    return L;
}

// Remover por código
Produto* remover_por_codigo(Produto *L, const char *codigo) {
    Produto *atual = L, *ant = NULL;

    while (atual && strcmp(atual->codigo, codigo) != 0) {
        ant = atual;
        atual = atual->prox;
    }

    if (!atual) return L; // não encontrado

    if (!ant) L = atual->prox; // remover início
    else ant->prox = atual->prox;

    free(atual);
    return L;
}

// Ajustar quantidade
Produto* ajustar_quantidade(Produto *L, const char *codigo, int delta_qtd) {
    Produto *p = L;
    while (p && strcmp(p->codigo, codigo) != 0) p = p->prox;
    if (!p) return L;

    if (p->qtd + delta_qtd >= 0) p->qtd += delta_qtd;
    else printf("Quantidade negativa não permitida!\n");

    return L;
}

// Buscar produto
Produto* buscar(Produto *L, const char *codigo) {
    Produto *p = L;
    while (p) {
        if (strcmp(p->codigo, codigo) == 0) return p;
        p = p->prox;
    }
    return NULL;
}

// Listar produtos
void listar(Produto *L) {
    Produto *p = L;
    printf("Codigo | Nome | Quantidade | Preco\n");
    while (p) {
        printf("%s | %s | %d | %.2f\n", p->codigo, p->nome, p->qtd, p->preco);
        p = p->prox;
    }
}

// Limpar lista
Produto* limpar(Produto *L) {
    Produto *p;
    while (L) {
        p = L;
        L = L->prox;
        free(p);
    }
    return NULL;
}

// Relatório
void relatorio(Produto *L) {
    if (!L) {
        printf("Estoque vazio.\n");
        return;
    }

    int total_itens = 0;
    float valor_total = 0, maior_valor = 0;
    Produto *p_maior = NULL;
    Produto *p = L;

    while (p) {
        total_itens++;
        float valor = p->qtd * p->preco;
        valor_total += valor;
        if (valor > maior_valor) {
            maior_valor = valor;
            p_maior = p;
        }
        p = p->prox;
    }

    printf("Total de itens distintos: %d\n", total_itens);
    printf("Valor total do estoque: %.2f\n", valor_total);
    if (p_maior)
        printf("Produto com maior valor imobilizado: %s (%.2f)\n", p_maior->nome, maior_valor);
}
