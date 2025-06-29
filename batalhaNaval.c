#include <stdio.h>

#define TAMANHO_TABULEIRO 10   // Tamanho fixo do tabuleiro (10x10)
#define TAMANHO_NAVIO 3        // Cada navio ocupa 3 posições
#define AGUA 0                 // Representa água
#define NAVIO 3                // Representa parte do navio

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Verifica se o navio pode ser posicionado (sem sair do tabuleiro e sem sobrepor)
int podePosicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                        int linha, int coluna, int orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + (orientacao == 1 ? i : 0);  // Vertical
        int c = coluna + (orientacao == 0 ? i : 0); // Horizontal

        // Verifica se está dentro dos limites do tabuleiro
        if (l >= TAMANHO_TABULEIRO || c >= TAMANHO_TABULEIRO) {
            return 0;
        }

        // Verifica se já há um navio na posição
        if (tabuleiro[l][c] != AGUA) {
            return 0;
        }
    }
    return 1; // Pode posicionar
}

// Posiciona o navio na matriz do tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                     int linha, int coluna, int orientacao, int navio[TAMANHO_NAVIO]) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + (orientacao == 1 ? i : 0);  // Vertical
        int c = coluna + (orientacao == 0 ? i : 0); // Horizontal
        tabuleiro[l][c] = navio[i];
    }
}

// Exibe o tabuleiro no formato solicitado (letras A-J e números 1-10)
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("   ");
    for (int col = 0; col < TAMANHO_TABULEIRO; col++) {
        printf("%c ", 'A' + col); // Cabeçalho com letras A-J
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i + 1); // Linhas numeradas de 1 a 10
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]); // Exibe cada célula (0 ou 3)
        }
        printf("\n");
    }
}

int main() {
    // Declara o tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa com água
    inicializarTabuleiro(tabuleiro);

    // Vetores representando os navios (cada um com 3 partes = valor 3)
    int navioHorizontal[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};

    // Coordenadas para posicionar os navios
    int linhaHorizontal = 2; // Linha 3 (índice 2)
    int colunaHorizontal = 4; // Coluna E (índice 4)
    int linhaVertical = 5; // Linha 6 (índice 5)
    int colunaVertical = 1; // Coluna B (índice 1)

    // Posiciona o navio horizontal se possível
    if (podePosicionarNavio(tabuleiro, linhaHorizontal, colunaHorizontal, 0)) {
        posicionarNavio(tabuleiro, linhaHorizontal, colunaHorizontal, 0, navioHorizontal);
    } else {
        printf("Erro: Não foi possível posicionar o navio horizontal.\n");
    }

    // Posiciona o navio vertical se possível
    if (podePosicionarNavio(tabuleiro, linhaVertical, colunaVertical, 1)) {
        posicionarNavio(tabuleiro, linhaVertical, colunaVertical, 1, navioVertical);
    } else {
        printf("Erro: Não foi possível posicionar o navio vertical.\n");
    }

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
 