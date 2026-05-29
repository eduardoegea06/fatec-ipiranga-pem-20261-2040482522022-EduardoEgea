#include <stdio.h>

void hanoi(int n, char origem, char destino, char auxiliar, long long *movimentos);
long long potenciaDeDois(int n);

int main(void) {
    int n;
    long long movimentos = 0;
    long long esperado;

    printf("Digite a quantidade de discos (1 a 10): ");
    scanf("%d", &n);

    if (n < 1 || n > 10) {
        printf("Erro: N deve estar entre 1 e 10.\n");
        return 0;
    }

    hanoi(n, 'A', 'C', 'B', &movimentos);

    esperado = potenciaDeDois(n) - 1;

    printf("\nTotal de movimentos realizados: %lld\n", movimentos);
    printf("Total esperado por 2^n - 1: %lld\n", esperado);

    if (movimentos == esperado) {
        printf("A quantidade de movimentos coincide com 2^n - 1.\n");
    } else {
        printf("A quantidade de movimentos nao coincide.\n");
    }

    return 0;
}

void hanoi(int n, char origem, char destino, char auxiliar, long long *movimentos) {
    if (n == 1) {
        /* Caso base: com apenas um disco, basta mover diretamente da origem ao destino. */
        printf("Mova disco 1 de %c para %c\n", origem, destino);
        (*movimentos)++;
    } else {
        /* Passo recursivo: move n - 1 discos para liberar o maior disco. */
        hanoi(n - 1, origem, auxiliar, destino, movimentos);
        printf("Mova disco %d de %c para %c\n", n, origem, destino);
        (*movimentos)++;
        hanoi(n - 1, auxiliar, destino, origem, movimentos);
    }
}

long long potenciaDeDois(int n) {
    long long resultado = 1;
    int i;

    for (i = 0; i < n; i++) {
        resultado *= 2;
    }

    return resultado;
}
