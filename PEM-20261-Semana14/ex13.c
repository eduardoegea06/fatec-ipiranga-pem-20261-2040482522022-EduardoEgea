#include <stdio.h>
#include <string.h>

int contaVogais(char *s);
void inverteCString(char *s);
int ePalindromo(char *s);

int main(void) {
    char texto1[100] = "arara";
    char texto2[100] = "Programacao";

    printf("Texto 1: %s\n", texto1);
    printf("Vogais no texto 1: %d\n", contaVogais(texto1));
    printf("E palindromo? %s\n", ePalindromo(texto1) ? "Sim" : "Nao");
    inverteCString(texto1);
    printf("Texto 1 invertido: %s\n", texto1);

    printf("\nTexto 2: %s\n", texto2);
    printf("Vogais no texto 2: %d\n", contaVogais(texto2));
    printf("E palindromo? %s\n", ePalindromo(texto2) ? "Sim" : "Nao");
    inverteCString(texto2);
    printf("Texto 2 invertido: %s\n", texto2);

    return 0;
}

int contaVogais(char *s) {
    int i;
    int contador = 0;

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
            s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            contador++;
        }
    }

    return contador;
}

void inverteCString(char *s) {
    int inicio = 0;
    int fim = (int)strlen(s) - 1;
    char temp;

    while (inicio < fim) {
        temp = s[inicio];
        s[inicio] = s[fim];
        s[fim] = temp;
        inicio++;
        fim--;
    }
}

int ePalindromo(char *s) {
    int inicio = 0;
    int fim = (int)strlen(s) - 1;

    while (inicio < fim) {
        if (s[inicio] != s[fim]) {
            return 0;
        }
        inicio++;
        fim--;
    }

    return 1;
}
