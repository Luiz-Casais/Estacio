#include <stdio.h>

int main() {
    // Dados das cartas
    char codigo_1[5], codigo_2[5];
    char estado_1[30], estado_2[30];
    char cidade_1[32], cidade_2[32];
    unsigned long int populacao_1, populacao_2;
    float area_1, area_2;
    float pib_1, pib_2;
    int pontos_turisticos_1, pontos_turisticos_2;
    float densidade_1, densidade_2;
    float pib_per_capital_1, pib_per_capital_2;

    printf("===== PRIMEIRA CARTA =====\n");
    printf("Código: "); scanf("%s", codigo_1);
    printf("Estado: "); scanf(" %[^\n]", estado_1);
    printf("Cidade: "); scanf(" %[^\n]", cidade_1);
    printf("População: "); scanf("%lu", &populacao_1);
    printf("Área: "); scanf("%f", &area_1);
    printf("PIB (em bilhões): "); scanf("%f", &pib_1);
    printf("Pontos turísticos: "); scanf("%d", &pontos_turisticos_1);

    densidade_1 = populacao_1 / area_1;
    pib_per_capital_1 = pib_1 * 1000 / populacao_1;

    printf("\n===== SEGUNDA CARTA =====\n");
    printf("Código: "); scanf("%s", codigo_2);
    printf("Estado: "); scanf(" %[^\n]", estado_2);
    printf("Cidade: "); scanf(" %[^\n]", cidade_2);
    printf("População: "); scanf("%lu", &populacao_2);
    printf("Área: "); scanf("%f", &area_2);
    printf("PIB (em bilhões): "); scanf("%f", &pib_2);
    printf("Pontos turísticos: "); scanf("%d", &pontos_turisticos_2);

    densidade_2 = populacao_2 / area_2;
    pib_per_capital_2 = pib_2 * 1000 / populacao_2;

    // Super poder
    float super_poder_1 = populacao_1 + area_1 + pib_1 + pontos_turisticos_1 + pib_per_capital_1 + (1 / densidade_1);
    float super_poder_2 = populacao_2 + area_2 + pib_2 + pontos_turisticos_2 + pib_per_capital_2 + (1 / densidade_2);

    // Placar
    int pontos_c1 = 0, pontos_c2 = 0;

    int atributo1 = 0, atributo2 = 0;

    // Menu primeiro atributo
    printf("\nEscolha o primeiro atributo para comparar:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos turísticos\n5 - PIB per capita\n6 - Densidade demográfica\n");
    printf("Opção: "); scanf("%d", &atributo1);

    // Menu segundo atributo (dinâmico: remove o primeiro escolhido)
    printf("\nEscolha o segundo atributo para comparar (diferente do primeiro):\n");
    if(atributo1 != 1) printf("1 - População\n");
    if(atributo1 != 2) printf("2 - Área\n");
    if(atributo1 != 3) printf("3 - PIB\n");
    if(atributo1 != 4) printf("4 - Pontos turísticos\n");
    if(atributo1 != 5) printf("5 - PIB per capita\n");
    if(atributo1 != 6) printf("6 - Densidade demográfica\n");
    printf("Opção: "); scanf("%d", &atributo2);

    printf("\n===== RESULTADO DA COMPARAÇÃO =====\n");

    // Comparação do primeiro atributo
    switch(atributo1) {
        case 1:
            printf("População: Carta 1 = %lu, Carta 2 = %lu\n", populacao_1, populacao_2);
            if(populacao_1 > populacao_2) { printf("Vencedor: Carta 1\n"); pontos_c1++; }
            else if(populacao_2 > populacao_1) { printf("Vencedor: Carta 2\n"); pontos_c2++; }
            else printf("Empate!\n");
            break;
        case 2:
            printf("Área: Carta 1 = %.2f, Carta 2 = %.2f\n", area_1, area_2);
            if(area_1 > area_2) { printf("Vencedor: Carta 1\n"); pontos_c1++; }
            else if(area_2 > area_1) { printf("Vencedor: Carta 2\n"); pontos_c2++; }
            else printf("Empate!\n");
            break;
        case 3:
            printf("PIB: Carta 1 = %.2f, Carta 2 = %.2f\n", pib_1, pib_2);
            if(pib_1 > pib_2) { printf("Vencedor: Carta 1\n"); pontos_c1++; }
            else if(pib_2 > pib_1) { printf("Vencedor: Carta 2\n"); pontos_c2++; }
            else printf("Empate!\n");
            break;
        case 4:
            printf("Pontos turísticos: Carta 1 = %d, Carta 2 = %d\n", pontos_turisticos_1, pontos_turisticos_2);
            if(pontos_turisticos_1 > pontos_turisticos_2) { printf("Vencedor: Carta 1\n"); pontos_c1++; }
            else if(pontos_turisticos_2 > pontos_turisticos_1) { printf("Vencedor: Carta 2\n"); pontos_c2++; }
            else printf("Empate!\n");
            break;
        case 5:
            printf("PIB per capita: Carta 1 = %.2f, Carta 2 = %.2f\n", pib_per_capital_1, pib_per_capital_2);
            if(pib_per_capital_1 > pib_per_capital_2) { printf("Vencedor: Carta 1\n"); pontos_c1++; }
            else if(pib_per_capital_2 > pib_per_capital_1) { printf("Vencedor: Carta 2\n"); pontos_c2++; }
            else printf("Empate!\n");
            break;
        case 6:
            printf("Densidade: Carta 1 = %.2f, Carta 2 = %.2f\n", densidade_1, densidade_2);
            if(densidade_1 < densidade_2) { printf("Vencedor: Carta 1\n"); pontos_c1++; }
            else if(densidade_2 < densidade_1) { printf("Vencedor: Carta 2\n"); pontos_c2++; }
            else printf("Empate!\n");
            break;
    }

    // Comparação do segundo atributo
    switch(atributo2) {
        case 1:
            printf("População: Carta 1 = %lu, Carta 2 = %lu\n", populacao_1, populacao_2);
            if(populacao_1 > populacao_2) { printf("Vencedor: Carta 1\n"); pontos_c1++; }
            else if(populacao_2 > populacao_1) { printf("Vencedor: Carta 2\n"); pontos_c2++; }
            else printf("Empate!\n");
            break;
        case 2:
            printf("Área: Carta 1 = %.2f, Carta 2 = %.2f\n", area_1, area_2);
            if(area_1 > area_2) { printf("Vencedor: Carta 1\n"); pontos_c1++; }
            else if(area_2 > area_1) { printf("Vencedor: Carta 2\n"); pontos_c2++; }
            else printf("Empate!\n");
            break;
        case 3:
            printf("PIB: Carta 1 = %.2f, Carta 2 = %.2f\n", pib_1, pib_2);
            if(pib_1 > pib_2) { printf("Vencedor: Carta 1\n"); pontos_c1++; }
            else if(pib_2 > pib_1) { printf("Vencedor: Carta 2\n"); pontos_c2++; }
            else printf("Empate!\n");
            break;
        case 4:
            printf("Pontos turísticos: Carta 1 = %d, Carta 2 = %d\n", pontos_turisticos_1, pontos_turisticos_2);
            if(pontos_turisticos_1 > pontos_turisticos_2) { printf("Vencedor: Carta 1\n"); pontos_c1++; }
            else if(pontos_turisticos_2 > pontos_turisticos_1) { printf("Vencedor: Carta 2\n"); pontos_c2++; }
            else printf("Empate!\n");
            break;
        case 5:
            printf("PIB per capita: Carta 1 = %.2f, Carta 2 = %.2f\n", pib_per_capital_1, pib_per_capital_2);
            if(pib_per_capital_1 > pib_per_capital_2) { printf("Vencedor: Carta 1\n"); pontos_c1++; }
            else if(pib_per_capital_2 > pib_per_capital_1) { printf("Vencedor: Carta 2\n"); pontos_c2++; }
            else printf("Empate!\n");
            break;
        case 6:
            printf("Densidade: Carta 1 = %.2f, Carta 2 = %.2f\n", densidade_1, densidade_2);
            if(densidade_1 < densidade_2) { printf("Vencedor: Carta 1\n"); pontos_c1++; }
            else if(densidade_2 < densidade_1) { printf("Vencedor: Carta 2\n"); pontos_c2++; }
            else printf("Empate!\n");
            break;
    }

    // Soma dos atributos escolhidos
    float soma1 = 0, soma2 = 0;

    // Adiciona o valor do primeiro atributo
    if(atributo1 == 1) soma1 += populacao_1, soma2 += populacao_2;
    if(atributo1 == 2) soma1 += area_1, soma2 += area_2;
    if(atributo1 == 3) soma1 += pib_1, soma2 += pib_2;
    if(atributo1 == 4) soma1 += pontos_turisticos_1, soma2 += pontos_turisticos_2;
    if(atributo1 == 5) soma1 += pib_per_capital_1, soma2 += pib_per_capital_2;
    if(atributo1 == 6) soma1 += densidade_1, soma2 += densidade_2;

    // Adiciona o valor do segundo atributo
    if(atributo2 == 1) soma1 += populacao_1, soma2 += populacao_2;
    if(atributo2 == 2) soma1 += area_1, soma2 += area_2;
    if(atributo2 == 3) soma1 += pib_1, soma2 += pib_2;
    if(atributo2 == 4) soma1 += pontos_turisticos_1, soma2 += pontos_turisticos_2;
    if(atributo2 == 5) soma1 += pib_per_capital_1, soma2 += pib_per_capital_2;
    if(atributo2 == 6) soma1 += densidade_1, soma2 += densidade_2;

    printf("\n===== SOMA DOS ATRIBUTOS ESCOLHIDOS =====\n");
    printf("Carta 1 (%s - %s): %.2f\n", estado_1, cidade_1, soma1);
    printf("Carta 2 (%s - %s): %.2f\n", estado_2, cidade_2, soma2);

    if(soma1 > soma2) printf("Vencedor da rodada: Carta 1!\n");
    else if(soma2 > soma1) printf("Vencedor da rodada: Carta 2!\n");
    else printf("EMPATE!\n");

    return 0;
}