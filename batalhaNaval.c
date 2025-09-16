#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define LINHA 10
#define COLUNA 10

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
    char* linha[10] = {'A','B','C','D','E','F','G','H','I','J'};

// For para inicialização da matriz

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

// Posicionamento dos Navios

// Navio 1 - HORIZONTAL

for (int nv1 = 1; nv1 < 4; nv1++){
        tabuleiro[2][nv1] = 3;
}

// Navio 2 - VERTICAL

for (int nv2 = 6; nv2 < 9; nv2++){
        tabuleiro[nv2][9] = 3;
}

// Navio 3 - DIAGONAL 1

for (int nv3_1 = 0, nv3_2 = 9; nv3_1 < 3 && nv3_2 > 6; nv3_1++, nv3_2--){
    for (nv3_2 = 9; nv3_2 > 6; nv3_2--)
    tabuleiro[nv3_1][nv3_2] = 3;
}

// Navio 4 - DIAGONAL 2

for (int nv4_1 = 8, nv4_2 = 1; nv4_1 > 5 && nv4_2 < 4; nv4_1--, nv4_2++){
    tabuleiro[nv4_1][nv4_2] = 3;
}

    // Impressão do tabuleiro

    printf("=== *** Tabuleiro Batalha Naval *** ===\n\n");

    printf("     "); 
    for(int col = 0; col < 10; col++){
        printf("%c ", linha[col]); 
    };

    printf("\n");

    for (int i = 0; i < 10; i++) {

        printf("%2d | ", i + 1);

        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }


    return 0;
}

