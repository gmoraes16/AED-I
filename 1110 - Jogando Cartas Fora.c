#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int valor;
    struct cel *seg;
} celula;

void Empilha(int y, celula **inicio, celula **fim) {
    celula *nova = malloc(sizeof(celula));
    nova->valor = y;
    nova->seg = NULL;
    if (*fim != NULL) {
        (*fim)->seg = nova;
    } else {
        *inicio = nova;
    }
    *fim = nova;
}

int Desempilha(celula **inicio, celula **fim) {
    if (*inicio == NULL) return -1;
    int x = (*inicio)->valor;
    celula *t = *inicio;
    *inicio = (*inicio)->seg;
    if (*inicio == NULL) {
        *fim = NULL;
    }
    free(t);
    return x;
}

int main() {
    int n, descartado;
    
    while (n != 0) {
        scanf("%d", &n);
        if (n == 0) break;

        celula *inicio = NULL, *fim = NULL;

        for (int i = 1; i <= n; i++) {
            Empilha(i, &inicio, &fim);
        }

        printf("Discarded cards: ");
        int primeira = 1;
        while (inicio != NULL && inicio->seg != NULL) {
            descartado = Desempilha(&inicio, &fim);
            if (primeira) {
                printf("%d", descartado);
                primeira = 0;
            } else {
                printf(", %d", descartado);
            }
            
            Empilha(Desempilha(&inicio, &fim), &inicio, &fim);
        }

        if (inicio != NULL) {
            printf("\nRemaining card: %d\n", Desempilha(&inicio, &fim));
        }
    }

    return 0;
}