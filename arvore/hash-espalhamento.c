#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int ch;
    int dado;
    struct no *prox;
} no;

int hash(int ch, int m) {
    return ch % m;
}
