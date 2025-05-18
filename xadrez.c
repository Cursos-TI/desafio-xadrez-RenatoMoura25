#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 8

void inicializar_tabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (i == 1)
                tabuleiro[i][j] = 'P'; // Peões pretos
            else if (i == 6)
                tabuleiro[i][j] = 'p'; // Peões brancos
            else if (i == 0 || i == 7) {
                if (j == 0 || j == 7)
                    tabuleiro[i][j] = (i == 0) ? 'T' : 't'; // Torres
                else if (j == 1 || j == 6)
                    tabuleiro[i][j] = (i == 0) ? 'C' : 'c'; // Cavalos
                else if (j == 2 || j == 5)
                    tabuleiro[i][j] = (i == 0) ? 'B' : 'b'; // Bispos
                else if (j == 3)
                    tabuleiro[i][j] = (i == 0) ? 'Q' : 'q'; // Rainhas
                else
                    tabuleiro[i][j] = (i == 0) ? 'K' : 'k'; // Reis
            } else {
                tabuleiro[i][j] = '.'; // Espaços vazios
            }
        }
    }
}

void exibir_tabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    printf("  ");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAMANHO; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int mover_peca(char tabuleiro[TAMANHO][TAMANHO], int linha_atual, int coluna_atual, int linha_destino, int coluna_destino) {
    if (linha_destino < 0 || linha_destino >= TAMANHO || coluna_destino < 0 || coluna_destino >= TAMANHO) {
        printf("Movimento inválido! Fora do tabuleiro.\n");
        return 0;
    }

    char peca = tabuleiro[linha_atual][coluna_atual];
    if (peca == '.') {
        printf("Não há peça na posição escolhida.\n");
        return 0;
    }

    // Movimento básico de peão (exemplo)
    if ((peca == 'P' && linha_destino == linha_atual + 1 && coluna_destino == coluna_atual) ||
        (peca == 'p' && linha_destino == linha_atual - 1 && coluna_destino == coluna_atual)) {
        tabuleiro[linha_destino][coluna_destino] = peca;
        tabuleiro[linha_atual][coluna_atual] = '.';
        return 1;
    }

    printf("Movimento inválido para a peça escolhida.\n");
    return 0;
}

void jogar() {
    char tabuleiro[TAMANHO][TAMANHO];
    inicializar_tabuleiro(tabuleiro);

    int linha_atual, coluna_atual, linha_destino, coluna_destino;
    int turno = 0; // 0 = jogador 1 (peças maiúsculas), 1 = jogador 2 (peças minúsculas)

    printf("Bem-vindo ao Xadrez!\n");
    while (1) {
        exibir_tabuleiro(tabuleiro);
        printf("Jogador %d, faça sua jogada.\n", turno + 1);
        printf("Escolha linha e coluna da peça: ");
        scanf("%d %d", &linha_atual, &coluna_atual);
        printf("Escolha linha e coluna de destino: ");
        scanf("%d %d", &linha_destino, &coluna_destino);

        if (mover_peca(tabuleiro, linha_atual, coluna_atual, linha_destino, coluna_destino)) {
            turno = 1 - turno; // Alterna entre os jogadores
        }
    }
}

int main() {
    jogar();
    return 0;
}
