#include <stdio.h>

#define TAM 4

void exibirTabuleiro(int tabuleiro[TAM][TAM]);
int verificaSimetriaDiagonal(int tabuleiro[TAM][TAM]);
void exibirDiagonais(int tabuleiro[TAM][TAM]);

int main(void) {
    int tabuleiro[TAM][TAM] = {
        {1, 2, 3, 4},
        {2, 5, 6, 7},
        {3, 6, 8, 1},
        {4, 7, 1, 8}
    };

    exibirTabuleiro(tabuleiro);

    if (verificaSimetriaDiagonal(tabuleiro)) {
        printf("\nTodos os valores estao simetricos em relacao a diagonal principal.\n");
    } else {
        printf("\nNem todos os valores estao simetricos em relacao a diagonal principal.\n");
    }

    exibirDiagonais(tabuleiro);

    return 0;
}

void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    int i, j;

    printf("Tabuleiro 4x4:\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%3d", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int verificaSimetriaDiagonal(int tabuleiro[TAM][TAM]) {
    int i, j;

    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] != tabuleiro[j][i]) {
                return 0;
            }
        }
    }

    return 1;
}

void exibirDiagonais(int tabuleiro[TAM][TAM]) {
    int i;

    printf("\nDiagonal principal: ");
    for (i = 0; i < TAM; i++) {
        printf("%d ", tabuleiro[i][i]);
    }

    printf("\nDiagonal secundaria: ");
    for (i = 0; i < TAM; i++) {
        printf("%d ", tabuleiro[i][TAM - 1 - i]);
    }

    printf("\n");
}
