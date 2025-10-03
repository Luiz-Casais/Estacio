#include <stdio.h>

    int main (){
        /*Super Trunfo, jogo de comparação de cartas,
        onde o usuário deve inserir as informações de 2
        cartas de algum estado.      
        */
        
        //Variáveis que guardam os codigos das cartas
        char codigo_1 [5], codigo_2 [5];

        //variáveis que guardam os nomes dos estados
        char estado_1 [17], estado_2 [17];

        //Variáveis que guardam os nomes das cidades
        char cidade_1 [32], cidade_2 [32];

        //Variáveis que guardam o número de população/habitantes
        unsigned long int populacao_1 = 0, populacao_2 = 0;

        //Variáveis que guardam o tamanho em Km² do estado
        float area_1 = 0, area_2 = 0;

        //Variáveis que guardam o valor do PIB em reais
        float pib_1= 0, pib_2 = 0;

        //Variáveis que guardam o número de pontos turísticos
        int pontos_turisticos_1 = 0, pontos_turisticos_2= 0;

        //variaveis de calculo de densidade densidade
        float densidade_1 = 0, densidade_2 = 0;

        //variaveis de calculo do pib per capital
        float pib_per_capital_1 = 0, pib_per_capital_2 = 0;

        //Mensagem de explicação e como utilizar o programa
        printf("olá, seja bem vindo ao Suoer Trunfo, onde iremos Comparar 2 cartas\n"
              "de duas cidades, digitalizando as informações necessárias.\n"
              "(ATENÇÃO: use (.) no lugar de (,)\n");
        
        printf("Digite o código da carta :");
        scanf("%s",&codigo_1);

        printf("Digite o nome do estado :");
        scanf("%s",&estado_1);

        printf("Digite o nome da cidade :");
        scanf("%s",&cidade_1);
        
        printf("Digite o numero da população :");
        scanf("%u",&populacao_1);

        printf("Digite o valor da área em Km² :");
        scanf("%f",&area_1);

        printf("Digite o valor do PIB em bilhoes de reais :");
        scanf("%f",&pib_1);

        printf("Digite a quantidade de pontos turíticos :");
        scanf("%d",&pontos_turisticos_1);

        //calculo da densidade e do pib per capital
        densidade_1 = populacao_1 / area_1;
        pib_per_capital_1= pib_1 * 1000 / populacao_1;

        //Saida das informações coletadas:
        printf("Dados da Primeira carta\n");
        printf("código da carta : %s\n",codigo_1);
        printf("Nome do estado : %s\n",estado_1);
        printf("Nome da cidade : %s\n",cidade_1);
        printf("População : %u\n",populacao_1);
        printf("Área : %.2f\n",area_1);
        printf("PIB : R$%.2f bilhões\n",pib_1);
        printf("Número de pontos turísticos : %d\n",pontos_turisticos_1);
        printf("Densidade populacional : %.2f/km²\n",densidade_1);
        printf("PIB per capita : R$%.2f mil\n",pib_per_capital_1);
        
        
        //Coleta das informações da segunda carta
        
        printf("Digite o código da carta :");
        scanf("%s",&codigo_2);

        printf("Digite o nome do estado :");
        scanf("%s",&estado_2);

        printf("Digite o nome da cidade :");
        scanf("%s",&cidade_2);
        
        printf("Digite o numero da população :");
        scanf("%u",&populacao_2);

        printf("Digite o valor da área em Km² :");
        scanf("%f",&area_2);

        printf("Digite o valor do PIB em Bilhões de reais :");
        scanf("%f",&pib_2);

        printf("Digite a quantidade de pontos turísticos :");
        scanf("%d",&pontos_turisticos_2);

        //calculo da densidade e do pib per capital
        densidade_2 = populacao_2 / area_2;
        pib_per_capital_2= pib_2 * 1000 / populacao_2;

        //Saida das informações coletadas:
        printf("Dados da segunda carta :\n");
        printf("código da carta : %s\n",codigo_2);
        printf("Nome do estado : %s\n",estado_2);
        printf("Nome da cidade : %s\n",cidade_2);
        printf("População : %u\n",populacao_2);
        printf("Área : %.2f\n",area_2);
        printf("PIB : R$%.2f bilhões\n",pib_2);
        printf("Número de pontos turísticos : %d\n",pontos_turisticos_2);
        printf("Densidade populacional : %.2f/km²\n",densidade_2);
        printf("PIB per capita : R$%.2f mil\n",pib_per_capital_2);
        
        // variaveis super poder e comparações
        float super_poder_1 = populacao_1 +area_1 +pib_1 +pontos_turisticos_1 +pib_per_capital_1 +(1/densidade_1);
        float super_poder_2 = populacao_2 +area_2 +pib_2 + pontos_turisticos_2 + pib_per_capital_2 +(1/densidade_2);
        
        printf("\nComparação das cartas\n");
        printf("População : carta %d vence\n",(populacao_1<populacao_2)+1);
        printf("Área : carta %d vence\n",(area_1<area_2)+1);
        printf("PIB : carta %d vence\n",(pib_1<pib_2)+1);
        printf("Pontos Turisticos : carta %d vence\n",(pontos_turisticos_1<pontos_turisticos_2)+1);
        printf("Densidade populacional : carta %d vence\n",(densidade_1<densidade_2)+1);
        printf("PIB per capita : carta %d vence\n",(pib_per_capital_1<pib_per_capital_2)+1);
        printf("Super poder : carta %d vence\n",(super_poder_1<super_poder_2)+1);
    return 0;
}