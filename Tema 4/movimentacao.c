#include <stdio.h>
/* ===============================================
Função recursiva: Movimento da Torre
Anda "n" casas para a direita.
===============================================*/
void moverTorre(int casas) {
    if (casas <= 0) return; // condição de parada
    printf("Direita\n");
    moverTorre(casas - 1); // chamada recursiva
}


/* ===============================================
Função recursiva e com loops aninhados: Movimento do Bispo
O bispo se move em diagonal (Cima + Direita)
O loop externo representa o movimento vertical (Cima)
O loop interno representa o movimento horizontal (Direita)
===============================================*/
void moverBispo(int vertical, int horizontal) {
    if (vertical <= 0) return; // condição de parada

    // Loop externo (vertical)
    printf("Cima\n");

    // Loop interno (horizontal)
    for (int j = 0; j < horizontal; j++) {
        printf("Direita\n");
    }

    // chamada recursiva (sobe mais uma "diagonal")
    moverBispo(vertical - 1, horizontal);
}


/* ===============================================
Função recursiva: Movimento da Rainha
Anda "n" casas para a esquerda.
===============================================*/
void moverRainha(int casas) {
    if (casas <= 0) return; // condição de parada
    printf("Esquerda\n");
    moverRainha(casas - 1); // chamada recursiva
}


/* ===============================================
Movimento complexo do Cavalo
Agora o Cavalo anda em "L" → duas casas para CIMA e uma para a DIREITA
Usa loops aninhados com múltiplas variáveis e controle com break/continue.
===============================================*/
void moverCavalo() {
    int movimentosCima = 2;
    int movimentosDireita = 1;

    printf("Movimento do Cavalo:\n");

    // Loop externo → movimento vertical (para cima)
    for (int i = 1; i <= movimentosCima; i++) {
        printf("Cima\n");

        // Loop interno → controla quando o cavalo deve virar à direita
        for (int j = 1; j <= movimentosDireita; j++) {
            if (i < movimentosCima) {
                // ainda não chegou na altura certa para virar
                continue;
            }
            // quando chega na última subida, vai pra direita
            printf("Direita\n");
            break; // encerra o loop interno após virar
        }
    }
}

/*===============================================
  Função principal
=============================================== */
int main() {
    // ===== MOVIMENTO DA TORRE =====
    printf("Movimento da Torre:\n");
    moverTorre(5); // anda 5 casas para a direita

    // ===== MOVIMENTO DO BISPO =====
    printf("\nMovimento do Bispo:\n");
    moverBispo(3, 1); // sobe 3 vezes, movendo 1 casa pra direita a cada subida

    // ===== MOVIMENTO DA RAINHA =====
    printf("\nMovimento da Rainha:\n");
    moverRainha(8); // anda 8 casas para a esquerda

    // ===== MOVIMENTO DO CAVALO =====
    printf("\n");
    moverCavalo(); // duas casas para cima e uma para a direita

    return 0;
}
