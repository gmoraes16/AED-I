#include <stdio.h>
#include <string.h>

int contarPosicoes (const char* mensagem, const char* crib) {
	int n = strlen(mensagem);
	int m = strlen(crib);
	int i, j;
	int count = 0;
	
	for (i = 0; i <= n - m; i++) {
		int valido = 1;
		
		for (j = 0; j < m; j++) {
			if(mensagem[i + j] == crib[j]) {
				valido = 0;
				break;
			}
		}
		
		if (valido) {
			count++;
		}
	}

return count;

}

int main() {

	char mensagem[10001];
	char crib[10001];
	
	int resultado;
	
	scanf("%s", mensagem);
	scanf("%s", crib);
	
	resultado = contarPosicoes(mensagem, crib);
	
	printf("%d\n", resultado);
	
	return 0;	
}