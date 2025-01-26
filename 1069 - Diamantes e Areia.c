#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int diamantes(char s[]) {
    char *p;
    int t = 0, contar = 0;

    int n = strlen(s);
    p = malloc(n * sizeof(char));

    for (int i = 0; i < n; ++i) {
        switch (s[i]) {
            case '>':
                if (t > 0 && p[t - 1] == '<') {
                    t--;
                    contar++;
                }
                break;
            case '<':
                p[t++] = s[i];
                break;
        }
    }

    free(p);
    return contar;
}

int main() {
    char s[1000];
    int N;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", s);
        printf("%d\n", diamantes(s));
    }

    return 0;
}