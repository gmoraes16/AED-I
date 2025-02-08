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

void Prefixo (arvore r) {
	if (r != NULL) {
		printf("%d", r->chave);
		if (r->esq != NULL) printf(" ");
		Prefixo(r->esq);
		if (r->dir != NULL) printf(" ");
		Prefixo(r->dir);
	}
}
	
void Infixo (arvore r) {
	if (r != NULL) {
		Infixo(r->esq);
		if (r->esq != NULL) printf(" ");
		printf("%d", r->chave);
		if (r->dir != NULL) printf(" ");
		Infixo(r->dir);
	}
}

void Posfixo (arvore r) {
	if (r != NULL) {
		Posfixo(r->esq);
		if (r->esq != NULL) printf(" ");
		Posfixo(r->dir);
		if (r->dir != NULL) printf(" ");
		printf("%d", r->chave);
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
		
		printf("Pre.: ");
		Prefixo(raiz);
		printf("\n");
		
		printf("In..: ");
		Infixo(raiz);
		printf("\n");
		
		printf("Post: ");
		Posfixo(raiz);
		printf("\n");
		
		printf("\n");
	}
	
	return 0;
}