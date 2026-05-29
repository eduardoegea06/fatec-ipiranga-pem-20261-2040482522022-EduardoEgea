#include <stdio.h>

#define N 8

int main(void) {
    int vetor[N];
    int inverso[N];
    int maior, menor;
    int indiceMaior = 0, indiceMenor = 0;
    int pares = 0, impares = 0;
    int busca;
    int encontrado = -1;
    int i;

    for (i = 0; i < N; i++) {
        printf("Digite o elemento %d: ", i);
        scanf("%d", &vetor[i]);
    }

    maior = vetor[0];
    menor = vetor[0];

    for (i = 0; i < N; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
            indiceMaior = i;
        }

        if (vetor[i] < menor) {
            menor = vetor[i];
            indiceMenor = i;
        }

        if (vetor[i] % 2 == 0) {
            pares++;
        } else {
            impares++;
        }

        inverso[N - 1 - i] = vetor[i];
    }

    printf("\nVetor original: ");
    for (i = 0; i < N; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\nVetor inverso: ");
    for (i = 0; i < N; i++) {
        printf("%d ", inverso[i]);
    }

    printf("\n\nMaior valor: %d no indice %d\n", maior, indiceMaior);
    printf("Menor valor: %d no indice %d\n", menor, indiceMenor);
    printf("Quantidade de pares: %d\n", pares);
    printf("Quantidade de impares: %d\n", impares);

    printf("\nDigite um valor para buscar: ");
    scanf("%d", &busca);

    for (i = 0; i < N; i++) {
        if (vetor[i] == busca) {
            encontrado = i;
            break;
        }
    }

    if (encontrado != -1) {
        printf("Valor encontrado no indice %d.\n", encontrado);
    } else {
        printf("Valor nao existe no vetor.\n");
    }

    return 0;
}
