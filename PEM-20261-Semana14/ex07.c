#include <stdio.h>

int main(void) {
    float valores[10];
    float soma = 0.0f;
    float media;
    float maior;
    float menor;
    float somaAcimaMedia = 0.0f;
    int i;

    for (i = 0; i < 10; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%f", &valores[i]);
        soma += valores[i];

        if (i == 0) {
            maior = valores[i];
            menor = valores[i];
        } else {
            if (valores[i] > maior) {
                maior = valores[i];
            }
            if (valores[i] < menor) {
                menor = valores[i];
            }
        }
    }

    media = soma / 10.0f;

    for (i = 0; i < 10; i++) {
        if (valores[i] > media) {
            somaAcimaMedia += valores[i];
        }
    }

    printf("\nMedia aritmetica: %.2f\n", media);
    printf("Maior valor: %.2f\n", maior);
    printf("Menor valor: %.2f\n", menor);
    printf("Soma dos valores acima da media: %.2f\n", somaAcimaMedia);

    return 0;
}
