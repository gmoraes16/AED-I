#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct celula {
	char conteudo[21];
	struct celula * seg;
}
celula;

celula * criarCelula(const char * conteudo) {
	celula * nova = (celula * ) malloc(sizeof(celula));
	if (nova != NULL) {
		strcpy(nova -> conteudo, conteudo);
		nova -> seg = NULL;
	}
	return nova;
}

void inserirOrdem(celula ** lst,
                  const char * conteudo) {
	celula * nova = criarCelula(conteudo);
	if (!nova) return;

	if ( * lst == NULL || strcmp(( * lst) -> conteudo, conteudo) > 0) {
		nova -> seg = * lst;
		* lst = nova;
		return;
	}

	celula * q = * lst;
	while (q -> seg != NULL && strcmp(q -> seg -> conteudo, conteudo) < 0) {
		q = q -> seg;
	}

	if (q -> seg == NULL || strcmp(q -> seg -> conteudo, conteudo) != 0) {
		nova -> seg = q -> seg;
		q -> seg = nova;
	} else {
		free(nova);
	}
}

void removerDuplicatas(celula * lst) {
	celula * q = lst;

	while (q != NULL && q -> seg != NULL) {
		if (strcmp(q -> conteudo, q -> seg -> conteudo) == 0) {
			celula * p = q -> seg;
			q -> seg = q -> seg -> seg;
			free(p);
		} else {
			q = q -> seg;
		}
	}
}

void imprimeLista(celula * lst) {
	celula * q = lst;
	int primeiro = 1;
	while (q != NULL) {
		if (!primeiro)
			printf(" ");
		printf("%s", q -> conteudo);
		primeiro = 0;
		q = q -> seg;
	}
	printf("\n");
}

void liberarLista(celula * lst) {
	celula * q = lst;
	while (q != NULL) {
		celula * p = q;
		q = q -> seg;
		free(p);
	}
}

int main() {
	unsigned short casos;
	char itens[20010], * cadaItem;
	celula * listaCompras = NULL;

	scanf("%hu", & casos);

	while (casos--) {

		scanf(" %[^\n]", itens);

		listaCompras = NULL;
		cadaItem = strtok(itens, " ");

		while (cadaItem != NULL) {
			inserirOrdem( & listaCompras, cadaItem);
			cadaItem = strtok(NULL, " ");
		}

		removerDuplicatas(listaCompras);
		imprimeLista(listaCompras);
		liberarLista(listaCompras);
	}

	return 0;
}