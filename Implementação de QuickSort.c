#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Separa(int p, int r, int v[]) {
    int c, j, k, t;
    c = v[r];
    j = p;
    for (k = p; k < r; k++) {
        if (v[k] <= c) {
            t = v[j];
            v[j] = v[k];
            v[k] = t;
            j++;
        }
    }
    t = v[j];
    v[j] = v[r];
    v[r] = t;
    return j;
}

void QuickSort(int p, int r, int v[]) {
    int j;
    if (p < r) {
        j = Separa(p, r, v);
        QuickSort(p, j - 1, v);
        QuickSort(j + 1, r, v);
    }
}

int main() {
    int n = 400000;  // Numero de elementos
    int v[n];

    // Gera numeros aleatorios
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        v[i] = rand();
    }

    QuickSort(0, n - 1, v);

    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
