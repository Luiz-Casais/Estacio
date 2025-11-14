#include <stdio.h>

#define TAM_TAB 10
#define TAM_NAVIO 3
#define NAVIO 3
#define AGUA 0
#define HABILIDADE 5

int main() {

    // -------------------------------------------------------------
    //  INICIALIZAÇÃO DO TABULEIRO
    // -------------------------------------------------------------
    int tab[TAM_TAB][TAM_TAB];

    // Preenchendo o tabuleiro com água (0)
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            tab[i][j] = AGUA;
        }
    }

    // -------------------------------------------------------------
    // POSICIONAMENTO DOS 4 NAVIOS DO DESAFIO ANTERIOR
    // -------------------------------------------------------------

    // Navios horizontais, verticais e diagonais
    int linha1 = 2, coluna1 = 1; // Horizontal →
    int linha2 = 5, coluna2 = 8; // Vertical ↓
    int linha3 = 0, coluna3 = 0; // Diagonal ↘
    int linha4 = 6, coluna4 = 9; // Diagonal ↙

    // Inserindo navio horizontal
    for (int i = 0; i < TAM_NAVIO; i++) {
        tab[linha1][coluna1 + i] = NAVIO;
    }

    // Inserindo navio vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        tab[linha2 + i][coluna2] = NAVIO;
    }

    // Inserindo navio diagonal ↘
    for (int i = 0; i < TAM_NAVIO; i++) {
        tab[linha3 + i][coluna3 + i] = NAVIO;
    }

    // Inserindo navio diagonal ↙
    for (int i = 0; i < TAM_NAVIO; i++) {
        tab[linha4 + i][coluna4 - i] = NAVIO;
    }

    // -------------------------------------------------------------
    // CRIAÇÃO DAS MATRIZES DE HABILIDADE (5x5)
    // -------------------------------------------------------------

    int h_tam = 5;  // Tamanho fixo das habilidades
    int cone[5][5], cruz[5][5], octa[5][5];

    // -------------------------------------------------------------
    // MATRIZ DO CONE (apontado para baixo)
    // -------------------------------------------------------------
    // A ideia aqui é fazer as linhas de baixo ficarem mais largas.
    for (int i = 0; i < h_tam; i++) {
        for (int j = 0; j < h_tam; j++) {
            if (j >= (h_tam/2 - i) && j <= (h_tam/2 + i))
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // -------------------------------------------------------------
    // MATRIZ DA CRUZ
    // -------------------------------------------------------------
    // A cruz tem linha e coluna centrais preenchidas.
    for (int i = 0; i < h_tam; i++) {
        for (int j = 0; j < h_tam; j++) {
            if (i == h_tam/2 || j == h_tam/2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // -------------------------------------------------------------
    // MATRIZ DO OCTAEDRO (losango)
    // -------------------------------------------------------------
    for (int i = 0; i < h_tam; i++) {
        for (int j = 0; j < h_tam; j++) {
            if (abs(h_tam/2 - i) + abs(h_tam/2 - j) <= h_tam/2)
                octa[i][j] = 1;
            else
                octa[i][j] = 0;
        }
    }

    // -------------------------------------------------------------
    // PONTOS DE ORIGEM DAS HABILIDADES NO TABULEIRO
    // -------------------------------------------------------------
    int origem_cone_l = 4, origem_cone_c = 4;
    int origem_cruz_l = 7, origem_cruz_c = 2;
    int origem_octa_l = 3, origem_octa_c = 8;

    // -------------------------------------------------------------
    // FUNÇÃO DE SOBREPOR UMA HABILIDADE NO TABULEIRO
    // -------------------------------------------------------------
    // Para centralizar, subtraio metade do tamanho
    int half = h_tam / 2;

    // Sobreposição CONE
    for (int i = 0; i < h_tam; i++) {
        for (int j = 0; j < h_tam; j++) {

            int linha = origem_cone_l + (i - half);
            int coluna = origem_cone_c + (j - half);

            // Verificação de limites
            if (linha >= 0 && linha < TAM_TAB && coluna >= 0 && coluna < TAM_TAB) {
                if (cone[i][j] == 1 && tab[linha][coluna] == AGUA) {
                    tab[linha][coluna] = HABILIDADE;
                }
            }
        }
    }

    // Sobreposição CRUZ
    for (int i = 0; i < h_tam; i++) {
        for (int j = 0; j < h_tam; j++) {

            int linha = origem_cruz_l + (i - half);
            int coluna = origem_cruz_c + (j - half);

            if (linha >= 0 && linha < TAM_TAB && coluna >= 0 && coluna < TAM_TAB) {
                if (cruz[i][j] == 1 && tab[linha][coluna] == AGUA) {
                    tab[linha][coluna] = HABILIDADE;
                }
            }
        }
    }

    // Sobreposição OCTAEDRO
    for (int i = 0; i < h_tam; i++) {
        for (int j = 0; j < h_tam; j++) {

            int linha = origem_octa_l + (i - half);
            int coluna = origem_octa_c + (j - half);

            if (linha >= 0 && linha < TAM_TAB && coluna >= 0 && coluna < TAM_TAB) {
                if (octa[i][j] == 1 && tab[linha][coluna] == AGUA) {
                    tab[linha][coluna] = HABILIDADE;
                }
            }
        }
    }

    // -------------------------------------------------------------
    // EXIBIÇÃO FINAL DO TABULEIRO
    // -------------------------------------------------------------
    printf("\n=========== TABULEIRO FINAL COM NAVIOS E HABILIDADES ===========\n\n");

    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {

            if (tab[i][j] == AGUA)
                printf("0 ");
            else if (tab[i][j] == NAVIO)
                printf("3 ");
            else if (tab[i][j] == HABILIDADE)
                printf("5 ");
        }
        printf("\n");
    }

    return 0;
}
