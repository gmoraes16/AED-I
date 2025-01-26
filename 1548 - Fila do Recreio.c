#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int valor;
    int original_p;
    struct cel *seg;
} celula;

void InsereOrdenado(int valor, celula **head, int pos) {
    celula *nova = malloc(sizeof(celula));
    nova->valor = valor;
    nova->original_p = pos;

    if (*head == NULL || (*head)->valor < valor) {
        nova->seg = *head;
        *head = nova;
    } else {
        celula *atual = *head;
        while (atual->seg != NULL && atual->seg->valor >= valor) {
            atual = atual->seg;
        }
        nova->seg = atual->seg;
        atual->seg = nova;
    }
}

int NaoMudaramDePosicao(celula *lista) {
    int count = 0;
    int pos = 0;
    celula *i;
    for (i = lista; i != NULL; i = i->seg) {
        if (i->original_p == pos) {
            count++;
        }
        pos++;
    }
    return count;
}

int main() {
    int t, n, i, m;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        celula *lista = NULL;

        for (i = 0; i < n; i++) {
            scanf("%d", &m);
            InsereOrdenado(m, &lista, i);
        }

        int count = NaoMudaramDePosicao(lista);
        
        printf("%d\n", count);
    }

    return 0;
}
