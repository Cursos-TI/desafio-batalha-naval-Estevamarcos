#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Verifica se o navio pode ser posicionado na posição desejada
int podePosicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha, c = coluna;

        if (orientacao == 0) c += i;             // Horizontal
        else if (orientacao == 1) l += i;        // Vertical
        else if (orientacao == 2) { l += i; c += i; } // Diagonal ↘
        else if (orientacao == 3) { l += i; c -= i; } // Diagonal ↙

        // Verifica limites e sobreposição
        if (l < 0 || l >= TAMANHO_TABULEIRO || c < 0 || c >= TAMANHO_TABULEIRO)
            return 0;
        if (tabuleiro[l][c] != AGUA)
            return 0;
    }
    return 1;
}

// Posiciona o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha, c = coluna;

        if (orientacao == 0) c += i;             // Horizontal
        else if (orientacao == 1) l += i;        // Vertical
        else if (orientacao == 2) { l += i; c += i; } // Diagonal ↘
        else if (orientacao == 3) { l += i; c -= i; } // Diagonal ↙

        tabuleiro[l][c] = NAVIO;
    }
}

// Exibe o tabuleiro formatado com letras e números
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("   ");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%c ", 'A' + i);  // Cabeçalho de colunas
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i + 1);  // Números das linhas
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Navio 1: horizontal na linha 2, colunas E-F-G
    if (podePosicionarNavio(tabuleiro, 2, 4, 0)) {
        posicionarNavio(tabuleiro, 2, 4, 0);
    }

    // Navio 2: vertical nas colunas B, linhas 5-6-7
    if (podePosicionarNavio(tabuleiro, 5, 1, 1)) {
        posicionarNavio(tabuleiro, 5, 1, 1);
    }

    // Navio 3: diagonal ↘ começando em linha 2, coluna C (i=2,j=2)
    if (podePosicionarNavio(tabuleiro, 2, 2, 2)) {
        posicionarNavio(tabuleiro, 2, 2, 2);
    }

    // Navio 4: diagonal ↙ começando em linha 6, coluna G (i=6,j=6)
    if (podePosicionarNavio(tabuleiro, 6, 6, 3)) {
        posicionarNavio(tabuleiro, 6, 6, 3);
    }

    exibirTabuleiro(tabuleiro);
    return 0;
}
