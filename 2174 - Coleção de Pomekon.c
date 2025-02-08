#include <stdio.h>
#include <string.h>

int main() {
    int N, i, j;
    scanf("%d", &N);

    char pomekon[N][151];
    int count = 0;
    char todosPomekon[151][151] = {0};

    for (i = 0; i < N; i++) {
        scanf("%s", pomekon[i]);
        int unico = 1;

        for (j = 0; j < count; j++) {
            if (strcmp(pomekon[i], todosPomekon[j]) == 0) {
                unico = 0;
                break;
            }
        }
        if (unico) {
            strcpy(todosPomekon[count], pomekon[i]);
            count++;
        }
    }

    printf("Falta(m) %d pomekon(s).\n", 151 - count);

    return 0;
}