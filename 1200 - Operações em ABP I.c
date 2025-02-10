#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cel {
	char chave;
	struct cel *dir;
	struct cel *esq;
};

typedef struct cel no;
typedef no *arvore;

arvore Insere(arvore r, char chave) {
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

void Prefixo (arvore r, int *primeiro) {
	if (r != NULL) {
		if (*primeiro) {
			printf("%c", r->chave);
			*primeiro = 0;
		} else {
			printf(" %c", r->chave);
		}
		Prefixo(r->esq, primeiro);
		Prefixo(r->dir, primeiro);
	}
}

void Infixo (arvore r, int *primeiro) {
	if (r != NULL) {
		Infixo(r->esq, primeiro);
		if (*primeiro) {
			printf("%c", r->chave);
			*primeiro = 0;
		} else {
			printf(" %c", r->chave);
		}
		Infixo(r->dir, primeiro);
	}
}

void Posfixo (arvore r, int *primeiro) {
	if (r != NULL) {
		Posfixo(r->esq, primeiro);
		Posfixo(r->dir, primeiro);
		if (*primeiro) {
			printf("%c", r->chave);
			*primeiro = 0;
		} else {
			printf(" %c", r->chave);
		}
	}
}

void LiberaArvore(arvore r) {
	if (r != NULL) {
		LiberaArvore(r->esq);
		LiberaArvore(r->dir);
		free(r);
	}
}

int Busca(arvore r, char chave) {
	if (r == NULL) {
		return 0;
	}
	if (chave == r->chave) {
		return 1;
	}
	if (chave < r->chave) {
		return Busca(r->esq, chave);
	} else {
		return Busca(r->dir, chave);
	}
}

int main() {
	arvore raiz = NULL;
	char comando[10];
	char chave;

	while (scanf("%s", comando) != EOF) {
		if (strcmp(comando, "I") == 0) {
			scanf(" %c", &chave);
			raiz = Insere(raiz, chave);
		} else if (strcmp(comando, "INFIXA") == 0) {
			int primeiro = 1;
			Infixo(raiz, &primeiro);
			printf("\n");
		} else if (strcmp(comando, "PREFIXA") == 0) {
			int primeiro = 1;
			Prefixo(raiz, &primeiro);
			printf("\n");
		} else if (strcmp(comando, "POSFIXA") == 0) {
			int primeiro = 1;
			Posfixo(raiz, &primeiro);
			printf("\n");
		} else if (strcmp(comando, "P") == 0) {
			scanf(" %c", &chave);
			if (Busca(raiz, chave)) {
				printf("%c existe\n", chave);
			} else {
				printf("%c nao existe\n", chave);
			}
		} else {
			printf("Comando invalido\n");
		}
	}

	LiberaArvore(raiz);
	return 0;
}