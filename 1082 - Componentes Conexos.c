#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
	char vertice;
	struct celula *prox;
}celula;

celula* criarCel(char vertice) {
	celula* nova = (celula*)malloc(sizeof(celula));
	nova->vertice = vertice;
	nova->prox = NULL;
	return nova;
}

void AddAresta(celula* adj[], char u, char v) {
	celula* celU = criarCel(v);
	celU->prox = adj[u - 'a'];
	adj[u - 'a'] = celU;
	
	celula* celV = criarCel(u);
	celV->prox = adj[v - 'a'];
	adj[v - 'a'] = celV;
}

void DFS(celula* adj[], int visitado[], char vertice, char* componente) {
	visitado[vertice - 'a'] = 1;
	strncat(componente, &vertice, 1);
	
	celula* atual = adj[vertice - 'a'];
	while (atual != NULL) {
		if(!visitado[atual->vertice - 'a']) {
			DFS(adj, visitado, atual->vertice, componente);
		}
		atual = atual->prox;
	}
}

int cmpChar(const void* a, const void* b) { // comparar dois caracteres
	return(*(char*)a - *(char*)b);
}

int main() {
	int N, i, j, k, t;
	scanf("%d", &N);
	
	for (i = 1; i <= N; i++) {
		int V, E;
		scanf("%d %d", &V, &E);
		
		celula* adj[26] = { NULL };
		int visitado[26] = { 0 };
		
		for (j = 0; j < E; j++) {
			char u, v;
			scanf(" %c %c", &u, &v);
			AddAresta(adj, u, v);
		}
	
	int count = 0;
	printf("Case #%d:\n", i);
	
	for(j = 0; j < V; j++) {
		char vertice = 'a' + j;
		if (!visitado[vertice - 'a']) {
			char componente[100] = "";
			DFS(adj, visitado, vertice, componente);
			
			int len = strlen(componente);
			qsort(componente, len, sizeof(char), cmpChar);
			
			printf("%c", componente[0]);
			
			for (k = 1; k < len; k++) {
				printf(",%c", componente[k]);
			}
			
			printf(",\n");
			
			count++;
		}
	}
	
	printf("%d connected components\n\n", count);
	
	for (j = 0; j <26; j++) {
		celula* atual = adj[j];
		while(atual) {
			celula* temp = atual;
			atual = atual->prox;
			free(temp);
		}
	}
}

return 0;

}
