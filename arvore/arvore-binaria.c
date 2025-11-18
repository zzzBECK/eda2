#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    int dado;
    struct Celula *esq, *dir, *pai;
} Celula;

Celula *cria_arvore(int x) {
    Celula *raiz = malloc(sizeof(Celula));
    raiz->dir = raiz->esq = NULL;
    raiz->dado = x;
    return raiz;
}

Celula *busca(Celula *raiz, int x) {
    if (raiz == NULL)
        return raiz;

    if (raiz->dado > x)
        return busca(raiz->esq, x);
    if (raiz->dado < x)
        return busca(raiz->dir, x);
}

Celula *maximo(Celula *raiz) {
    if (raiz == NULL)
        return raiz;

    while (raiz->dir != NULL) {
        raiz = raiz->dir;
    }
    return raiz;
}

Celula *minimo(Celula *raiz) {
    if (raiz == NULL)
        return raiz;

    while (raiz->esq != NULL) {
        raiz = raiz->esq;
    }
    return raiz;
}

Celula *ancestral_a_esq(Celula *no) {
    if (no->pai == NULL || no->pai->dir == no) {
        return no->pai;
    }
    return ancestral_a_esq(no->pai);
}

Celula *antecessor(Celula *no) {
    if (no->esq != NULL)
        return maximo(no->esq);
    else
        return ancestral_a_esq(no);
}

Celula *insere_abb(Celula *raiz, int ch) {
    if (raiz != NULL) {
        if (ch < raiz->dado)
            raiz->esq = insere_abb(raiz->esq, ch);
        else if (ch > raiz->dado)
            raiz->dir = insere_abb(raiz->dir, ch);
    } else {
        Celula *novo = cria_arvore(ch);
        return novo;
    }
}

void remover_antecessor(Celula *raiz) {
    Celula *pai = raiz;
    Celula *max = raiz->esq;
    while (max->dir != NULL) {
        pai = max;
        max = max->dir;
    }
    if (max == pai->esq)
        pai->esq = max->esq;
    else
        pai->dir = max->esq;
    free(max);
}

Celula *remover_abb(Celula *raiz, int x) {
    if (raiz == NULL)
        return raiz;

    if (x < raiz->dado)
        raiz->esq = remover_abb(raiz->esq, x);
    if (x > raiz->dado)
        raiz->dir = remover_abb(raiz->dir, x);

    if (raiz->esq == NULL)
        return raiz->dir;
    else if (raiz->dir == NULL)
        return raiz->esq;
    else
        remover_antecessor(raiz);
}