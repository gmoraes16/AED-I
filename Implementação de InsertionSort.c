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
    int v[] = {2, 6, 10, 35, 16, 1, 60, 8};
    int n = sizeof(v) / sizeof(v[0]);
    
    Inserção(n, v);

    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
