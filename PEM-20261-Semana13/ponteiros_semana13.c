/*
 * Programação Estruturada e Modular
 * Semana 13 - Fundamentos de Ponteiros em Linguagem C
 *
 * Arquivo com a resolução dos exercícios 01 a 12.
 *
 */

#include <stdio.h>
#include <string.h>

/* Exercício 03 e Exercício 12: função auxiliar para trocar inteiros */
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Função auxiliar para imprimir arrays usando ponteiros */
void imprimirArray(const int *arr, int n) {
    const int *p = arr;
    const int *fim = arr + n;

    printf("{ ");
    while (p < fim) {
        printf("%d", *p);
        if (p < fim - 1) {
            printf(", ");
        }
        p++;
    }
    printf(" }\n");
}

/* Exercício 09 */
void inverter(int *arr, int n) {
    int *inicio = arr;
    int *fim = arr + n - 1;

    while (inicio < fim) {
        trocar(inicio, fim);
        inicio++;
        fim--;
    }
}

/* Exercício 11 */
void estatisticas(int *v, int n, int *soma, float *media, int *maior, int *menor) {
    int *p = v;
    int *fim = v + n;

    *soma = 0;
    *maior = *v;
    *menor = *v;

    while (p < fim) {
        *soma += *p;

        if (*p > *maior) {
            *maior = *p;
        }

        if (*p < *menor) {
            *menor = *p;
        }

        p++;
    }

    *media = (float)(*soma) / n;
}

/* Exercício 12 */
void selectionSort(int *arr, int n) {
    int *i;
    int *j;
    int *menor;

    for (i = arr; i < arr + n - 1; i++) {
        menor = i;

        for (j = i + 1; j < arr + n; j++) {
            if (*j < *menor) {
                menor = j;
            }
        }

        if (menor != i) {
            trocar(i, menor);
            printf("Após troca: ");
            imprimirArray(arr, n);
        }
    }
}

int main(void) {
    printf("===== Exercício 01 - Endereço na Memória =====\n");
    int inteiro = 42;
    float real = 3.14f;
    char caractere = 'C';

    int *ptrInteiro = &inteiro;
    float *ptrReal = &real;
    char *ptrCaractere = &caractere;

    printf("int: valor = %d | endereço da variável = %p | endereço no ponteiro = %p | valor via ponteiro = %d\n",
           inteiro, (void *)&inteiro, (void *)ptrInteiro, *ptrInteiro);
    printf("float: valor = %.2f | endereço da variável = %p | endereço no ponteiro = %p | valor via ponteiro = %.2f\n",
           real, (void *)&real, (void *)ptrReal, *ptrReal);
    printf("char: valor = %c | endereço da variável = %p | endereço no ponteiro = %p | valor via ponteiro = %c\n",
           caractere, (void *)&caractere, (void *)ptrCaractere, *ptrCaractere);

    printf("\n===== Exercício 02 - Tamanho de um Ponteiro =====\n");
    int *pInt = NULL;
    float *pFloat = NULL;
    double *pDouble = NULL;
    char *pChar = NULL;

    printf("sizeof(int*) = %zu bytes\n", sizeof(pInt));
    printf("sizeof(float*) = %zu bytes\n", sizeof(pFloat));
    printf("sizeof(double*) = %zu bytes\n", sizeof(pDouble));
    printf("sizeof(char*) = %zu bytes\n", sizeof(pChar));

    /*
     * O tamanho do ponteiro normalmente não varia com o tipo apontado.
     * Ele varia principalmente com a arquitetura do sistema, por exemplo
     * 4 bytes em ambientes de 32 bits e 8 bytes em ambientes de 64 bits.
     * O tipo apontado informa ao compilador quantos bytes devem ser
     * avançados ou recuados na aritmética de ponteiros.
     */

    printf("\n===== Exercício 03 - Troca de Valores via Referência =====\n");
    int a = 10;
    int b = 25;

    printf("Antes: a = %d, b = %d\n", a, b);
    trocar(&a, &b);
    printf("Depois: a = %d, b = %d\n", a, b);

    printf("\n===== Exercício 04 - Mapa de Endereços de um Struct =====\n");
    struct Aluno {
        char nome[50];
        int matricula;
        float media;
    };

    struct Aluno aluno;
    strcpy(aluno.nome, "Ana Silva");
    aluno.matricula = 2026001;
    aluno.media = 8.7f;

    printf("Endereço do struct aluno: %p\n", (void *)&aluno);
    printf("Endereço de aluno.nome: %p\n", (void *)&aluno.nome);
    printf("Endereço de aluno.matricula: %p\n", (void *)&aluno.matricula);
    printf("Endereço de aluno.media: %p\n", (void *)&aluno.media);

    /*
     * Os campos do struct aparecem na memória na ordem em que foram declarados.
     * Porém, os endereços podem não ser perfeitamente consecutivos byte a byte,
     * pois o compilador pode inserir bytes de preenchimento, chamados padding,
     * para alinhar os campos em posições de memória mais eficientes.
     */

    printf("\n===== Exercício 05 - Modificação Indireta =====\n");
    int vetor5[5] = {1, 2, 3, 4, 5};
    int *pVetor5 = vetor5;
    int *fimVetor5 = vetor5 + 5;

    printf("Antes: ");
    imprimirArray(vetor5, 5);

    while (pVetor5 < fimVetor5) {
        *pVetor5 = *pVetor5 * 2;
        pVetor5++;
    }

    printf("Depois: ");
    imprimirArray(vetor5, 5);

    printf("\n===== Exercício 06 - Leitura e Escrita de Struct via Ponteiro =====\n");
    struct Produto {
        char nome[40];
        float preco;
        int estoque;
    };

    struct Produto produto;
    struct Produto *ptrProduto = &produto;

    strcpy((*ptrProduto).nome, "Teclado");
    (*ptrProduto).preco = 149.90f;
    (*ptrProduto).estoque = 12;

    printf("Usando (*ptr).campo:\n");
    printf("Nome: %s | Preço: R$ %.2f | Estoque: %d\n",
           (*ptrProduto).nome, (*ptrProduto).preco, (*ptrProduto).estoque);

    strcpy(ptrProduto->nome, "Mouse");
    ptrProduto->preco = 89.90f;
    ptrProduto->estoque = 20;

    printf("Usando ptr->campo:\n");
    printf("Nome: %s | Preço: R$ %.2f | Estoque: %d\n",
           ptrProduto->nome, ptrProduto->preco, ptrProduto->estoque);

    /*
     * O operador -> é uma forma abreviada e mais legível de escrever
     * (*ponteiro).campo quando trabalhamos com ponteiros para struct.
     */

    printf("\n===== Exercício 07 - Percurso com Incremento =====\n");
    int array8[8] = {14, 7, 22, 3, 9, 18, 1, 11};
    int soma7 = 0;
    int maior7 = *array8;
    int menor7 = *array8;
    int *p7 = array8;

    while (p7 < array8 + 8) {
        printf("Valor: %d | Endereço: %p\n", *p7, (void *)p7);

        soma7 += *p7;

        if (*p7 > maior7) {
            maior7 = *p7;
        }

        if (*p7 < menor7) {
            menor7 = *p7;
        }

        p7++;
    }

    printf("Soma = %d\n", soma7);
    printf("Média = %.2f\n", soma7 / 8.0f);
    printf("Maior = %d\n", maior7);
    printf("Menor = %d\n", menor7);

    printf("\n===== Exercício 08 - Distância entre Ponteiros =====\n");
    double arrayDouble[10] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10};
    double *pTerceiro = arrayDouble + 2;
    double *pOitavo = arrayDouble + 7;

    printf("Diferença entre ponteiros: %td elementos\n", pOitavo - pTerceiro);

    /*
     * A subtração entre dois ponteiros do mesmo tipo retorna a distância
     * em número de elementos, não em número de bytes. Internamente, o
     * compilador considera o tamanho do tipo apontado, neste caso double.
     */

    printf("Elementos do 3º ao 8º:\n");
    while (pTerceiro <= pOitavo) {
        printf("%.2f\n", *pTerceiro);
        pTerceiro++;
    }

    printf("\n===== Exercício 09 - Inversão de Array com Ponteiros =====\n");
    int arrayInverter[7] = {1, 2, 3, 4, 5, 6, 7};

    printf("Antes: ");
    imprimirArray(arrayInverter, 7);
    inverter(arrayInverter, 7);
    printf("Depois: ");
    imprimirArray(arrayInverter, 7);

    printf("\n===== Exercício 10 - Busca em Matriz com Ponteiro =====\n");
    int matriz[4][4] = {
        {3, 8, 12, 4},
        {6, 15, 1, 9},
        {22, 5, 7, 10},
        {11, 2, 13, 14}
    };

    int *pMatriz = &matriz[0][0];
    int *pMaior = pMatriz;
    int posMaior = 0;
    int posAtual = 0;

    while (pMatriz < &matriz[0][0] + 16) {
        if (*pMatriz > *pMaior) {
            pMaior = pMatriz;
            posMaior = posAtual;
        }

        pMatriz++;
        posAtual++;
    }

    printf("Maior valor = %d\n", *pMaior);
    printf("Posição: linha = %d, coluna = %d\n", posMaior / 4, posMaior % 4);

    printf("\n===== Exercício 11 - Função com Múltiplos Retornos =====\n");
    int vEstatisticas[6] = {8, 4, 15, 16, 23, 42};
    int soma11;
    float media11;
    int maior11;
    int menor11;

    estatisticas(vEstatisticas, 6, &soma11, &media11, &maior11, &menor11);

    printf("Array: ");
    imprimirArray(vEstatisticas, 6);
    printf("Soma = %d\n", soma11);
    printf("Média = %.2f\n", media11);
    printf("Maior = %d\n", maior11);
    printf("Menor = %d\n", menor11);

    printf("\n===== Exercício 12 - Ordenação por Seleção com Ponteiros =====\n");
    int arrayOrdenar[8] = {29, 10, 14, 37, 13, 5, 21, 1};

    printf("Antes: ");
    imprimirArray(arrayOrdenar, 8);
    selectionSort(arrayOrdenar, 8);
    printf("Depois: ");
    imprimirArray(arrayOrdenar, 8);

    return 0;
}