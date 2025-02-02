#include <stdio.h>

long long int fatorial (int n) {
	long long int fat = 1;
	for (int i = 2; i <=n; i++) {
		fat *= i;
	}
	return fat;
}

int main() {
	int N, M;
	long long int soma;
	
	while (scanf("%d %d", &N, &M) != EOF) {
		soma = fatorial(N) + fatorial(M);
		printf("%lld\n", soma);
	}
	
	return 0;
}