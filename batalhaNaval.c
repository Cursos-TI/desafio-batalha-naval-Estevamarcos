#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_HAB 5 // Tamanho fixo das matrizes de habilidade

// Função para inicializar o tabuleiro com os navios
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    // Preenche o tabuleiro com água (0)
    for (int i = 0; i < TAM_TABULEIRO; i++)
        for (int j = 0; j < TAM_TABULEIRO; j++)
            tabuleiro[i][j] = 0;

    // Posiciona os navios com base na saída desejada
    tabuleiro[0][5] = 3;

    tabuleiro[1][4] = 3;
    tabuleiro[1][5] = 3;
    tabuleiro[1][6] = 3;

    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;
    tabuleiro[2][5] = 3;
    tabuleiro[2][6] = 3;
    tabuleiro[2][7] = 3;

    tabuleiro[4][4] = 3;

    tabuleiro[5][2] = 3;
    tabuleiro[5][3] = 3;
    tabuleiro[5][4] = 3;
    tabuleiro[5][5] = 3;
    tabuleiro[5][6] = 3;

    tabuleiro[6][4] = 3;

    tabuleiro[7][2] = 3;

    tabuleiro[8][1] = 3;
    tabuleiro[8][2] = 3;
    tabuleiro[8][3] = 3;

    tabuleiro[9][2] = 3;
}

// Função para criar a matriz de habilidade em forma de cone (apontando para baixo)
void criarHabilidadeCone(int cone[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= TAM_HAB / 2 - i && j <= TAM_HAB / 2 + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }
}

// Função para criar a matriz de habilidade em forma de cruz
void criarHabilidadeCruz(int cruz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }
}

// Função para criar a matriz de habilidade em forma de octaedro (losango)
void criarHabilidadeOctaedro(int octaedro[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }
}

// Função para aplicar a matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                       int habilidade[TAM_HAB][TAM_HAB], int centroX, int centroY) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int tabX = centroX - TAM_HAB / 2 + i;
            int tabY = centroY - TAM_HAB / 2 + j;

            if (tabX >= 0 && tabX < TAM_TABULEIRO && tabY >= 0 && tabY < TAM_TABULEIRO) {
                if (habilidade[i][j] == 1 && tabuleiro[tabX][tabY] == 0) {
                    tabuleiro[tabX][tabY] = 5;
                }
            }
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("  A B C D E F G H I J\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%2d", i + 1);
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    inicializarTabuleiro(tabuleiro);
    criarHabilidadeCone(cone);
    criarHabilidadeCruz(cruz);
    criarHabilidadeOctaedro(octaedro);

    // Aplicação das habilidades nas posições estratégicas
    aplicarHabilidade(tabuleiro, cruz, 4, 4);      // Cruz em linha 5, coluna E
    aplicarHabilidade(tabuleiro, cone, 1, 5);      // Cone em linha 2, coluna F
    aplicarHabilidade(tabuleiro, octaedro, 8, 2);  // Octaedro em linha 9, coluna C

    // Exibe o tabuleiro com as áreas afetadas
    exibirTabuleiro(tabuleiro);

    return 0;
}
