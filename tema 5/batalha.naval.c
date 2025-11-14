#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int i, j;

    // 1️⃣ Inicializa o tabuleiro com 0 (água)
    for (i = 0; i < TAM_TABULEIRO; i++) {
        for (j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // 2️⃣ Declaração dos quatro navios
    // Todos têm tamanho fixo = 3
    int navio1[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO}; // Horizontal
    int navio2[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO}; // Vertical
    int navio3[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO}; // Diagonal ↘
    int navio4[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO}; // Diagonal ↙

    // 3️⃣ Coordenadas iniciais dos navios
    int linha1 = 2, coluna1 = 1; // Horizontal
    int linha2 = 5, coluna2 = 8; // Vertical
    int linha3 = 0, coluna3 = 0; // Diagonal ↘
    int linha4 = 6, coluna4 = 9; // Diagonal ↙ (descendo à esquerda)

    // 4️⃣ Validação de limites para todos os navios
    // Horizontal
    if (coluna1 + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: navio horizontal fora dos limites!\n");
        return 1;
    }

    // Vertical
    if (linha2 + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: navio vertical fora dos limites!\n");
        return 1;
    }

    // Diagonal ↘ (linha e coluna crescem)
    if (linha3 + TAM_NAVIO > TAM_TABULEIRO || coluna3 + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: navio diagonal ↘ fora dos limites!\n");
        return 1;
    }

    // Diagonal ↙ (linha cresce, coluna diminui)
    if (linha4 + TAM_NAVIO > TAM_TABULEIRO || coluna4 - (TAM_NAVIO - 1) < 0) {
        printf("Erro: navio diagonal ↙ fora dos limites!\n");
        return 1;
    }

    // 5️⃣ Posicionamento dos navios com validação de sobreposição

    // Horizontal →
    for (i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha1][coluna1 + i] == NAVIO) {
            printf("Erro: sobreposição detectada no navio horizontal!\n");
            return 1;
        }
        tabuleiro[linha1][coluna1 + i] = navio1[i];
    }

    // Vertical ↓
    for (i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha2 + i][coluna2] == NAVIO) {
            printf("Erro: sobreposição detectada no navio vertical!\n");
            return 1;
        }
        tabuleiro[linha2 + i][coluna2] = navio2[i];
    }

    // Diagonal ↘
    for (i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha3 + i][coluna3 + i] == NAVIO) {
            printf("Erro: sobreposição detectada no navio diagonal ↘!\n");
            return 1;
        }
        tabuleiro[linha3 + i][coluna3 + i] = navio3[i];
    }

    // Diagonal ↙
    for (i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha4 + i][coluna4 - i] == NAVIO) {
            printf("Erro: sobreposição detectada no navio diagonal ↙!\n");
            return 1;
        }
        tabuleiro[linha4 + i][coluna4 - i] = navio4[i];
    }

    // 6️⃣ Exibição do tabuleiro final
    printf("\n=== TABULEIRO COMPLETO DO BATALHA NAVAL ===\n\n");

    for (i = 0; i < TAM_TABULEIRO; i++) {
        for (j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
