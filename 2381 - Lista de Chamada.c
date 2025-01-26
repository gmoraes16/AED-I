#include <stdio.h>
#include <string.h>

void InsereEmHeap(int m, char v[][21], int pos[]) {
    int f = m + 1;
    while (f > 1 && strcmp(v[pos[f / 2]], v[pos[f]]) < 0) {
        int t = pos[f / 2]; pos[f / 2] = pos[f]; pos[f] = t;
        f = f / 2;
    } 
}

void SacodeHeap(int m, char v[][21], int pos[]) {
    int t; 
    int f = 2;
    while (f <= m) {
        if (f < m && strcmp(v[pos[f]], v[pos[f + 1]]) < 0) ++f;
        if (strcmp(v[pos[f / 2]], v[pos[f]]) >= 0) break;
        t = pos[f / 2]; pos[f / 2] = pos[f]; pos[f] = t;
        f *= 2;
    }
}

void Heapsort(int n, char v[][21], int pos[]) {
    int m;
    for (m = 1; m < n; m++) {
        InsereEmHeap(m, v, pos);
    }
    for (m = n; m > 1; m--) {
        int t = pos[1]; pos[1] = pos[m]; pos[m] = t;
        SacodeHeap(m - 1, v, pos);
    }
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    char alunos[N][21];
    int pos[N + 1];

    for (int i = 0; i < N; i++) {
        scanf("%s", alunos[i]);
        pos[i + 1] = i;
    }

    Heapsort(N, alunos, pos);

    printf("%s\n", alunos[pos[K]]);
    
    return 0;
}
