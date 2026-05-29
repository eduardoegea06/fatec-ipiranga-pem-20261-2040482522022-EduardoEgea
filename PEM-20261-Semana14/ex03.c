#include <stdio.h>

int main(void) {
    double peso, altura, imc;

    printf("Digite o peso em kg: ");
    scanf("%lf", &peso);

    printf("Digite a altura em metros: ");
    scanf("%lf", &altura);

    if (peso <= 0 || altura <= 0) {
        printf("Erro: peso e altura devem ser maiores que zero.\n");
    } else {
        imc = peso / (altura * altura);

        printf("IMC: %.2f\n", imc);

        if (imc < 18.5) {
            printf("Classificacao: Abaixo do peso\n");
        } else if (imc < 25.0) {
            printf("Classificacao: Peso normal\n");
        } else if (imc < 30.0) {
            printf("Classificacao: Sobrepeso\n");
        } else {
            printf("Classificacao: Obesidade\n");
        }
    }

    return 0;
}
