#include <stdio.h>

int main(void) {
    char resposta;
    int numero;
    int multiplicador;

    do {
        for (numero = 1; numero <= 10; numero++) {
            printf("\nTabuada do %d\n", numero);
            multiplicador = 1;

            while (multiplicador <= 10) {
                printf("%2d x %2d = %3d\n", numero, multiplicador, numero * multiplicador);
                multiplicador++;
            }

            printf("\nDeseja continuar para a proxima tabuada? (S/N): ");
            scanf(" %c", &resposta);

            if (resposta == 'N' || resposta == 'n') {
                break;
            }
        }
    } while (resposta != 'N' && resposta != 'n');

    printf("Programa encerrado.\n");

    return 0;
}
