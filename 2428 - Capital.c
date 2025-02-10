#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
	return (*(int *)a - *(int *)b);
}

char verificaDivisao(int A1, int A2, int A3, int A4) {

	int areas[4] = {A1, A2, A3, A4};

	qsort(areas, 4, sizeof(int), comparar);
	if(areas[0] * areas[3] == areas[1] * areas[2]) {
		return 'S';
	} else {
		return 'N';
	}
}

int main() {
	int A1, A2, A3, A4;
	
	scanf("%d %d %d %d", &A1, &A2, &A3, &A4);
	
	char resultado = verificaDivisao(A1, A2, A3, A4);
	
	printf("%c\n", resultado);
	
	return 0;
}