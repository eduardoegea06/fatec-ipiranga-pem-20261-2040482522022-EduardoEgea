#include <stdio.h>

int main(void) {
    int vetor[6] = {10, 20, 30, 40, 50, 60};
    int *p = vetor;
    int soma = 0;
    int i;

    printf("Elementos e enderecos antes de dobrar:\n");
    for (i = 0; i < 6; i++) {
        printf("Valor: %d | Endereco: %p\n", *(p + i), (void *)(p + i));
        soma += *(p + i);
    }

    printf("\nSoma dos elementos: %d\n", soma);

    for (i = 0; i < 6; i++) {
        *(p + i) = *(p + i) * 2;
    }

    printf("\nElementos depois de dobrar:\n");
    for (i = 0; i < 6; i++) {
        printf("Valor: %d | Endereco: %p\n", *(p + i), (void *)(p + i));
    }

    printf("\nsizeof(int): %zu bytes\n", sizeof(int));
    printf("A diferenca entre enderecos consecutivos corresponde a sizeof(int).\n");

    return 0;
}
