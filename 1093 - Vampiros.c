#include <stdio.h>
#include <string.h>

int visitado[10][10];
double vamp[10][10];

double calcularProb(double a, int contador) {
    if (contador == 0) {
        return 1.0;
    } else {
        return a * calcularProb(a, contador - 1);
    }
}

double prob_vamp1W(int EV1, int EV2, int AT) {
    double res = 0.0;

    if (AT == 3) {
        res = (double) EV1 / (EV1 + EV2);
    } else {
        double dado = 1.0 - (6.0 - AT) / 6.0;
        dado = (1.0 - dado) / dado;
        res = (1.0 - calcularProb(dado, EV1)) / (1.0 - calcularProb(dado, EV1 + EV2));
    }

    return res;
}

int main() {
    int EV1, EV2, AT, D;

    while (1) {
        scanf("%d %d %d %d", &EV1, &EV2, &AT, &D);
        
        if (EV1 == 0 && EV2 == 0 && AT == 0 && D == 0) break;

        memset(visitado, 0, sizeof(visitado));
        memset(vamp, 0, sizeof(vamp));

        int aux = EV1;
        EV1 = 0;
        while (aux > 0) {
            aux -= D;
            EV1++;
        }

        aux = EV2;
        EV2 = 0;
        while (aux > 0) {
            aux -= D;
            EV2++;
        }

        double p = prob_vamp1W(EV1, EV2, AT);

        printf("%.1lf\n", p * 100);
    }

    return 0;
}
