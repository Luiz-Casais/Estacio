#include <stdio.h>

int main() {
    // Simulando o movimento das peças de xadrez usando estruturas de repetição

    // Torre → anda 5 casas para a direita (usando for)
    int i;
    printf("Movimento da Torre:\n");
    for(i = 1; i <= 5; i++) {
        printf("Direita\n");
    }

    // Bispo → anda 5 casas na diagonal (cima e direita) (usando while)
    int j = 1;
    printf("\nMovimento do Bispo:\n");
    while(j <= 5) {
        printf("Cima, Direita\n");
        j++;
    }

    // Rainha → anda 8 casas para a esquerda (usando do-while)
    int k = 1;
    printf("\nMovimento da Rainha:\n");
    do {
        printf("Esquerda\n");
        k++;
    } while(k <= 8);

    // ===============================================
    // Cavalo → anda duas casas para baixo e uma para a esquerda (usando loops aninhados)
    // ===============================================
    int movimentosBaixo = 2;
    int movimentosEsquerda = 1;
    int contadorBaixo, contadorEsquerda;

    printf("\nMovimento do Cavalo:\n");

    // Loop externo (for): move o cavalo para baixo
    for(contadorBaixo = 1; contadorBaixo <= movimentosBaixo; contadorBaixo++) {
        printf("Baixo\n");

        // Loop interno (while): move o cavalo para a esquerda após descer
        contadorEsquerda = 0;
        while(contadorEsquerda < movimentosEsquerda && contadorBaixo == movimentosBaixo) {
            printf("Esquerda\n");
            contadorEsquerda++;
        }
    }

    // O Cavalo se move em "L":
    // - 2 casas para baixo (controladas pelo for)
    // - 1 casa para a esquerda (controlada pelo while dentro do for)
    // Isso garante o uso de loops aninhados, como solicitado no desafio.

    return 0;
}
