#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int valor;
    int min;
    struct celula *seg;
} celula;

void Empilha(int y, celula **p) {
    celula *nova = malloc(sizeof(celula));
    nova->valor = y;
    nova->min = (*p == NULL) ? y : (y < (*p)->min ? y : (*p)->min);
    nova->seg = *p;
    *p = nova;
}

int Desempilha(celula **p) {
    if (*p == NULL) {
        printf("EMPTY\n");
        return -1;
    }
    int x = (*p)->valor;
    celula *q = *p;
    *p = (*p)->seg;
    free(q);
    return x;
}

int Minimo(celula *p) {
    if (p == NULL) {
        printf("EMPTY\n");
        return -1;
    }
    return p->min;
}

int main() {
    int N, V;
    char operacao[5];
    celula *pilha = NULL;
    
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        scanf("%s", operacao);
        
        if (operacao[1] == 'U') {
            scanf("%d", &V);
            Empilha(V, &pilha);
        } else if (operacao[1] == 'O') {
            Desempilha(&pilha);
        } else if (operacao[1] == 'I') {
            int minValue = Minimo(pilha);
            if (minValue != -1) {
                printf("%d\n", minValue);
            }
        }
    }
    return 0;
}