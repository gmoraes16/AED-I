#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int u, v, peso;
} Aresta;

int compararAresta(const void *a, const void *b) {
    const Aresta *arestaA = (const Aresta *)a;
    const Aresta *arestaB = (const Aresta *)b;
    return arestaA->peso - arestaB->peso;
}

int encontra(int pai[], int i) {
    if (pai[i] != i) {
        pai[i] = encontra(pai, pai[i]);
    }
    return pai[i];
}

void unir(int pai[], int altura[], int raizX, int raizY) {
    if (altura[raizX] < altura[raizY]) {
        pai[raizX] = raizY;
    } else if (altura[raizX] > altura[raizY]) {
        pai[raizY] = raizX;
    } else {
        pai[raizY] = raizX;
        altura[raizX]++;
    }
}

void uniao(int pai[], int altura[], int x, int y) {
    int raizX = encontra(pai, x);
    int raizY = encontra(pai, y);

    if (raizX != raizY) {
        unir(pai, altura, raizX, raizY);
    }
}

int main() {
    while (1) {
        int m, n, i;
        scanf("%d %d", &m, &n);

        if (m == 0 && n == 0) {
            break;
        }

        Aresta arestas[n];
        int custoTotal = 0;

        for (i = 0; i < n; i++) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            arestas[i] = (Aresta){x, y, z};
            custoTotal += z;
        }

        qsort(arestas, n, sizeof(Aresta), compararAresta);

        int pai[m], altura[m];
        for (i = 0; i < m; i++) {
            pai[i] = i;
            altura[i] = 0;
        }

        int custoArvore = 0;
        for (i = 0; i < n; i++) {
            int u = arestas[i].u;
            int v = arestas[i].v;
            int peso = arestas[i].peso;

            if (encontra(pai, u) != encontra(pai, v)) {
                uniao(pai, altura, u, v);
                custoArvore += peso;
            }
        }

        printf("%d\n", custoTotal - custoArvore);
    }

    return 0;
}