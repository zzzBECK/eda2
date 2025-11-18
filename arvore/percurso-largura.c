#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    int dado;
    struct Celula *esq, *dir;
} Celula;

typedef struct No {
    Celula *celula;
    struct No *prox;
} No;

typedef struct Pilha {
    No *topo;
} Pilha;

Celula *cria_arvore(int x) {
    Celula *raiz = malloc(sizeof(Celula));
    raiz->esq = NULL;
    raiz->dir = NULL;
    raiz->dado = x;
    return raiz;
}

Pilha *criar_pilha() {
    Pilha *pilha = malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

int pilha_vazia(Pilha *pilha) {
    return pilha->topo == NULL;
}

void empilha(Pilha *pilha, Celula *celula) {
    No *novo = malloc(sizeof(No));
    novo->celula = celula;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

Celula *desempilha(Pilha *pilha) {
    if (pilha_vazia(pilha)) {
        return NULL;
    }

    No *temp = pilha->topo;
    Celula *celula = temp->celula;
    pilha->topo = temp->prox;
    free(temp);
    return celula;
}

void libera_pilha(Pilha *pilha) {
    while (!pilha_vazia(pilha)) {
        desempilha(pilha);
    }
    free(pilha);
}

void preordem_recursiva(Celula *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado);
        preordem_recursiva(raiz->esq);
        preordem_recursiva(raiz->dir);
    }
}

void preordem_pilha(Celula *raiz) {
    Pilha *pilha = criar_pilha();
    empilha(pilha, raiz);
    while (!pilha_vazia(pilha)) {
        raiz = desempilha(pilha);
        if (raiz->dir != NULL)
            empilha(pilha, raiz->dir);
        if (raiz->esq != NULL)
            empilha(pilha, raiz->esq);

        printf("%d ", raiz->dado);
    }

    libera_pilha(pilha);
}

void posordem_recursiva(Celula *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado);
        posordem_recursiva(raiz->dir);
        posordem_recursiva(raiz->esq);
    }
}

int altura(Celula *raiz) {
    if (raiz == NULL)
        return -1;
    int he = altura(raiz->esq);
    int hd = altura(raiz->dir);
    if (he > hd)
        return he + 1;
    else
        return hd + 1;
}

int main() {
    Celula *raiz = cria_arvore(10);
    raiz->esq = cria_arvore(5);
    raiz->dir = cria_arvore(20);
    raiz->esq->esq = cria_arvore(3);
    raiz->esq->dir = cria_arvore(7);
    raiz->dir->esq = cria_arvore(15);
    raiz->dir->dir = cria_arvore(25);
    raiz->esq->esq->esq = cria_arvore(20);

    printf("Percurso pre-ordem recursivo:\n");
    preordem_recursiva(raiz);
    printf("\n");

    printf("Percurso pre-ordem com pilha:\n");
    preordem_pilha(raiz);
    printf("\n");

    printf("Percurso pos-ordem recursivo:\n");
    posordem_recursiva(raiz);
    printf("\n");

    printf("Altura da arvore:\n");
    printf("%d\n", altura(raiz));

    return 0;
}