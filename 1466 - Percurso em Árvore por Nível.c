#include <stdio.h>
#include <stdlib.h>

struct cel {
	int chave;
	struct cel *esq;
	struct cel *dir;
};

typedef struct cel no;
typedef no *arvore;
	
arvore Insere(arvore r, int chave) {
	if (r == NULL) {
		no *novo = malloc(sizeof(no));
		novo->chave = chave;
		novo->esq = novo->dir = NULL;
		return novo;
	}
	if (chave < r->chave) {
		r->esq = Insere(r->esq, chave);
	} else {
		r->dir = Insere(r->dir, chave);
	}
	return r;
}

void BFS (arvore raiz) {
	if (raiz == NULL) return;
	
	no* fila[500];
	int inicio = 0, fim = 0;
	
	fila[fim++] = raiz;
	int primeiro = 1;
	
	while (inicio < fim) {
		no* atual = fila[inicio++];
		
		if (!primeiro) {
			printf(" ");
		}
		printf("%d", atual->chave);
		primeiro = 0;
		
		if (atual->esq != NULL) {
			fila[fim++] = atual->esq;
		}
		if (atual->dir != NULL) {
			fila[fim++] = atual->dir;
		}
	}
}

int main() {
	int C, N;
	int i, caso, valor;
	scanf("%d", &C);
	
	for (caso = 1; caso <= C; caso++) {
		scanf("%d", &N);
		
		arvore raiz = NULL;
		
		for (i = 0; i < N; i++) {
			scanf("%d", &valor);
			raiz = Insere(raiz, valor);
		}
		
		printf("Case %d:\n", caso);
		
		BFS(raiz);
		printf("\n\n");
	}
	
	return 0;
}