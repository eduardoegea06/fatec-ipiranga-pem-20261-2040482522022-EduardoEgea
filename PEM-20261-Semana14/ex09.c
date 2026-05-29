#include <stdio.h>

#define TAM 3

int main(void) {
    int A[TAM][TAM];
    int B[TAM][TAM];
    int C[TAM][TAM];
    int i, j, k;

    printf("Digite os valores da matriz A:\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nDigite os valores da matriz B:\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            C[i][j] = 0;

            /*
               i representa a linha da matriz A.
               j representa a coluna da matriz B.
               k percorre os elementos usados na soma A[i][k] * B[k][j].
            */
            for (k = 0; k < TAM; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\nMatriz A:\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%5d", A[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz B:\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%5d", B[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz C = A x B:\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%5d", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
