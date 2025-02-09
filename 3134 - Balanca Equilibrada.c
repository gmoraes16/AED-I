#include <stdio.h>

int equilibra(float pesos[4]) {
	int i, j;
	float soma_esq, soma_dir;

	for(i = 0; i < 16; i++) {
		soma_esq = 0;
		soma_dir = 0;

		for(j = 0; j < 4; j++) {
			if((i >> j) & 1) {
				soma_esq += pesos[j];
			} else {
				soma_dir += pesos[j];
			}
		}

		if (fabs(soma_esq - soma_dir) < 0.001) {
			return 1;
		}
	}

	return 0;
}

int main() {
	int i;
	float pesos[4];

	for (i = 0; i < 4; i++) {
		scanf("%f", &pesos[i]);
	}

	if(equilibra(pesos)) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}

	return 0;
}