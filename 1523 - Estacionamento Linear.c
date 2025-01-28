#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K, C, S, i;
    
    while (1) {
        scanf("%d %d", &N, &K);
        if (N == 0 && K == 0) {
            break;
        }

        int chegada[N], saida[N];

        for (i = 0; i < N; i++) {
            scanf("%d %d", &C, &S);
            chegada[i] = C;
            saida[i] = S;
        }

        int pilha_tamanho = 0;
        int possivel = 1;
        int topo_pilha = -1;
        int pilha_saida[K];

        for (i = 0; i < N; i++) {
            C = chegada[i];
            S = saida[i];

            while (topo_pilha >= 0 && pilha_saida[topo_pilha] <= C) {
                topo_pilha--;
                pilha_tamanho--;
            }

            if (pilha_tamanho < K) {
                if (topo_pilha >= 0 && pilha_saida[topo_pilha] < S) {
                    possivel = 0;
                    break;
                }


                topo_pilha++;
                pilha_saida[topo_pilha] = S;
                pilha_tamanho++;
            } else {
                possivel = 0;
                break;
            }
        }

        if (possivel) {
            printf("Sim\n");
        } else {
            printf("Nao\n");
        }
    }

    return 0;
}