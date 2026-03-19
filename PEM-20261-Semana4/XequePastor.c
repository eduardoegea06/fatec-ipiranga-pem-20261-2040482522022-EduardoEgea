/**-------------------------------------------*
* -Nome: Eduardo Martinez Ferreira Egea
  -Fatec Ipiranga - Ads Vespertino 
  -Atividade PEM - Aula 4 - Dia 13/03/2025
  -Objetivo: Desenvolver um xeque pastor usando c.          
  *-------------------------------------------*/

#include <stdio.h>
#include <string.h>

#define TAM 8

void imprimirTabuleiro(char tab[TAM][TAM][4]) {
    printf("\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%-4s", tab[i][j]);
        }
        printf("\n");
    }
}

void pausar() {
    printf("\nPressione ENTER para próxima jogada...");
    getchar();
}

// Inicializa tabuleiro
void inicializarTabuleiro(char tab[TAM][TAM][4]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            strcpy(tab[i][j], "---");

    for (int j = 0; j < TAM; j++) {
        strcpy(tab[1][j], "PP");
        strcpy(tab[6][j], "PB");
    }

    strcpy(tab[0][0], "TP"); strcpy(tab[0][7], "TP");
    strcpy(tab[7][0], "TB"); strcpy(tab[7][7], "TB");

    strcpy(tab[0][1], "CP"); strcpy(tab[0][6], "CP");
    strcpy(tab[7][1], "CB"); strcpy(tab[7][6], "CB");

    strcpy(tab[0][2], "BP"); strcpy(tab[0][5], "BP");
    strcpy(tab[7][2], "BB"); strcpy(tab[7][5], "BB");

    strcpy(tab[0][3], "DP");
    strcpy(tab[7][3], "DB");

    strcpy(tab[0][4], "RP");
    strcpy(tab[7][4], "RB");
}

// Move peça mostrando origem e destino
void mover(char tab[TAM][TAM][4], int li, int ci, int lf, int cf, char nome[]) {
    strcpy(tab[li][ci], "...");   // origem
    strcpy(tab[lf][cf], nome);    // destino
}

int main() {
    char tab[TAM][TAM][4];

    inicializarTabuleiro(tab);

    printf("TABULEIRO INICIAL:\n");
    imprimirTabuleiro(tab);
    pausar();

    // Jogada 1
    printf("\nBrancas: Peão e2 -> e4\n");
    mover(tab, 6, 4, 4, 4, "PB5");
    imprimirTabuleiro(tab);
    pausar();

    printf("\nPretas: Peão e7 -> e5\n");
    mover(tab, 1, 4, 3, 4, "PP5");
    imprimirTabuleiro(tab);
    pausar();

    // Jogada 2
    printf("\nBrancas: Bispo f1 -> c4\n");
    mover(tab, 7, 5, 4, 2, "BB");
    imprimirTabuleiro(tab);
    pausar();

    printf("\nPretas: Cavalo b8 -> c6\n");
    mover(tab, 0, 1, 2, 2, "CP");
    imprimirTabuleiro(tab);
    pausar();

    // Jogada 3
    printf("\nBrancas: Dama d1 -> h5\n");
    mover(tab, 7, 3, 3, 7, "DB");
    imprimirTabuleiro(tab);
    pausar();

    printf("\nPretas: Cavalo g8 -> f6\n");
    mover(tab, 0, 6, 2, 5, "CP");
    imprimirTabuleiro(tab);
    pausar();

    // Jogada final
    printf("\nBrancas: Dama captura em f7 (Xeque Mate)\n");
    mover(tab, 3, 7, 1, 5, "DB");
    imprimirTabuleiro(tab);

    printf("\nXEQUE MATE!\n");

    return 0;
}
