#include <stdio.h>

int main(void) {
    long long n;
    int passos = 0;

    printf("Digite um inteiro positivo: ");
    scanf("%lld", &n);

    if (n <= 0) {
        printf("Erro: o valor deve ser maior que zero.\n");
    } else {
        printf("Sequencia de Collatz:\n");
        printf("%lld", n);

        while (n != 1) {
            if (n % 2 == 0) {
                n = n / 2;
            } else {
                n = 3 * n + 1;
            }

            passos++;
            printf(" -> %lld", n);
        }

        printf("\nNumero de passos: %d\n", passos);
    }

    return 0;
}
