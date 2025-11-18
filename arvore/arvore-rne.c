#include <stdio.h>
#include <stdlib.h>

enum cor { VERM, PRETO };

typedef struct celula {
    int dado;
    enum cor cor;
    struct celula *esq, *dir;
} celula;

int ehVerm(celula *a) {
    if (a->cor == VERM)
        return 1;
    return 0;
}

int ehPreto(celula *a) {
    if (a->cor == PRETO)
        return 1;
    return 0;
}

celula *rotacao_esquerda(celula *a) {
    celula *b = a->dir;
    celula *beta = b->esq;
    b->esq = a;
    a->dir = beta;
    b->cor = a->cor;
    a->cor = VERM;
    return b;
}

celula *rotacao_direita(celula *a) {
    celula *b = a->esq;
    celula *beta = b->dir;
    b->dir = a;
    a->esq = beta;
    b->cor = a->cor;
    a->cor = VERM;
    return b;
}

void subida_cor(celula *a) {
    a->cor = VERM;
    a->esq->cor = a->dir->cor = PRETO;
}

celula *insere(celula *raiz, int x) {
    if (raiz != NULL) {
        if (x < raiz->dado)
            raiz->esq = insere(raiz->esq, x);
        if (x > raiz->dado)
            raiz->dir = insere(raiz->dir, x);

        if (ehPreto(raiz->esq) && ehVerm(raiz->dir))
            raiz = rotacao_esquerda(raiz);
        if (ehVerm(raiz->esq) && ehVerm(raiz->esq->esq))
            raiz = rotacao_direita(raiz);
        if (ehVerm(raiz->esq) && ehVerm(raiz->dir))
            subida_cor(raiz);
        return raiz;
    } else {
        celula *novo = malloc(sizeof(celula));
        novo->dado = x;
        novo->cor = VERM;
        novo->esq = novo->dir = NULL;
        return novo;
    }
}