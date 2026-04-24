/*----------------------------------------------------------*
 * Nome: Eduardo Martinez Ferreira Egea                     *
 *                      FATEC Ipiranga                      *
 * Disciplina: Programacao Estruturada e Modular            *
 *          Prof. Veríssimo                                 *
 *----------------------------------------------------------*
 * Objetivo: Busca em profundidade com Ponteiros            *
 * Data - 24/04/2026                                        *
 * Codigo Novo 1 - Refatoracao com Ponteiros                *
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

float processarHierarquia(Pasta *bd, int index, int nivel_atual, int limite_profundidade) {
    if (index == -1 || nivel_atual > limite_profundidade) {
        return 0;
    }

    Pasta *atual = &bd[index];
    atual->tamanho_total = atual->tamanho_proprio;

    for (int i = 0; i < atual->qtd_sub; i++) {
        int *filho = &atual->subpastas_indices[i];
        atual->tamanho_total += processarHierarquia(bd, *filho, nivel_atual + 1, limite_profundidade);
    }

    for (int i = 0; i < nivel_atual; i++) printf("  ");
    printf("|-- %s [%.2f GB]", atual->nome, atual->tamanho_total);

    if (atual->tamanho_total > LIMITE_ALERTA) {
        printf(" [!] ALERTA: GARGALO DETECTADO");
    }
    printf("\n");

    return atual->tamanho_total;
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

    printf("\n--- RELATORIO DE HIERARQUIA (COM PONTEIROS) ---\n");
    processarHierarquia(drive, 0, 0, limite);
    printf("-----------------------------------------------\n");

    t = clock() - t;
    double tempo_execucao = ((double)t) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %f segundos\n", tempo_execucao);

    return 0;
}
