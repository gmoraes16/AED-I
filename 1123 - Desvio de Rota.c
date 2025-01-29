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
    int N, M, C, K, i, j;
    
    while (1) {
        scanf("%d %d %d %d", &N, &M, &C, &K);
        if (N == 0 && M == 0 && C == 0 && K == 0) break;
        
        int grafo[N][N];

        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                grafo[i][j] = INF;
            }
        }

        for (i = 0; i < M; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            
            if (u < C && v < C) {  
                if (u == v - 1) {
                    grafo[u][v] = w;
                } else if (v == u - 1) {
                    grafo[v][u] = w;
                }
            } else {  
                grafo[u][v] = w;
                grafo[v][u] = w;
            }
        }
        
        for (i = 0; i < C - 1; i++) {
            for (j = 0; j < N; j++) {
                if (j != i + 1) {
                    grafo[i][j] = INF;
                }
            }
        }
        
        int distancia[N];
        dijkstra(N, grafo, K, distancia);
        
        if (distancia[C - 1] == INF) {
            printf("-1\n");
        } else {
            printf("%d\n", distancia[C - 1]);
        }
    }
        
    return 0;
}