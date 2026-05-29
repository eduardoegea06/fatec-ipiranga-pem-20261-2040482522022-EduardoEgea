#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 12

int buscaRecAux(int *v, int n, int chave, int indice, int profundidade, int *chamadas, int *profMax);
int buscaRec(int *v, int n, int chave, int *chamadas, int *profMax);
int somaRec(int *v, int ini, int fim, int profundidade, int *chamadas, int *profMax);

int main(void) {
    int vetor[TAM];
    int i;
    int chave;
    int indice;
    int soma;
    int chamadasBusca = 0;
    int profBusca = 0;
    int chamadasSoma = 0;
    int profSoma = 0;

    srand((unsigned int)time(NULL));

    printf("Vetor gerado:\n");
    for (i = 0; i < TAM; i++) {
        vetor[i] = rand() % 100;
        printf("%d ", vetor[i]);
    }
    printf("\n");

    soma = somaRec(vetor, 0, TAM - 1, 1, &chamadasSoma, &profSoma);
    printf("\nSoma total do vetor: %d\n", soma);
    printf("Chamadas recursivas em somaRec: %d\n", chamadasSoma);
    printf("Profundidade maxima em somaRec: %d\n", profSoma);

    printf("\nDigite um valor para buscar: ");
    scanf("%d", &chave);

    indice = buscaRec(vetor, TAM, chave, &chamadasBusca, &profBusca);

    if (indice != -1) {
        printf("Valor encontrado no indice %d.\n", indice);
    } else {
        printf("Valor nao existe no vetor.\n");
    }

    printf("Chamadas recursivas em buscaRec: %d\n", chamadasBusca);
    printf("Profundidade maxima em buscaRec: %d\n", profBusca);

    return 0;
}

int buscaRec(int *v, int n, int chave, int *chamadas, int *profMax) {
    return buscaRecAux(v, n, chave, 0, 1, chamadas, profMax);
}

int buscaRecAux(int *v, int n, int chave, int indice, int profundidade, int *chamadas, int *profMax) {
    (*chamadas)++;

    if (profundidade > *profMax) {
        *profMax = profundidade;
    }

    if (indice >= n) {
        /* Caso base: chegou ao fim do vetor sem encontrar a chave. */
        return -1;
    }

    if (v[indice] == chave) {
        /* Caso base: encontrou a primeira ocorrencia da chave. */
        return indice;
    }

    /* Passo recursivo: avanca para o proximo indice do vetor. */
    return buscaRecAux(v, n, chave, indice + 1, profundidade + 1, chamadas, profMax);
}

int somaRec(int *v, int ini, int fim, int profundidade, int *chamadas, int *profMax) {
    int meio;
    int somaEsquerda;
    int somaDireita;

    (*chamadas)++;

    if (profundidade > *profMax) {
        *profMax = profundidade;
    }

    if (ini == fim) {
        /* Caso base: intervalo com apenas um elemento. */
        return v[ini];
    }

    if (ini > fim) {
        /* Caso base: intervalo vazio. */
        return 0;
    }

    /* Passo recursivo: divide o intervalo em duas partes e soma cada metade. */
    meio = (ini + fim) / 2;
    somaEsquerda = somaRec(v, ini, meio, profundidade + 1, chamadas, profMax);
    somaDireita = somaRec(v, meio + 1, fim, profundidade + 1, chamadas, profMax);

    return somaEsquerda + somaDireita;
}
