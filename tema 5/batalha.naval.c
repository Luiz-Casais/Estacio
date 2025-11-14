#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int i, j;

    // Inicializa o tabuleiro com 0 (água)
    for (i = 0; i < TAM_TABULEIRO; i++) {
        for (j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Define os navios
    int navioHorizontal[TAM_NAVIO] = {3, 3, 3};
    int navioVertical[TAM_NAVIO] = {3, 3, 3};

    // Coordenadas iniciais dos navios
    int linhaHorizontal = 4, colunaHorizontal = 2; // navio horizontal começa na linha 4, coluna 2
    int linhaVertical = 1, colunaVertical = 7;     // navio vertical começa na linha 1, coluna 7

    // Validação para garantir que os navios cabem no tabuleiro
    if (colunaHorizontal + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: o navio horizontal ultrapassa o limite do tabuleiro!\n");
        return 1;
    }

    if (linhaVertical + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: o navio vertical ultrapassa o limite do tabuleiro!\n");
        return 1;
    }

    // Posiciona o navio horizontal no tabuleiro
    for (i = 0; i < TAM_NAVIO; i++) {
        // Verifica se já existe um navio na posição (para evitar sobreposição)
        if (tabuleiro[linhaHorizontal][colunaHorizontal + i] == 3) {
            printf("Erro: sobreposição detectada no navio horizontal!\n");
            return 1;
        }
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];
    }

    // Posiciona o navio vertical no tabuleiro
    for (i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linhaVertical + i][colunaVertical] == 3) {
            printf("Erro: sobreposição detectada no navio vertical!\n");
            return 1;
        }
        tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
    }

    // Exibe o tabuleiro final
    printf("\n=== TABULEIRO DO BATALHA NAVAL ===\n\n");
    for (i = 0; i < TAM_TABULEIRO; i++) {
        for (j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}