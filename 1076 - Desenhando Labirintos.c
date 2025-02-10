#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u;
    int v;
} Aresta;

Aresta criarAresta(int u, int v) {
    Aresta aresta;
    if (u <= v) {
        aresta.u = u;
        aresta.v = v;
    } else {
        aresta.u = v;
        aresta.v = u;
    }
    return aresta;
}

int compararArestas(const void *a, const void *b) {
    Aresta *arestaA = (Aresta *)a;
    Aresta *arestaB = (Aresta *)b;
    if (arestaA->u != arestaB->u) {
        return arestaA->u - arestaB->u;
    } else {
        return arestaA->v - arestaB->v;
    }
}

int contarArestaUnica(Aresta *arestas, int A) {
    if (A == 0) return 0;
    qsort(arestas, A, sizeof(Aresta), compararArestas);
    int unico = 1;
    for (int i = 1; i < A; i++) {
        if (arestas[i].u != arestas[i-1].u || arestas[i].v != arestas[i-1].v) {
            unico++;
        }
    }
    return unico;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, V, A;
        scanf("%d", &N);
        scanf("%d %d", &V, &A);

        Aresta *arestas = (Aresta *)malloc(A * sizeof(Aresta));
        for (int i = 0; i < A; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            arestas[i] = criarAresta(u, v);
        }

        int unicoA = contarArestaUnica(arestas, A);
        printf("%d\n", 2 * unicoA);

        free(arestas);
    }

    return 0;
}