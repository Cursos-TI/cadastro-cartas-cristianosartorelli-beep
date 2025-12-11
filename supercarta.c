#include <stdio.h>
#include <stdlib.h>

// Definição do tamanho máximo para strings
#define TAMANHO_NOME 50
#define TAMANHO_CODIGO 4 

// ==========================================================
// PASSO 1: DEFINICAO DA STRUCT (O MOLDE)
// ==========================================================
struct Carta {
    char estado;
    char codigo[TAMANHO_CODIGO];
    char nome_cidade[TAMANHO_NOME];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
};

// ==========================================================
// PASSO 2: PROTÓTIPOS DAS FUNÇÕES
// ==========================================================
// Precisamos declarar as funcoes antes do 'main' para que o compilador saiba que elas existem.
// A funcao 'ler_carta' precisa de um PONTEIRO para a struct 
// (struct Carta *c), para poder MODIFICAR a carta original.

/**
 * Funcao para ler os dados de uma carta do teclado.
 * Recebe: Um ponteiro para a struct Carta que sera preenchida.
 */
void ler_carta(struct Carta *c, int numero_carta);

/**
 * Funcao para exibir os dados de uma carta na tela.
 * Recebe: A struct Carta (copia) que contem os dados.
 */
void exibir_carta(struct Carta c, int numero_carta);


// ==========================================================
// PASSO 3: FUNÇÃO PRINCIPAL (MAIN)
// ==========================================================
int main() {
    // Declaração das duas cartas usando o struct
    struct Carta carta1;
    struct Carta carta2;

    printf("====================================================\n");
    printf("        INICIANDO CADASTRO DE CARTAS (NIVEL 3)        \n");
    printf("====================================================\n");

    // Chamando a funcao para preencher a Carta 1
    // Passamos o ENDEREÇO (&carta1) para que a função 'ler_carta' possa modificá-la.
    ler_carta(&carta1, 1);

    // Chamando a funcao para preencher a Carta 2
    ler_carta(&carta2, 2);

    // Exibicao dos Dados
    printf("\n\n====================================================\n");
    printf("              DADOS FINAIS CADASTRADOS              \n");
    printf("====================================================\n");

    // Chamando a funcao para exibir a Carta 1
    exibir_carta(carta1, 1);

    // Chamando a funcao para exibir a Carta 2
    exibir_carta(carta2, 2);
    
    printf("\n====================================================\n");
    
    return 0; 
}


// ==========================================================
// PASSO 4: IMPLEMENTAÇÃO DAS FUNÇÕES
// ==========================================================

// --- Implementacao da Funcao de Leitura ---
void ler_carta(struct Carta *c, int numero_carta) {
    int buffer_limpar; // Variável auxiliar para limpeza
    
    printf("\n--- Leitura da Carta %d ---\n", numero_carta);

    // Lembrete sobre Ponteiros: 
    // Quando trabalhamos com ponteiros para structs, usamos '->' (seta)
    // para acessar os campos, em vez de '.' (ponto).
    // Ex: c->estado é o mesmo que (*c).estado.

    // Limpa o buffer antes de cada chamada para strings/chars
    while ((buffer_limpar = getchar()) != '\n' && buffer_limpar != EOF) {} 

    // 1. Estado (char)
    printf("1. Estado (A-H): ");
    scanf(" %c", &c->estado); // Note o '->'

    // 2. Codigo da Carta (string)
    printf("2. Codigo da Carta (ex: A01): ");
    scanf("%s", c->codigo);

    // 3. Nome da Cidade (string)
    printf("3. Nome da Cidade: ");
    while ((buffer_limpar = getchar()) != '\n' && buffer_limpar != EOF) {}
    fgets(c->nome_cidade, TAMANHO_NOME, stdin);

    // 4. Populacao (int)
    printf("4. Populacao: ");
    scanf("%d", &c->populacao);

    // 5. Area (float)
    printf("5. Area em km2: ");
    scanf("%f", &c->area);

    // 6. PIB (float)
    printf("6. PIB (em bilhoes de reais): ");
    scanf("%f", &c->pib);

    // 7. Numero de Pontos Turisticos (int)
    printf("7. Pontos Turisticos: ");
    scanf("%d", &c->pontos_turisticos);
}

// --- Implementacao da Funcao de Exibicao ---
void exibir_carta(struct Carta c, int numero_carta) {
    // Nesta funcao, recebemos a struct por VALOR (copia), nao por ponteiro.
    // Como nao vamos modificar os dados, usamos o operador '.' normalmente.

    printf("\n--- Carta %d (Cidade %s) ---\n", numero_carta, c.codigo);
    printf("Estado: %c\n", c.estado);
    printf("Codigo: %s\n", c.codigo);
    printf("Nome da Cidade: %s", c.nome_cidade); 
    printf("Populacao: %d\n", c.populacao);
    printf("Area: %.2f km2\n", c.area); 
    printf("PIB: %.2f bilhoes de reais\n", c.pib);
    printf("Numero de Pontos Turisticos: %d\n", c.pontos_turisticos);
}