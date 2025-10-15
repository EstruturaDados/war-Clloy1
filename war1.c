#include <stdio.h>
#include <string.h>

#define MAX_TERRITORIOS 5

// Definição da estrutura Territorio
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

int main() {
    // Declaração do vetor de structs
    Territorio mapa[MAX_TERRITORIOS];
    int i;

    printf("===== CADASTRO DE TERRITÓRIOS =====\n");
    
    // Cadastro dos 5 territórios
    for (i = 0; i < MAX_TERRITORIOS; i++) {
        printf("\nTerritório %d:\n", i + 1);
        printf("Nome: ");
        scanf("%29s", mapa[i].nome); // Leitura do nome
        
        printf("Cor: ");
        scanf("%9s", mapa[i].cor);   // Leitura da cor
        
        printf("Tropas: ");
        scanf("%d", &mapa[i].tropas); // Leitura das tropas
    }

    // Exibição dos dados
    printf("\n===== DADOS REGISTRADOS =====\n");
    for (i = 0; i < MAX_TERRITORIOS; i++) {
        printf("--- %s ---\n", mapa[i].nome);
        printf("Cor: %s | Tropas: %d\n", mapa[i].cor, mapa[i].tropas);
    }

    return 0;
}