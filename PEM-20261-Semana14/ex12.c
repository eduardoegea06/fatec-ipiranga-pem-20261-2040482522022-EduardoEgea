#include <stdio.h>

void troca(int *a, int *b);
void minMax(int *v, int n, int *min, int *max);
void normalizaVetor(float *v, int n);

int main(void) {
    int x = 5, y = 9;
    int vetorInt[5] = {8, 3, 10, 1, 6};
    int min, max;
    float vetorFloat[5] = {2.0f, 4.0f, 6.0f, 8.0f, 10.0f};
    int i;

    printf("Antes da troca: x = %d, y = %d\n", x, y);
    troca(&x, &y);
    printf("Depois da troca: x = %d, y = %d\n", x, y);

    minMax(vetorInt, 5, &min, &max);
    printf("\nMenor valor do vetor: %d\n", min);
    printf("Maior valor do vetor: %d\n", max);

    printf("\nVetor float antes da normalizacao: ");
    for (i = 0; i < 5; i++) {
        printf("%.2f ", vetorFloat[i]);
    }

    normalizaVetor(vetorFloat, 5);

    printf("\nVetor float depois da normalizacao: ");
    for (i = 0; i < 5; i++) {
        printf("%.2f ", vetorFloat[i]);
    }
    printf("\n");

    return 0;
}

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minMax(int *v, int n, int *min, int *max) {
    int i;

    *min = *v;
    *max = *v;

    for (i = 1; i < n; i++) {
        if (*(v + i) < *min) {
            *min = *(v + i);
        }

        if (*(v + i) > *max) {
            *max = *(v + i);
        }
    }
}

void normalizaVetor(float *v, int n) {
    int i;
    float maior = *v;

    for (i = 1; i < n; i++) {
        if (*(v + i) > maior) {
            maior = *(v + i);
        }
    }

    if (maior != 0.0f) {
        for (i = 0; i < n; i++) {
            *(v + i) = *(v + i) / maior;
        }
    }
}
