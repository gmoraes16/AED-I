#include <stdio.h>
#include <stdlib.h>

int MDC(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return abs(a);
}

int main() {
	int N, F1, F2, i, resultado;
	
	scanf("%d", &N);
	
	for (i = 0; i < N; i++) {
		scanf("%d %d", &F1, &F2);
		
		resultado = MDC(F1, F2);
		
		printf("%d\n", resultado);
	}
    return 0;
}