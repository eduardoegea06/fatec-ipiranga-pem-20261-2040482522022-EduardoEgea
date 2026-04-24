/*----------------------------------------------------------*
 * Nome: Eduardo Martinez Ferreira Egea                     *
 *                      FATEC Ipiranga                      *
 * Disciplina: Programacao Estruturada e Modular            *
 *          Prof. Veríssimo                                 *
 *----------------------------------------------------------*
 * Objetivo: Busca em profundidade Iterativa                *
 * Data - 24/04/2026                                        *
 * Codigo Novo 2 - Conversao Recursivo para Iterativo       *
 *----------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_PASTAS 50
#define LIMITE_ALERTA 300.0

typedef struct {
    char nome[50];
    float tamanho_proprio;
    float tamanho_total;
    int subpastas_indices[10];
    int qtd_sub;
} Pasta;

Pasta drive[MAX_PASTAS];

void processarHierarquia(int raiz, int limite_profundidade) {
    int pilha1[MAX_PASTAS];
    int nivel1[MAX_PASTAS];
    int topo1 = -1;

    int pilha2[MAX_PASTAS];
    int nivel2[MAX_PASTAS];
    int topo2 = -1;

    topo1++;
    pilha1[topo1] = raiz;
    nivel1[topo1] = 0;

    while (topo1 >= 0) {
        int index = pilha1[topo1];
        int nivel = nivel1[topo1];
        topo1--;

        if (nivel > limite_profundidade) continue;

        topo2++;
        pilha2[topo2] = index;
        nivel2[topo2] = nivel;

        for (int i = 0; i < drive[index].qtd_sub; i++) {
            topo1++;
            pilha1[topo1] = drive[index].subpastas_indices[i];
            nivel1[topo1] = nivel + 1;
        }
    }

    while (topo2 >= 0) {
        int index = pilha2[topo2];
        int nivel = nivel2[topo2];
        topo2--;

        drive[index].tamanho_total = drive[index].tamanho_proprio;

        for (int i = 0; i < drive[index].qtd_sub; i++) {
            int filho = drive[index].subpastas_indices[i];
            drive[index].tamanho_total += drive[filho].tamanho_total;
        }

        for (int k = 0; k < nivel; k++) printf("  ");
        printf("|-- %s [%.2f GB]", drive[index].nome, drive[index].tamanho_total);

        if (drive[index].tamanho_total > LIMITE_ALERTA) {
            printf(" [!] ALERTA: GARGALO DETECTADO");
        }
        printf("\n");
    }
}

int main() {
    strcpy(drive[0].nome, "RAIZ");
    drive[0].tamanho_proprio = 10.0;
    drive[0].qtd_sub = 2;
    drive[0].subpastas_indices[0] = 1;
    drive[0].subpastas_indices[1] = 2;

    strcpy(drive[1].nome, "Projetos_TI");
    drive[1].tamanho_proprio = 50.0;
    drive[1].qtd_sub = 1;
    drive[1].subpastas_indices[0] = 3;

    strcpy(drive[2].nome, "Backups_Antigos");
    drive[2].tamanho_proprio = 350.0;
    drive[2].qtd_sub = 0;

    strcpy(drive[3].nome, "Videos_Aulas");
    drive[3].tamanho_proprio = 280.0;
    drive[3].qtd_sub = 0;

    int limite;
    printf("Defina o limite de profundidade do mergulho: ");
    scanf("%d", &limite);

    clock_t t;
    t = clock();

    printf("\n--- RELATORIO DE HIERARQUIA (ITERATIVO) ---\n");
    processarHierarquia(0, limite);
    printf("-------------------------------------------\n");

    t = clock() - t;
    double tempo_execucao = ((double)t) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %f segundos\n", tempo_execucao);

    return 0;
}
