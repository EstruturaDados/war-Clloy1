#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Estrutura Principal ---
typedef struct {
    char nome[20];
    int tropas;
    int id_jogador;
} Territorio;

// --- 1. Alocação Dinâmica e Inicialização ---
Territorio* criar_e_inicializar_territorio(const char *nome, int tropas, int id_jogador) {
    // Usa malloc para alocar memória dinâmica
    Territorio *t = (Territorio *)malloc(sizeof(Territorio));
    
    if (t != NULL) {
        // Inicializa os campos através do ponteiro
        strncpy(t->nome, nome, 19);
        t->tropas = tropas;
        t->id_jogador = id_jogador;
    }
    return t; // Retorna o ponteiro para a memória alocada
}

// --- 2. Função com Ponteiros (Passagem por Referência) ---
void simular_ataque(Territorio *atacante, Territorio *defensor) {
    // Lógica que MODIFICA os structs originais via ponteiro (->)
    printf("\n[Ataque]: %s (J%d, %d tropas) ataca %s (J%d, %d tropas).\n", 
           atacante->nome, atacante->id_jogador, atacante->tropas,
           defensor->nome, defensor->id_jogador, defensor->tropas);
           
    if (atacante->tropas > defensor->tropas) {
        // Atacante vence
        defensor->id_jogador = atacante->id_jogador; // Conquista
        defensor->tropas = 1; 
        atacante->tropas -= 1; 
        printf(" -> CONQUISTADO! %s agora pertence ao J%d.\n", defensor->nome, defensor->id_jogador);
    } else {
        atacante->tropas -= 1; // Perde 1 tropa
        printf(" -> DEFESA BEM-SUCEDIDA! %s perdeu 1 tropa.\n", atacante->nome);
    }
}

// --- 3. Função de Liberação de Memória ---
void liberar_territorio(Territorio *t) {
    if (t != NULL) {
        free(t); // Libera a memória alocada com malloc
    }
}

int main() {
    // Criação de dois territórios na memória dinâmica (heap)
    Territorio *brasil = criar_e_inicializar_territorio("Brasil", 5, 1);
    Territorio *argentina = criar_e_inicializar_territorio("Argentina", 3, 2);

    if (brasil == NULL || argentina == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return 1;
    }

    // Demonstração da lógica de ataque usando ponteiros
    simular_ataque(brasil, argentina);

    // Exibição do estado final
    printf("\n--- Estado Final ---\n");
    printf("%s: Dono J%d, Tropas %d\n", brasil->nome, brasil->id_jogador, brasil->tropas);
    printf("%s: Dono J%d, Tropas %d\n", argentina->nome, argentina->id_jogador, argentina->tropas);
    
    // Liberação de Memória (essencial para execução correta)
    liberar_territorio(brasil);
    liberar_territorio(argentina);

    printf("\nExecucao concluida corretamente.\n");
    return 0;
}