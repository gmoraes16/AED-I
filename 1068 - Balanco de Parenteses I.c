#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bemFormada(char s[]) {
    char *p;
    int t = 0;

    int n = strlen(s);
    p = malloc(n * sizeof(char));

    for (int i = 0; i < n; ++i) {
        switch (s[i]) {
            case ')':
                if (t == 0 || p[--t] != '(') {
                    free(p);
                    return 0;
                }
                break;
            case ']':
                if (t == 0 || p[--t] != '[') {
                    free(p);
                    return 0;
                }
                break;
            case '(':
            case '[':
                p[t++] = s[i];
                break;
        }
    }

    free(p);
    return t == 0;
}

int main() {
    char s[1000];

    while (scanf("%s", s) != EOF) {
        if (bemFormada(s)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}