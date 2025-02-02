#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
	char conteudo[101];
	struct celula *prox;
}celula;

void Insere (char *x, celula **p) {
	celula *nova = (celula *)malloc(sizeof(celula));
	strcpy(nova->conteudo, x);
	nova->prox = NULL;
	
	if (*p == NULL) {
		*p = nova;
	} else {
		celula *q = *p;
		while (q->prox != NULL) {
			q = q->prox;
		}
		q->prox = nova;
	}
}

void LiberaLista(celula *p) {
	celula *q;
	while (p != NULL) {
		q = p;
		p = p->prox;
		free(q);
	}
}
 
int main() {
 
    int N, i, j;
    int erros[4] = {0};
    char palpite[101], vencedor[101];
    
    scanf("%d", &N);
    getchar();
    
    for (i = 0; i < N; i++) {
    	celula *Palpites = NULL;
    	celula *Vencedores = NULL;
    	
    	char linha[20];
    	fgets(linha, 20, stdin);
    	
    	for (j = 0; j < 4; j++) {
        	fgets(palpite, 101, stdin);
        	palpite[strcspn(palpite, "\n")] = '\0';
        	Insere(palpite, &Palpites);
		}
		
		fgets(linha, 20, stdin);
    
		for (j = 0; j < 4; j++) {
        	fgets(vencedor, 101, stdin);
        	vencedor[strcspn(vencedor, "\n")] = '\0';
        	Insere(vencedor, &Vencedores);
		} 
		
		celula *p = Palpites;
		celula *v = Vencedores;
		
		for (j = 0; j < 4; j++) {
			if (strcmp(p->conteudo, v->conteudo) != 0) {
				erros[j]++;
			}
			p = p->prox;
			v = v->prox;
		}
		
		LiberaLista(Palpites);
		LiberaLista(Vencedores);
	
    }
    
    int maxErros = 0;
    for (i = 0; i < 4; i++) {
    	if (erros[i] > maxErros) {
    		maxErros = erros[i];
		}
	}
	
	int primeiro = 1;
    for (i = 0; i < 4; i++) {
        if (erros[i] == maxErros) {
        	if(!primeiro) {
        		printf(" ");
			}
            printf("%d ", i + 1);
            primeiro = 0;
        }
    }
	printf("\n");
    
    return 0;
}