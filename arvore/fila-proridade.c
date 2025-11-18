#include <stdio.h>
#include <stdlib.h>

typedef struct FP {
    int *v;
    int n, tam;
} FP;

FP *cria_fp(int tam) {
    FP *fp = malloc(sizeof(FP));
    fp->v = malloc(tam * sizeof(int));
    fp->n = 0;
    fp->tam = tam;
    return fp;
}

void sobe_no_heap(FP *fp) {
    int idx = fp->n - 1;
    int pai = (idx - 1) / 2;
    while (idx > 0 && fp->v[pai] < fp->v[idx]) {
        int tmp = fp->v[idx];
        fp->v[idx] = fp->v[pai];
        idx = pai;
        pai = (idx - 1) / 2;
    }
}

void insere(FP *fp, int x) {
    if (fp->n == fp->tam) {
        fp->v = realloc(fp->v, 2 * fp->tam * sizeof(int));
        fp->tam *= 2;
    }
    fp->v[fp->n] = x;
    fp->n++;
    sobe_no_heap(fp);
}

int extrai_maximo(FP *fp) {
    int maior = fp->v[0];
    troca(&fp->v[0], &fp->v[fp->n - 1]);
    fp->n--;
    desce_no_heap(fp, 0);
    return maior;
}

void desce_no_heap(FP *fp, int k) {
    int esq = 2 * k + 1;
    int dir = esq + 1;
    int maior_filho;
    if (esq < fp->n) {
        maior_filho = esq;
        if (dir < fp->n && fp->v[dir] > fp->v[esq])
            maior_filho = dir;
        if (fp->v[k] < fp->v[maior_filho]) {
            troca(&fp->v[k], fp->v[maior_filho]);
            desce_no_heap(fp, maior_filho);
        }
    }
}
