#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define LINHA 10
#define COLUNA 10
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 1

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

// Variáveis inicias

    int tabuleiro[LINHA][COLUNA]; 
    char linha[10] = {'A','B','C','D','E','F','G','H','I','J'};

// For para inicialização da matriz

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
// =================================
// *** POSICIONAMENTO DOS NAVIOS ***
// =================================

// --------------------
// NAVIO 1 - HORIZONTAL
// --------------------

for (int nv1 = 3; nv1 < 6; nv1++){
        tabuleiro[4][nv1] = NAVIO;
}

// --------------------
// NAVIO 2 - VERTICAL
// --------------------


for (int nv2 = 6; nv2 < 9; nv2++){
        tabuleiro[nv2][9] = NAVIO;
}

// --------------------
// NAVIO 3 - DIAGONAL 1 DESCRENTE
// --------------------

for (int nv3_1 = 0, nv3_2 = 9; nv3_1 < 3 && nv3_2 > 6; nv3_1++, nv3_2--){
    tabuleiro[nv3_1][nv3_2] = NAVIO;
}

// --------------------
// NAVIO 4 - DIAGONAL 2 CRESCENTE
// --------------------

for (int nv4_1 = 9, nv4_2 = 2; nv4_1 > 6 && nv4_2 < 5; nv4_1--, nv4_2++){
    tabuleiro[nv4_1][nv4_2] = NAVIO;
}

// =================================
//   *** HABILIDADES ESPECIAIS ***
// =================================

// --------------------
//        CONE
// --------------------

int baseA = 3, baseB = 7;
int alt_cone = 3;

for (int i = 0; i < alt_cone; i++) {

    int linha = baseA + i;          // avança a linha
    int inicio = baseB - i;         // começa mais à esquerda
    int fim = baseB + i;            // termina mais à direita

    for (int j = inicio; j <= fim; j++) {
        tabuleiro[linha][j] = HABILIDADE;
    }
}

// --------------------
//        CRUZ
// --------------------

int Cruz_l = 7, Cruz_c = 2;
int alcance = 1; // define o tamanho da cruz
int i = -alcance, j = -alcance;

tabuleiro[Cruz_l][Cruz_c] = HABILIDADE; // Centro da Cruaz

do {
    tabuleiro[Cruz_l + i][Cruz_c] = HABILIDADE; // Vertical da Cruz
    i++;
} while (i <= alcance);


do {
    tabuleiro[Cruz_l][Cruz_c + j] = HABILIDADE; // Horizontal da Cruz
    j++;
} while (j <= alcance);


// --------------------
//       OCTAEDRO
// --------------------

int c_oct1 = 2, c_oct2 = 2;
int tam_oct = 2; // controla o tamanho

for (int i = -tam_oct; i <= tam_oct; i++) {
    int largura;
    if (i < 0) largura = tam_oct + i;
    else largura = tam_oct - i;

    for (int j = -largura; j <= largura; j++){
        tabuleiro[c_oct1 + i][c_oct2 + j] = HABILIDADE;
    }

}

// =================================
//   *** IMPRESSÃO DO TABULEIRO ***
// =================================

    printf("=== *** TABULEIRO BATALHA NAVAL *** ===\n\n");

    printf("     "); 
    for(int col = 0; col < 10; col++){
        printf("%c ", linha[col]); 
    };

    printf("\n");

    for (int i = 0; i < 10; i++) {

        printf("%2d | ", i);

        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }


    return 0;
}

