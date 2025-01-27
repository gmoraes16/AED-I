#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int valor;
    struct celula *seg;
} celula;

void InsereEmHeap(int tamanho, int v[]) {
    int f = tamanho;
    while (f > 1 && v[f / 2] < v[f]) {
        int t = v[f / 2];
        v[f / 2] = v[f];
        v[f] = t;
        f = f / 2;
    }
}

void SacodeHeap(int tamanho, int v[]) {
    int t, f = 1;
    while (2 * f <= tamanho) {
        int j = 2 * f;
        if (j < tamanho && v[j] < v[j + 1])
            j++;
        if (v[f] >= v[j])
            break;
        t = v[f];
        v[f] = v[j];
        v[j] = t;
        f = j;
    }
}

void Empilha(int y, celula **p) {
    celula *nova = malloc(sizeof(celula));
    nova->valor = y;
    nova->seg = *p;
    *p = nova;
}

int Desempilha(celula **p) {
    if (*p == NULL) {
        printf("Pilha vazia!\n");
        exit(1);
    }
    int x = (*p)->valor;
    celula *q = *p;
    *p = (*p)->seg;
    free(q);
    return x;
}

void Insere(int y, celula **es, celula **et) {
    celula *nova = malloc(sizeof(celula));
    nova->valor = y;
    nova->seg = NULL;
    if (*et == NULL) {
        *et = *es = nova;
    } else {
        (*et)->seg = nova;
        *et = nova;
    }
}

int Remove(celula **es, celula **et) {
    if (*es == NULL) {
        printf("Fila vazia!\n");
        exit(1);
    }
    int x = (*es)->valor;
    celula *p = *es;
    *es = p->seg;
    free(p);
    if (*es == NULL) {
        *et = NULL;
    }
    return x;
}

int main() {
    int n, i, comando, valor;

    while (scanf("%d", &n) != EOF) {
        celula *pilha = NULL;
        celula *fila_es = NULL, *fila_et = NULL;
        int heap[1001], tamanho_heap = 0;

        int eh_pilha = 1, eh_fila = 1, eh_heap = 1;

        for (i = 0; i < n; i++) {
            scanf("%d", &comando);

            if (comando == 1) {
                scanf("%d", &valor);
                if (eh_pilha) Empilha(valor, &pilha);
                if (eh_fila) Insere(valor, &fila_es, &fila_et);
                if (eh_heap) heap[++tamanho_heap] = valor, InsereEmHeap(tamanho_heap, heap);
            } else if (comando == 2) {
                scanf("%d", &valor);
                if (eh_pilha && (pilha == NULL || Desempilha(&pilha) != valor)) eh_pilha = 0;
                if (eh_fila && (fila_es == NULL || Remove(&fila_es, &fila_et) != valor)) eh_fila = 0;
                if (eh_heap && (tamanho_heap == 0 || heap[1] != valor)) eh_heap = 0;
                if (tamanho_heap > 0) heap[1] = heap[tamanho_heap--], SacodeHeap(tamanho_heap, heap);
            }
        }

        if (eh_pilha + eh_fila + eh_heap > 1)
            printf("not sure\n");
        else if (eh_pilha)
            printf("stack\n");
        else if (eh_fila)
            printf("queue\n");
        else if (eh_heap)
            printf("priority queue\n");
        else
            printf("impossible\n");
    }

    return 0;
}