#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct celula {
	int valor;
	struct celula *seg;
}celula;

celula *grafo[50001];
int peso[50001];
int vertices[50001];

void adicionarAresta(int A, int B) {
	celula *nova = (celula *)malloc(sizeof(celula));
	nova->valor = B;
	nova->seg = grafo[A];
	grafo[A] = nova;
	
	nova = (celula *)malloc(sizeof(celula));
	nova->valor = A;
	nova->seg = grafo[B];
	grafo[B] = nova;
	
	peso[A]++;
	peso[B]++;
}

int compararVertices (const void *a, const void *b ) {
	int pesoA = peso[*(int *)a];
	int pesoB = peso[*(int *)b];
	return pesoB - pesoA;
}

bool verificarClique (int *vertices, int k) {
	for (int i = 0; i < k; i++) {
		for (int j = i + 1; j < k; j++) {
			int u = vertices[i];
			int v = vertices[j];
			bool conectado = false;
			for (celula *vizinho = grafo[u]; vizinho != NULL; vizinho = vizinho->seg) {
				if (vizinho->valor == v) {
					conectado = true;
					break;
				}
			}
			if(!conectado) {
				return false;
			}
		}
	}
	return true;
}

bool verificarIndependentSet (int *vertices, int inicio, int fim) {
	for (int i = inicio; i < fim; i++) {
		for (int j = i + 1; j < fim; j++) {
			int u = vertices[i];
			int v = vertices[j];
			for (celula *vizinho = grafo[u]; vizinho != NULL; vizinho = vizinho->seg) {
				if (vizinho->valor == v) {
					return false;
				}
			}
		}
	}
	return true;
}

bool verificarGrafoSplit(int H) {
	for (int i = 1; i <= H; i++) {
		vertices[ i - 1] = i;
	}
	qsort(vertices, H, sizeof(int), compararVertices);
	
	int maiorClique = 0;
	for (int i = 0; i < H; i++) {
		if (peso[vertices[i]] >= i) {
			maiorClique = i + 1;
		} else {
			break;
		}
	}
	
	if (!verificarClique(vertices, maiorClique)) {
		return false;
	}
	
	if(!verificarIndependentSet(vertices, maiorClique, H)) {
		return false;
	}

    return true;
}

void freeGrafo(int H) {
	for (int i = 1; i <= H; i++) {
		celula *atual = grafo[i];
		while (atual) {
			celula *temp = atual;
			atual = atual->seg;
			free(temp);
		}
		grafo[i] = NULL;
	}
}

int main() {
	int H, R;
	while (scanf("%d %d", &H, &R) && (H != 0 || R != 0)) {
		for (int i = 1; i <= H; i++) {
			grafo[i] = NULL;
			peso[i] = 0;
		}
		
		for (int i = 0; i < R; i++) {
			int A, B;
			scanf("%d %d", &A, &B);
			adicionarAresta(A, B);
		}
		printf("%c\n", verificarGrafoSplit(H) ? 'Y' : 'N');
		freeGrafo(H);
	}
	return 0;
}