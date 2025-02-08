#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
	struct cel *esq;
	struct cel *dir;
	char chave;
} no;

typedef no *arvore;

arvore construirArvore(char *prefixo, char *infixo, int n) {
	if (n <= 0) return NULL;
	
	char raizChar = prefixo[0];
	
	arvore raiz = (arvore)malloc(sizeof(no));
	raiz->chave = raizChar;
	raiz->esq = raiz->dir = NULL;
	
	int posfixo;
	for (posfixo = 0; posfixo < n; posfixo++) {
		if(infixo[posfixo] == raizChar) break;
	}
	
	raiz->esq = construirArvore(prefixo + 1, infixo, posfixo);
	raiz->dir = construirArvore(prefixo + posfixo + 1, infixo + posfixo + 1, n - posfixo - 1);
	
	return raiz;
}

void Posfixo (arvore r) {
	if (r != NULL) {
		Posfixo(r->esq);
		Posfixo(r->dir);
		printf("%c", r->chave);
	}
}

void liberarArvore(arvore r) {
	if (r != NULL) {
		liberarArvore(r->esq);
		liberarArvore(r->dir);
		free(r);
	}
}

int main() {
	int C;

	scanf("%d", &C);

	for (int i = 0; i < C; i++) {
		int N;
		char S1[53], S2[53];
		scanf("%d %s %s", &N, S1, S2);
		
		arvore raiz = construirArvore(S1, S2, N);
		Posfixo(raiz);
		printf("\n");
		
		liberarArvore(raiz);
	}
	
	return 0;
}