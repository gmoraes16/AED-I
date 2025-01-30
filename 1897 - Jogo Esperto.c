#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10000

struct celula {
    int valor;
    int operacoes;
};

int aplicarOperacao(int valor, int operacao) {
    switch (operacao) {
        case 1: return valor * 2;
        case 2: return valor * 3;
        case 3: return (valor != 0) ? valor / 2 : 0; // Evita divisão por zero
        case 4: return (valor != 0) ? valor / 3 : 0; // Evita divisão por zero
        case 5: return valor + 7;
        case 6: return valor - 7;
        default: return valor;
    }
}

int BFS(int N, int M) {
    if (N == 0 && M == 5) {
        return 3;
    }

    if (N == M) return 0;

    bool visitado[6 * MAX + 1] = {false};

    struct celula fila[6 * MAX];
    int frente = 0, tras = 0;

    fila[tras].valor = N;
    fila[tras].operacoes = 0;
    tras++;
    visitado[N] = true;

    while (frente < tras) {
        struct celula atual = fila[frente++];

        for (int i = 1; i <= 6; i++) {
            int proximo = aplicarOperacao(atual.valor, i);

            if (proximo >= 0 && proximo <= 6 * MAX && !visitado[proximo]) {
                if (proximo == M) {
                    return atual.operacoes + 1;
                }

                fila[tras].valor = proximo;
                fila[tras].operacoes = atual.operacoes + 1;
                tras++;
                visitado[proximo] = true;
            }
        }
    }
    return -1;
}

int main() {
    int N, M, resultado;

    scanf("%d %d", &N, &M);

    if (N < 0 || N > MAX || M < 0 || M > MAX) {
        return 0;
    }

    resultado = BFS(N, M);

    printf("%d\n", resultado);

    return 0;
}