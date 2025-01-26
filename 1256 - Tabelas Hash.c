#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No *seg;
} No;

No* criarNo (int chave) {
    No* novo = (No*)malloc(sizeof(No));
    novo->chave = chave;
    novo->seg = NULL;
    return novo;
}

void FreeTable (No** hashtable, int t) {
    for (int i = 0; i < t; i++) {
        No* q = hashtable[i];
        while (q != NULL) {
            No* p = q;
            q = q->seg;
            free(p);
        }
    }
}

void inserirNo(No** lista, int chave) {
    No* novo = criarNo(chave);
    if (*lista == NULL) {
        *lista = novo;
    } else {
        No* temp = *lista;
        while (temp->seg != NULL) {
            temp = temp->seg;
        }
        temp->seg = novo;
    }
}

int main() {
	int N, M, C, i, j, chave, indice;
    
    scanf("%d", &N);
    
    for (j = 0; j < N; j++) {
        if (j > 0) {
            printf("\n");
        }
        scanf("%d %d", &M, &C);
        
        No* hashtable[M];
        for (i = 0; i < M; i++) {
            hashtable[i] = NULL;
        }
        
        for (i = 0; i < C; i++) {
            scanf("%d", &chave);
            
            indice = chave % M;
            
            inserirNo(&hashtable[indice], chave);
        }
        
        for (i = 0; i < M; i++) {
            printf("%d ->", i);
            No* q = hashtable[i];
            while (q != NULL) {
                printf(" %d ->", q->chave);
                q = q->seg;
            }
            printf(" \\\n");
        }
        
        FreeTable(hashtable, M);
    }
    
    return 0;
}