#include "stringutil.h"
#include <string.h>

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
