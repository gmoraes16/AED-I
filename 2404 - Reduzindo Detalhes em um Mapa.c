#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int u, v, peso;
} Aresta;

int compararArestas(const void* a, const void*b) {
	return ((Aresta*)a)->peso - ((Aresta*)b)->peso;
}

int busca(int pai[], int i) {
	if (pai[i] != i) {
		pai[i] = busca(pai, pai[i]);
	}
	return pai[i];
}

void unir(int pai[], int altura[], int x, int y) {
	int raizX = busca(pai, x);
	int raizY = busca(pai, y);

	if (raizX != raizY) {
		if(altura[raizX] < altura[raizY]) {
			pai[raizX] = raizY;
		} else if (altura[raizX] > altura[raizY]) {
			pai[raizY] = raizX;
		} else {
			pai[raizY] = raizX;
			altura[raizX]++;
		}
	}
}

int kruskal(Aresta arestas[], int R, int C) {
	qsort(arestas, C, sizeof(Aresta), compararArestas);

	int pai[R + 1], altura[R + 1];

	for ( int i = 1; i <= R; i++) {
		pai[i] = i;
		altura[i] = 0;
	}

	int custoTotal = 0, arestasUsadas = 0;

	for (int i = 0; i < C && arestasUsadas < R - 1; i++) {
		int u = arestas[i].u;
		int v = arestas[i].v;
		int peso = arestas[i].peso;

		if (busca(pai, u) != busca(pai, v)) {
			unir(pai, altura, u, v);
			custoTotal += peso;
			arestasUsadas++;
		}
	}

	return custoTotal;
}

int main() {

	int N, M, i;

	scanf("%d %d", &N, &M);

	Aresta arestas[M];

	for (i = 0; i < M; i++) {
		scanf("%d %d %d", &arestas[i].u, &arestas[i].v, &arestas[i].peso);
	}

	int custoTotal = kruskal(arestas, N, M);
	printf("%d\n", custoTotal);

	return 0;
}