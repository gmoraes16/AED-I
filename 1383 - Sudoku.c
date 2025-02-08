#include <stdio.h>

int main() {

	int sudoku[9][9], i, j, num, valido, c, l, n, k;
	int contar[10];

	scanf("%d", &n);

	for (k = 1; k <= n; k++) {
		valido = 1;

		for (i = 0; i < 9; i++) {
			for (j = 0; j < 9; j++) {
				scanf("%d", &sudoku[i][j]);
			}
		}

		for (i = 0; i < 9; i++) {
			for (num = 1; num <= 9; num++) {
				contar[num] = 0;
			}

			for (j = 0; j < 9; j++) {
				if (sudoku[i][j] >= 1 && sudoku[i][j] <= 9) {
					contar[sudoku[i][j]]++;
				}
			}

			for (num = 1; num <= 9; num++) {
				if (contar[num] != 1) {
					valido = 0;
					break;
				}
			}

			if (!valido) {
				break;
			}
		}

		for (j = 0; j < 9; j++) {
			for (num = 1; num <= 9; num++) {
				contar[num] = 0;
			}

			for (i = 0; i < 9; i++) {
				if (sudoku[i][j] >= 1 && sudoku[i][j] <= 9) {
					contar[sudoku[i][j]]++;
				}
			}

			for (num = 1; num <= 9; num++) {
				if (contar[num] != 1) {
					valido = 0;
					break;
				}
			}

			if (!valido) {
				break;
			}
		}

		if (valido) {
			for (i = 0; i < 9; i += 3) {
				for (j = 0; j < 9; j += 3) {
					for (num = 1; num <= 9; num++) {
						contar[num] = 0;
					}

					for (c = 0; c < 3; c++) {
						for (l = 0; l < 3; l++) {
							if (sudoku[i + c][j + l] >= 1 && sudoku[i + c][j + l] <= 9) {
								contar[sudoku[i + c][j + l]]++;
							}
						}
					}
					for (num = 1; num <= 9; num++) {
						if (contar[num] != 1) {
							valido = 0;
							break;
						}
					}

					if (!valido) {
						break;
					}
				}
				if (!valido) {
					break;
				}
			}
		}

		printf("Instancia %d\n", k);

		if (valido) {
			printf("SIM\n");
		} else {
			printf("NAO\n");
		}
		printf("\n");
	}
	return 0;
}