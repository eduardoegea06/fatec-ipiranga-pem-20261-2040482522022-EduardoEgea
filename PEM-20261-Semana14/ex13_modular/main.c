#include <stdio.h>
#include "stringutil.h"

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
