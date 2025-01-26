#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    char identificador[6];
    struct celula *prox;
} celula;

celula* filaOeste = NULL;
celula* filaNorte = NULL;
celula* filaSul = NULL;
celula* filaLeste = NULL;

void inserirAviao(celula** fila, char identificador[]) {
    celula* novo = (celula*)malloc(sizeof(celula));
    strcpy(novo->identificador, identificador);
    novo->prox = NULL;

    if (*fila == NULL) {
        *fila = novo;
    } else {
        celula* temp = *fila;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novo;
    }
}

void imprimirFila() {
    Celula *tempOeste, *tempNorte, *tempSul, *tempLeste;
    int first = 1;

    while (filaOeste != NULL || filaNorte != NULL || filaSul != NULL || filaLeste != NULL) {
        if (filaOeste != NULL) {
            if (!first) printf(" ");
            printf("%s", filaOeste->identificador);
            first = 0;
            tempOeste = filaOeste;
            filaOeste = filaOeste->prox;
            free(tempOeste);
        }

        if (filaNorte != NULL) {
            if (!first) printf(" ");
            printf("%s", filaNorte->identificador);
            first = 0;
            tempNorte = filaNorte;
            filaNorte = filaNorte->prox;
            free(tempNorte);
        }

        if (filaSul != NULL) {
            if (!first) printf(" ");
            printf("%s", filaSul->identificador);
            first = 0;
            tempSul = filaSul;
            filaSul = filaSul->prox;
            free(tempSul);
        }

        if (filaLeste != NULL) {
            if (!first) printf(" ");
            printf("%s", filaLeste->identificador);
            first = 0;
            tempLeste = filaLeste;
            filaLeste = filaLeste->prox;
            free(tempLeste);
        }
    }

    printf("\n");
}

int main() {
    int P;
    char identificador[6];
    
    scanf("%d", &P);

    while (1) {
        if (P == 0) break;
        
        scanf("%s", identificador);

        if (P == -1) {
            inserirAviao(&filaOeste, identificador);
        } else if (P == -3) {
            inserirAviao(&filaNorte, identificador);
        } else if (P == -2) {
            inserirAviao(&filaSul, identificador);
        } else if (P == -4) {
            inserirAviao(&filaLeste, identificador);
        }
        
        scanf("%d", &P);
    }

    imprimirFila();

    return 0;
}
