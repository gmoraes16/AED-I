#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INF INT_MAX

typedef struct {
	char nome[20];
	int indice;
} mapeamento;

mapeamento mapa [4000];
int total_vertices = 0;
int grafo[4000][4000];

int criar_indice(char *nome) {
	for (int i = 0; i < total_vertices; i++) {
		if(strcmp(mapa[i].nome, nome) == 0) {
			return mapa[i].indice;
		}
	}
	strcpy(mapa[total_vertices].nome, nome);
	mapa[total_vertices].indice = total_vertices;
	return total_vertices++;
}

void dijkstra (int n, int inicio, int distancia[]) {
	int visitado[n], i;

	for (i = 0; i < n; i++) {
		distancia[i] = INF;
		visitado[i] = 0;
	}
	distancia[inicio] = 0;
	for (i = 0; i < n - 1; i++) {
		int minDist = INF, u = -1;
		for (int j = 0; j < n; j++) {
			if (!visitado[j] && distancia[j] < minDist) {
				minDist = distancia[j];
				u = j;
			}
		}
		if (u == -1) break;
		visitado[u] = 1;

		for (int v = 0; v < n; v++) {
			if (!visitado[v] && grafo[u][v] != INF && distancia[u] < distancia[v]) {
				distancia[v] = distancia[u] + grafo[u][v];
			}
		}
	}
}

int main() {

	int vertices, arestas;

	scanf("%d %d", &vertices, &arestas);

	for (int i = 0; i < vertices; i++) {
		for (int j = 0; j < vertices; j++) {
			grafo[i][j] = (i == j) ? 0 : INF;
		}
	}

	char ponto1[20], ponto2[20];

	for (int i = 0; i < arestas; i++) {
		scanf("%s %s", ponto1, ponto2);

		int u = criar_indice(ponto1);
		int v = criar_indice(ponto2);

		grafo[u][v] = 1;
		grafo[v][u] = 1;
	}

	int inicio = criar_indice("Entrada");
	int queijo = criar_indice("*");
	int saida = criar_indice("Saida");


	int dist1[vertices], dist2[vertices];

	dijkstra(total_vertices, inicio, dist1);
	dijkstra(total_vertices, queijo, dist2);

	int resultado = dist1[queijo] + dist2[saida];

	printf("%d\n", resultado);

	return 0;
}