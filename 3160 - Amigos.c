#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct celula {
	char conteudo[50];
	struct celula *seg;
} celula;

void imprimeN (celula *lst) {
	celula *p;
	for (p = lst; p!=NULL; p=p->seg) {
		printf("%s", p->conteudo);
		if(p->seg != NULL) {
			printf(" ");
		}
	}
	printf("\n");
}

void insereNoFinal(celula **lst, char *nome) {
	celula *novo = (celula *)malloc(sizeof(celula));
	strcpy(novo->conteudo, nome);
	novo->seg = NULL;

	if (*lst == NULL) {
		*lst = novo;
	} else {
		celula *p = *lst;
		while (p->seg != NULL) {
			p = p->seg;
		}
		p->seg = novo;
	}
}

void insereAntes (celula **lst, char *nome, char *indicado) {
	celula *novo = (celula *)malloc(sizeof(celula));
	strcpy(novo->conteudo, nome);

	if (*lst == NULL || strcmp((*lst)->conteudo, indicado) == 0) {
		novo->seg = *lst;
		*lst = novo;
	} else {
		celula *p = *lst;
		while (p->seg != NULL && strcmp (p->seg->conteudo, indicado) != 0) {
			p = p->seg;
		}
		if (p->seg != NULL) {
			novo->seg = p->seg;
			p->seg = novo;
		} else {
			free (novo);
		}
	}
}


int main() {

	char linha1[100], linha2[100], indicado[50];
	celula *listaAmigos = NULL;

	fgets (linha1, 100, stdin);
	linha1[strcspn(linha1, "\n")] = 0;

	fgets (linha2, 100, stdin);
	linha2[strcspn(linha2, "\n")] = 0;

	fgets (indicado, 50, stdin);
	indicado[strcspn(indicado, "\n")] = 0;

	char *token = strtok (linha1, " ");
	while (token != NULL) {
		insereNoFinal(&listaAmigos, token);
		token = strtok(NULL, " ");
	}

	token = strtok(linha2, " ");
	while (token != NULL) {
		if (strcmp(indicado, "nao") == 0) {
			insereNoFinal (&listaAmigos, token);
		} else {
			insereAntes(&listaAmigos, token, indicado);
		}
		token = strtok(NULL, " ");
	}
	imprimeN(listaAmigos);

	return 0;
}