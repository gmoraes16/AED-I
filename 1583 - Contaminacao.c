#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x, y;
} posicao;

int main() {
	int N, M;

	while (scanf("%d %d", &N, &M) && N != 0 && M != 0) {
		char mapa[N][M];

		posicao fila [N * M];

		int inicio = 0, fim = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf(" %c", &mapa[i][j]);
				if(mapa[i][j] == 'T') {
					fila[fim].x = i;
					fila[fim].y = j;
					fim++;
				}
			}
		}

		while (inicio < fim) {
			posicao atual = fila[inicio];
			inicio++;

			int dx[] = {-1, 1, 0, 0};
			int dy[] = {0, 0, -1, 1};

			for (int d = 0; d < 4; d++) {
				int nx = atual.x + dx[d];
				int ny = atual.y + dy[d];

				if (nx >= 0 && nx < N && ny >= 0 && ny < M && mapa[nx][ny] == 'A') {
					mapa[nx][ny] = 'T';
					fila[fim].x = nx;
					fila[fim].y = ny;
					fim++;
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				printf("%c", mapa[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}