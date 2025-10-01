#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

// Inicializa fila
void inicializar(Fila *f) {
    f->ini = f->fim = NULL;
}

// Enfileira cliente
void enfileirar(Fila *f, Cliente c) {
    Cliente *novo = (Cliente*) malloc(sizeof(Cliente));
    if (!novo) return;
    *novo = c;
    novo->prox = NULL;

    if (!f->fim) {
        f->ini = f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

// Desenfileira cliente
bool desenfileirar(Fila *f, Cliente *out) {
    if (!f->ini) return false;

    Cliente *tmp = f->ini;
    *out = *tmp;
    f->ini = f->ini->prox;
    if (!f->ini) f->fim = NULL;
    free(tmp);
    return true;
}

// Verifica se a fila está vazia
bool vazia(Fila *f) {
    return f->ini == NULL;
}

// Limpa fila
void limpar(Fila *f) {
    Cliente *tmp;
    while (f->ini) {
        tmp = f->ini;
        f->ini = f->ini->prox;
        free(tmp);
    }
    f->fim = NULL;
}
