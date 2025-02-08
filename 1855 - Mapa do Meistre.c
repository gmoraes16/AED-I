#include <stdio.h>

char verifica_mapa(char mapa[][100], int largura, int altura) {
    int x = 0, y = 0;
    int visitados[100][100] = {0};


    int dx = 0, dy = 0;

    while (1) {

        if (x < 0 || x >= largura || y < 0 || y >= altura) {
            return '!';
        }


        if (visitados[y][x]) {
            return '!';
        }
        visitados[y][x] = 1;


        if (mapa[y][x] == '*') {
            return '*';
        } else if (mapa[y][x] == '>') {
            dx = 1;
            dy = 0;
        } else if (mapa[y][x] == '<') {
            dx = -1;
            dy = 0;
        } else if (mapa[y][x] == 'v') {
            dx = 0;
            dy = 1;
        } else if (mapa[y][x] == '^') {
            dx = 0;
            dy = -1;
        } else if (mapa[y][x] != '.') {
            return '!';
        }

        x += dx;
        y += dy;
    }
}

int main() {
    int largura, altura;
    scanf("%d", &largura);
    scanf("%d", &altura);

    char mapa[100][100];
    for (int i = 0; i < altura; i++) {
        scanf("%s", mapa[i]);
    }

    char resultado = verifica_mapa(mapa, largura, altura);
    printf("%c\n", resultado);

    return 0;
}
