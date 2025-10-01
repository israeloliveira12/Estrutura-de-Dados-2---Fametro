#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

// Inicializa a pilha
void pilha_init(Pilha *p) {
    p->topo = NULL;
}

// Empilha um frame
bool push(Pilha *p, const char *func, int sp) {
    Frame *novo = (Frame*) malloc(sizeof(Frame));
    if (!novo) return false;
    strncpy(novo->func, func, sizeof(novo->func)-1);
    novo->func[sizeof(novo->func)-1] = '\0';
    novo->sp = sp;
    novo->baixo = p->topo;
    p->topo = novo;
    return true;
}

// Desempilha um frame
bool pop(Pilha *p, Frame *out) {
    if (!p->topo) return false;
    Frame *tmp = p->topo;
    *out = *tmp;
    p->topo = tmp->baixo;
    free(tmp);
    return true;
}

// Mostra o topo sem remover
bool peek(Pilha *p, Frame *out) {
    if (!p->topo) return false;
    *out = *(p->topo);
    return true;
}

// Verifica se a pilha está vazia
bool vazia(Pilha *p) {
    return p->topo == NULL;
}

// Limpa toda a pilha
void limpar(Pilha *p) {
    Frame *tmp;
    while (p->topo) {
        tmp = p->topo;
        p->topo = p->topo->baixo;
        free(tmp);
    }
}
