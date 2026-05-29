#include <stdio.h>

int main(void) {
    int centimetros;
    float metros;
    double quilometros;
    double milhas;

    /*
       int foi usado para armazenar centimetros porque o enunciado informa
       limite maximo de 2.147.483.647, que corresponde ao limite comum de int.
       float foi usado para metros por ser uma conversao simples.
       double foi usado para quilometros e milhas para maior precisao decimal.
    */

    printf("Digite a distancia em centimetros: ");
    scanf("%d", &centimetros);

    if (centimetros <= 0) {
        printf("Erro: informe um valor positivo.\n");
    } else {
        metros = centimetros / 100.0f;
        quilometros = centimetros / 100000.0;
        milhas = quilometros / 1.60934;

        printf("Metros: %.2f m\n", metros);
        printf("Quilometros: %.6f km\n", quilometros);
        printf("Milhas: %.6f mi\n", milhas);
    }

    return 0;
}
