#include <stdio.h>

int mdc(int a, int b);
long long potenciaInteira(int base, int expoente);
int ePrimo(int n);
void decimalParaBinario(int n, char binario[]);

int main(void) {
    int opcao;
    int a, b, n;
    char binario[65];

    do {
        printf("\n===== CALCULADORA MODULAR =====\n");
        printf("1 - Maximo Divisor Comum\n");
        printf("2 - Potencia inteira\n");
        printf("3 - Verificar numero primo\n");
        printf("4 - Converter decimal para binario\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite dois numeros: ");
                scanf("%d %d", &a, &b);
                printf("MDC: %d\n", mdc(a, b));
                break;

            case 2:
                printf("Digite a base e o expoente: ");
                scanf("%d %d", &a, &b);
                if (b < 0) {
                    printf("Erro: use expoente inteiro nao negativo.\n");
                } else {
                    printf("Resultado: %lld\n", potenciaInteira(a, b));
                }
                break;

            case 3:
                printf("Digite um numero: ");
                scanf("%d", &n);
                printf("%s\n", ePrimo(n) ? "E primo" : "Nao e primo");
                break;

            case 4:
                printf("Digite um numero decimal nao negativo: ");
                scanf("%d", &n);
                if (n < 0) {
                    printf("Erro: informe um numero nao negativo.\n");
                } else {
                    decimalParaBinario(n, binario);
                    printf("Binario: %s\n", binario);
                }
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}

/*
   Funcao: mdc
   Parametros: dois numeros inteiros.
   Retorno: maximo divisor comum entre os dois numeros.
   Complexidade: O(log n), usando o algoritmo de Euclides.
*/
int mdc(int a, int b) {
    int resto;

    if (a < 0) {
        a = -a;
    }
    if (b < 0) {
        b = -b;
    }

    while (b != 0) {
        resto = a % b;
        a = b;
        b = resto;
    }

    return a;
}

/*
   Funcao: potenciaInteira
   Parametros: base e expoente inteiro nao negativo.
   Retorno: base elevada ao expoente.
   Complexidade: O(n), pois multiplica a base expoente vezes.
*/
long long potenciaInteira(int base, int expoente) {
    long long resultado = 1;
    int i;

    for (i = 0; i < expoente; i++) {
        resultado *= base;
    }

    return resultado;
}

/*
   Funcao: ePrimo
   Parametros: numero inteiro.
   Retorno: 1 se for primo, 0 caso contrario.
   Complexidade: O(n), verificando divisores de 2 ate n - 1.
*/
int ePrimo(int n) {
    int i;

    if (n <= 1) {
        return 0;
    }

    for (i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

/*
   Funcao: decimalParaBinario
   Parametros: numero decimal e vetor de caracteres para armazenar o resultado.
   Retorno: nao retorna valor, pois grava a string no parametro binario.
   Complexidade: O(log n), pois divide o numero por 2 sucessivamente.
*/
void decimalParaBinario(int n, char binario[]) {
    int i = 0;
    int j;
    char temp;

    if (n == 0) {
        binario[0] = '0';
        binario[1] = '\0';
        return;
    }

    while (n > 0) {
        binario[i] = (char)((n % 2) + '0');
        n = n / 2;
        i++;
    }
    binario[i] = '\0';

    for (j = 0; j < i / 2; j++) {
        temp = binario[j];
        binario[j] = binario[i - 1 - j];
        binario[i - 1 - j] = temp;
    }
}
