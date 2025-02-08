#include <stdio.h>
#include <stdlib.h>

void lerFila(int fila[], int N) {
	for (int i = 0; i < N; i++) {
		scanf("%d", &fila[i]);
	}
}

void lerRemovidos(int rmv[], int M) {
	for (int i = 0; i < M; i++) {
		scanf("%d", &rmv[i]);
	}
}

int compare(const void *a, const void *b) {
	return (*(int *)a - *(int *)b);
}

int procuraRMV(int rmv[], int M, int valor) {
	return bsearch(&valor, rmv, M, sizeof(int), compare) != NULL;
}

void imprimeFila(int fila[], int N) {
	for (int i = 0; i < N; i++) {
		printf("%d", fila[i]);
		if (i < N - 1) {
			printf(" ");
		}
	}
	printf("\n");
}

int removerFila(int fila[], int *N, int rmv[], int M) {
	int x = 0;

	qsort(rmv, M, sizeof(int), compare);

	for (int i = 0; i < *N; i++) {
		if (!procuraRMV(rmv, M, fila[i])) {
			fila[x++] = fila[i];
		}
	}

	*N = x;
	return x;
}

int main() {
	int N, M;

	scanf("%d", &N);
	int *fila = (int *)malloc(N * sizeof(int));

	lerFila(fila, N);

	scanf("%d", &M);
	int *rmv = (int *)malloc(M * sizeof(int));

	lerRemovidos(rmv, M);

	removerFila(fila, &N, rmv, M);
	imprimeFila(fila, N);

	free(fila);
	free(rmv);

	return 0;
}