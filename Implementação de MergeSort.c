#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Intercala(int p, int q, int r, int v[]) {
    int i, j, k, *w;
    w = malloc((r - p + 1) * sizeof(int));
    i = p; j = q; k = 0;
    while (i < q && j < r) {
        if (v[i] <= v[j]) w[k++] = v[i++];
        else w[k++] = v[j++];
    }
    while (i < q) w[k++] = v[i++];
    while (j < r) w[k++] = v[j++];
    for (i = p; i < r; i++) v[i] = w[i - p];
    free(w);
}

void Mergesort(int p, int r, int v[]) {
    if (p < r - 1) {
        int q = (p + r) / 2;
        Mergesort(p, q, v);
        Mergesort(q, r, v);
        Intercala(p, q, r, v);
    }
}

int main() {
    int n = 20000;  // Numero de elementos
    int v[n];

    // Gera numeros aleatorios
    srand(time(NULL));

 for (int i = 0; i < n; i++) {
        v[i] = rand();
    }
    
    Mergesort(0, n, v);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
