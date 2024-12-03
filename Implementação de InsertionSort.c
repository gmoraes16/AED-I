#include <stdio.h>

void Inserção(int n, int v[]) {
    int i, j, x;
    for (j = 1; j < n; j++) {
        x = v[j];
        for (i = j-1; i >= 0 && v[i] > x; i--) {
            v[i+1] = v[i];
        }
        v[i+1] = x;
    }
}

int main() {
    int n = 50000;  // Número de elementos
    int v[n];

    // Gerador de números aleatórios
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        v[i] = rand();
    }

    Inserção(t, v);

    for (int i = 0; i < t; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
