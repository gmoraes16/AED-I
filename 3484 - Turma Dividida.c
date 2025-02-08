#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int altura;
    struct celula *esquerda;
    struct celula *direita;
}celula;

celula* criarCel(int altura) {
    celula *nova = (celula*)malloc(sizeof(celula));
    nova->altura = altura;
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

celula* insere(celula* raiz, int altura) {
    if (raiz == NULL) {
        return criarCel(altura);
    }
    if (altura < raiz->altura) {
        raiz->esquerda = insere(raiz->esquerda, altura);
    } else {
        raiz->direita = insere(raiz->direita, altura);
    }
    return raiz;
}

void ProcurarMenorAltura(celula* raiz, int nivel, int* menorAltura) {
    if (raiz == NULL) {
        return;
    }
    if (menorAltura[nivel] == 0 || raiz->altura < menorAltura[nivel]) {
        menorAltura[nivel] = raiz->altura;
    }
    
    ProcurarMenorAltura(raiz->esquerda, nivel + 1, menorAltura);
    ProcurarMenorAltura(raiz->direita, nivel + 1, menorAltura);
}

int main() {
    int N, i;
    scanf("%d", &N);
    
    int* alturas = (int*)malloc(N * sizeof(int));
    for (i = 0; i < N; i++) {
        scanf("%d", &alturas[i]);
    }
    
    celula* raiz = NULL;
    for (i = 0; i < N; i++) {
        raiz = insere(raiz, alturas[i]);
    }
    
    int menorAltura[250] = {0};
    
    ProcurarMenorAltura(raiz, 0, menorAltura);
    
    for (i = 0; i < 250; i++) {
        if (menorAltura[i] != 0) {
        printf("%d %d\n", i, menorAltura[i]);
        }
    }
    
    free(alturas);
    return 0;
}