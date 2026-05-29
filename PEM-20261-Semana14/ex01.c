#include <stdio.h>

int main(void) {
    double n1, n2, n3;
    int p1, p2, p3;
    double media;

    printf("Digite a primeira nota: ");
    scanf("%lf", &n1);

    printf("Digite o peso da primeira nota: ");
    scanf("%d", &p1);

    printf("Digite a segunda nota: ");
    scanf("%lf", &n2);

    printf("Digite o peso da segunda nota: ");
    scanf("%d", &p2);

    printf("Digite a terceira nota: ");
    scanf("%lf", &n3);

    printf("Digite o peso da terceira nota: ");
    scanf("%d", &p3);

    if (p1 + p2 + p3 == 0) {
        printf("Erro: a soma dos pesos nao pode ser zero.\n");
        return 0;
    }

    media = (n1 * p1 + n2 * p2 + n3 * p3) / (p1 + p2 + p3);

    printf("\nMedia ponderada: %.2f\n", media);
    printf("Tamanho de double: %zu bytes\n", sizeof(double));
    printf("Tamanho de int: %zu bytes\n", sizeof(int));

    return 0;
}
