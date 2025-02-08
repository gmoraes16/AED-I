#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int adj[20][20]; 
int lbl[20]; 

int pathR(int v, int profundidade) {
    int output = 0;
    lbl[v] = 1;

    for (int w = 0; w < 20; w++) {
        if (adj[v][w] == 1) {
            for (int i = 0; i < profundidade; i++) {
                printf("  ");
            }
            if (lbl[w] == -1) { 
                printf("%d-%d pathR(G,%d)\n", v, w, w);
                output = 1; 
                int sub_output = pathR(w, profundidade + 1);
                output = output || sub_output;
            } else { 
                printf("%d-%d\n", v, w);
                output = 1; 
            }
        }
    }
    return output;
}

int main() {
    int N, V, E;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &V, &E);
        printf("Caso %d:\n", i + 1);

        memset(adj, 0, sizeof(adj));
        memset(lbl, -1, sizeof(lbl));

        for (int j = 0; j < E; j++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u][v] = 1;
        }

        int first = 1;
        int previousHadOutput = 0;
        for (int u = 0; u < V; u++) {
            if (lbl[u] == -1) {
                if (!first && previousHadOutput) {
                    printf("\n");
                }
                first = 0;
                int currentOutput = pathR(u, 1);
                previousHadOutput = currentOutput;
            }
        }
        printf("\n");
    }

    return 0;
}