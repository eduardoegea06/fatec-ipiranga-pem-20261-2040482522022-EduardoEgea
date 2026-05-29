#include <stdio.h>

int main(void) {
    double a, b, c;
    double maior, lado1, lado2;
    double maiorQuadrado, somaQuadrados;

    printf("Digite o primeiro lado: ");
    scanf("%lf", &a);

    printf("Digite o segundo lado: ");
    scanf("%lf", &b);

    printf("Digite o terceiro lado: ");
    scanf("%lf", &c);

    if (a <= 0 || b <= 0 || c <= 0) {
        printf("Erro: todos os lados devem ser positivos.\n");
    } else if (a + b <= c || a + c <= b || b + c <= a) {
        /* Pela desigualdade triangular, a soma de dois lados deve ser maior que o terceiro. */
        printf("Os valores nao formam um triangulo valido.\n");
    } else {
        printf("Os valores formam um triangulo valido.\n");

        if (a == b && b == c) {
            /* Tres lados iguais formam um triangulo equilatero. */
            printf("Classificacao pelos lados: Equilatero\n");
        } else if (a == b || a == c || b == c) {
            /* Dois lados iguais formam um triangulo isosceles. */
            printf("Classificacao pelos lados: Isosceles\n");
        } else {
            /* Tres lados diferentes formam um triangulo escaleno. */
            printf("Classificacao pelos lados: Escaleno\n");
        }

        maior = a;
        lado1 = b;
        lado2 = c;

        if (b > maior) {
            maior = b;
            lado1 = a;
            lado2 = c;
        } else if (c > maior) {
            maior = c;
            lado1 = a;
            lado2 = b;
        }

        maiorQuadrado = maior * maior;
        somaQuadrados = lado1 * lado1 + lado2 * lado2;

        if (maiorQuadrado == somaQuadrados) {
            /* Se o quadrado do maior lado e igual a soma dos outros, e retangulo. */
            printf("Classificacao pelos angulos: Retangulo\n");
        } else if (maiorQuadrado > somaQuadrados) {
            /* Se o quadrado do maior lado e maior que a soma dos outros, e obtusangulo. */
            printf("Classificacao pelos angulos: Obtusangulo\n");
        } else {
            /* Se o quadrado do maior lado e menor que a soma dos outros, e acutangulo. */
            printf("Classificacao pelos angulos: Acutangulo\n");
        }
    }

    return 0;
}
