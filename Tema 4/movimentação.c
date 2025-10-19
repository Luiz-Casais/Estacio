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

    return 0;
}
