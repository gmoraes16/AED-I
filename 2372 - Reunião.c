#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

void dijkstra(int n, int grafo[n][n], int inicio, int distancia[n]) {
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
			if (!visitado[v] && grafo[u][v] != INF && distancia[u] != INF && distancia[u] + grafo[u][v] < distancia[v]) {
				distancia[v] = distancia[u] + grafo[u][v];
			}
		}
	}
}

int main() {
	int N, M, i, j;

	scanf("%d %d", &N, &M);

	int grafo[N][N];

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			grafo[i][j] = INF;
		}
	}
	for (i = 0; i < M; i++) {
		int U, V, W;
		scanf("%d %d %d", &U, &V, &W);

		if (W < grafo[U][V]) {
			grafo[U][V] = W;
			grafo[V][U] = W;
		}
	}

	int menorMaxDist = INF;

	for (i = 0; i < N; i++) {
		int distancia[N];
		dijkstra(N, grafo, i, distancia);

		int maxDist = 0;
		for (j = 0; j < N; j++) {
			if (distancia[j] > maxDist) {
				maxDist = distancia[j];
			}
		}

		if (maxDist < menorMaxDist) {
			menorMaxDist = maxDist;
		}
	}

	printf("%d\n", menorMaxDist);

	return 0;
}