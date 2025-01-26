#include <stdlib.h>
#include <string.h>

typedef struct celula {
    int valor;
    struct celula *seg;
} celula;

celula *criapilha() {
    celula *p = malloc(sizeof(celula));
    p->seg = NULL;
    return p;
}

void empilha(int y, celula *p) {
    celula *nova = malloc(sizeof(celula));
    nova->valor = y;
    nova->seg = p->seg;
    p->seg = nova;
}

int desempilha(celula *p) {
    int x;
    celula *q = p->seg;
    x = q->valor;
    p->seg = q->seg;
    free(q);
    return x;
}

int prioridade(char op) {
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

char *infixaParaPosfixa(char *inf) {
    int n = strlen(inf);
    char *posf = malloc((n + 1) * sizeof(char));
    celula *p = criapilha();
    int j = 0;
    
    for (int i = 0; inf[i] != '\0'; ++i) {
        char x;
        if (inf[i] >= '0' && inf[i] <= '9' || inf[i] >= 'A' && inf[i] <= 'Z' || inf[i] >= 'a' && inf[i] <= 'z') {
            posf[j++] = inf[i];
        } else if (inf[i] == '(') {
            empilha('(', p);
        } else if (inf[i] == ')') {
            while ((x = desempilha(p)) != '(') {
                posf[j++] = x;
            }
        } else {
            while (p->seg != NULL && prioridade(p->seg->valor) >= prioridade(inf[i])) {
                posf[j++] = desempilha(p);
            }
            empilha(inf[i], p);
        }
    }

    while (p->seg != NULL) {
        posf[j++] = desempilha(p);
    }

    posf[j] = '\0';
    free(p);
    return posf;
}

int main() {
    char s[1000];
    int N;

    if (scanf("%d", &N) != 1) {
        return 1;
    }

    for (int i = 0; i < N; i++) {
        if (scanf("%s", s) != 1) {
            return 1;
        }
        char *posf = infixaParaPosfixa(s);
        printf("%s\n", posf);
        free(posf);
    }

    return 0;
}