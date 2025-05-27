#include <stdio.h>

int main() {
    // Declaração das variáveis para Carta 1
    char estado1, codigo1[4], nome1[50];
    unsigned long int populacao1;
    float area1, pib1;
    int pontosTuristicos1;

    // Declaração das variáveis para Carta 2
    char estado2, codigo2[4], nome2[50];
    unsigned long int populacao2;
    float area2, pib2;
    int pontosTuristicos2;

    // Leitura dos dados da Carta 1
    printf("===== Cadastro da Carta 1 =====\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Digite o Código da Carta (ex: A01): ");
    scanf("%3s", codigo1);
    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", nome1);  // lê string com espaços
    printf("Digite a População: ");
    scanf("%lu", &populacao1);
    printf("Digite a Área (em km²): ");
    scanf("%f", &area1);
    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib1);
    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // Leitura dos dados da Carta 2
    printf("\n===== Cadastro da Carta 2 =====\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Digite o Código da Carta (ex: B02): ");
    scanf("%3s", codigo2);
    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", nome2);
    printf("Digite a População: ");
    scanf("%lu", &populacao2);
    printf("Digite a Área (em km²): ");
    scanf("%f", &area2);
    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculos de densidade populacional e PIB per capita para Carta 1
    float densidade1 = (float)populacao1 / area1;
    float pibPerCapita1 = (pib1 * 1e9) / populacao1; // PIB em bilhões, convertendo para reais

    // Cálculos para Carta 2
    float densidade2 = (float)populacao2 / area2;
    float pibPerCapita2 = (pib2 * 1e9) / populacao2;

    // Cálculo do Super Poder para cada carta
    // Super Poder = população + área + PIB + pontos turísticos + PIB per capita + inverso da densidade
    // Como os tipos são diferentes, convertendo tudo para float para somar
    float superPoder1 = (float)populacao1 + area1 + pib1 + (float)pontosTuristicos1 + pibPerCapita1 + (1.0f / densidade1);
    float superPoder2 = (float)populacao2 + area2 + pib2 + (float)pontosTuristicos2 + pibPerCapita2 + (1.0f / densidade2);

    // Exibição dos dados das cartas
    printf("\n=== Dados da Carta 1 ===\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nome1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);
    printf("Super Poder: %.2f\n", superPoder1);

    printf("\n=== Dados da Carta 2 ===\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nome2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);
    printf("Super Poder: %.2f\n", superPoder2);

    // Comparação dos atributos
    printf("\n=== Comparação de Cartas ===\n");

    int pop1_vence = (populacao1 > populacao2);
    printf("População: Carta %d venceu (%d)\n", pop1_vence ? 1 : 2, pop1_vence);

    int area1_vence = (area1 > area2);
    printf("Área: Carta %d venceu (%d)\n", area1_vence ? 1 : 2, area1_vence);

    int pib1_vence = (pib1 > pib2);
    printf("PIB: Carta %d venceu (%d)\n", pib1_vence ? 1 : 2, pib1_vence);

    int ptur1_vence = (pontosTuristicos1 > pontosTuristicos2);
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", ptur1_vence ? 1 : 2, ptur1_vence);

    // Densidade: vence quem tiver MENOR valor
    int dens1_vence = (densidade1 < densidade2);
    printf("Densidade Populacional: Carta %d venceu (%d)\n", dens1_vence ? 1 : 2, dens1_vence);

    int pibpc1_vence = (pibPerCapita1 > pibPerCapita2);
    printf("PIB per Capita: Carta %d venceu (%d)\n", pibpc1_vence ? 1 : 2, pibpc1_vence);

    int sp1_vence = (superPoder1 > superPoder2);
    printf("Super Poder: Carta %d venceu (%d)\n", sp1_vence ? 1 : 2, sp1_vence);

    return 0;
}
