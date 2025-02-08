#include <stdio.h>
#include <stdbool.h>

int N;
char matriz[1000][1000];
int casa[1000];

void DFS(int pessoa, int casa_atual){
	casa[pessoa] = casa_atual;
	for(int i = 0; i < N; i++) {
		if (matriz[pessoa][i] == 'S' && casa[i] == -1) {
			DFS(i, casa_atual);
		}
	}
}

bool verificar_inconsistencia() {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if (matriz[i][j] == 'S' && casa[i] != casa[j]) {
			return true;
			}
		if (matriz[i][j] == 'D' && casa[i] == casa[j]) {
			return true;
			}
		}
	}
	return false;
}
 
int main() {
	int i, j;
    
    scanf("%d", &N);
    
    for (i = 0; i < N; i++) {
    	scanf("%s", matriz[i]);
    }
    
    for (i = 0; i < N; i++) {
    	casa[i] = -1;
	}
	
	int casa_atual = 0;
	for (i = 0; i < N; i++) {
		if(casa[i] == -1) {
			DFS(i, casa_atual);
			casa_atual++;
		}
	}
	
	if(verificar_inconsistencia()) {
		printf("-1\n");
		return 0;
	}
	
	int tamanho_casas[1000] = {0};
	for (i = 0; i < N; i++) {
		tamanho_casas[casa[i]]++;
	}
	
	int K = 0;
	for (i = 0; i < N; i++) {
		if (tamanho_casas[i] > 0) {
			K++;
		}
	}
	
	for (i = 0; i < casa_atual - 1; i++) {
		for (j = i + 1; j < casa_atual; j++) {
			if (tamanho_casas[i] < tamanho_casas[j]) {
				int temp = tamanho_casas[i];
				tamanho_casas[i] = tamanho_casas[j];
				tamanho_casas[j] = temp;
			}
		}
	}
	
	printf("%d\n", K);
	for (int i = 0; i < K; i++) {
		if (i > 0) printf(" ");
		printf("%d", tamanho_casas[i]);
	}
	printf("\n");
	
    return 0;
}