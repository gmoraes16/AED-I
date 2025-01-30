#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	
	int *v = malloc(N * sizeof(int));
	for (i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}
	
	int *c = malloc(M * sizeof(int));
	for (i = 0; i < N; i++) {
		scanf("%d", &c[i]);
	}
	
	int *tempo_funcionario = calloc(N, sizeof(int));
	
	for (j = 0; j < M; j++) {
		int min_tempo = tempo_funcionario[0];
		int funcionario = 0;
		
		for (i = 1; i < N; i++) {
			if (tempo_funcionario[i] < min_tempo) {
				min_tempo = tempo_funcionario[i];
				funcionario = 1;
			}
		}
		
		tempo_funcionario[funcionario] += v[funcionario] * c[j];
	}
	
	int max_tempo = 0;
	for(i = 0; i < N; i++) {
		if (tempo_funcionario[i] > max_tempo) {
			max_tempo = tempo_funcionario[i];
		}
	}
	
	printf("%d\n", max_tempo);
	
	free(v);
	free(c);
	free(tempo_funcionario);
	
	return 0;
}