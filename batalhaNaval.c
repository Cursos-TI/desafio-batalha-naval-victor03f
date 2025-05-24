#include <stdio.h>

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[10][10], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para o nível Novato
void nivelNovato() {
    // Criando o tabuleiro 5x5 com valores iniciais 0 (vazio)
    int tabuleiro[5][5] = {{0}};
    
    // Posicionando o navio horizontal (ocupando as posições (2,1), (2,2), (2,3))
    tabuleiro[2][1] = 3;
    tabuleiro[2][2] = 3;
    tabuleiro[2][3] = 3;

    // Posicionando o navio vertical (ocupando as posições (1,3), (2,3), (3,3))
    tabuleiro[1][3] = 3;
    tabuleiro[2][3] = 3;
    tabuleiro[3][3] = 3;

    // Exibindo as coordenadas dos navios
    printf("Nivel Novato\n");
    printf("Coordenadas do navio horizontal:\n");
    printf("(2, 1), (2, 2), (2, 3)\n");

    printf("Coordenadas do navio vertical:\n");
    printf("(1, 3), (2, 3), (3, 3)\n");

    // Exibindo o tabuleiro
    printf("\nTabuleiro Final:\n");
    exibirTabuleiro(tabuleiro, 5);
}

// Função para o nível Aventureiro
void nivelAventureiro() {
    // Criando o tabuleiro 10x10 com valores iniciais 0 (vazio)
    int tabuleiro[10][10] = {{0}};
    
    // Posicionando o navio horizontal (ocupando as posições (2,1), (2,2), (2,3))
    tabuleiro[2][1] = 3;
    tabuleiro[2][2] = 3;
    tabuleiro[2][3] = 3;

    // Posicionando o navio vertical (ocupando as posições (4,4), (5,4), (6,4))
    tabuleiro[4][4] = 3;
    tabuleiro[5][4] = 3;
    tabuleiro[6][4] = 3;

    // Posicionando o navio diagonal 1 (ocupando as posições (1,1), (2,2), (3,3))
    tabuleiro[1][1] = 3;
    tabuleiro[2][2] = 3;
    tabuleiro[3][3] = 3;

    // Posicionando o navio diagonal 2 (ocupando as posições (1,9), (2,8), (3,7))
    tabuleiro[1][9] = 3;
    tabuleiro[2][8] = 3;
    tabuleiro[3][7] = 3;

    // Exibindo o tabuleiro
    printf("Nivel Aventureiro\n");
    printf("\nTabuleiro Final:\n");
    exibirTabuleiro(tabuleiro, 10);
}

// Função para aplicar a habilidade Cone
void aplicarHabilidadeCone(int tabuleiro[10][10], int x, int y) {
    // Padrão Cone
    tabuleiro[x][y] = 1;
    tabuleiro[x+1][y-1] = 1;
    tabuleiro[x+1][y] = 1;
    tabuleiro[x+1][y+1] = 1;
    tabuleiro[x+2][y] = 1;
    tabuleiro[x+2][y+1] = 1;
    tabuleiro[x+2][y-1] = 1;
}

// Função para aplicar a habilidade Cruz
void aplicarHabilidadeCruz(int tabuleiro[10][10], int x, int y) {
    // Padrão Cruz
    tabuleiro[x][y] = 1;
    tabuleiro[x-1][y] = 1;
    tabuleiro[x+1][y] = 1;
    tabuleiro[x][y-1] = 1;
    tabuleiro[x][y+1] = 1;
}

// Função para aplicar a habilidade Octaedro
void aplicarHabilidadeOctaedro(int tabuleiro[10][10], int x, int y) {
    // Padrão Octaedro
    tabuleiro[x][y] = 1;
    tabuleiro[x+1][y] = 1;
    tabuleiro[x+1][y+1] = 1;
    tabuleiro[x+1][y-1] = 1;
    tabuleiro[x+2][y] = 1;
}

// Função para o nível Mestre
void nivelMestre() {
    // Criando o tabuleiro 10x10 com valores iniciais 0 (vazio)
    int tabuleiro[10][10] = {{0}};

    // Aplicar habilidades especiais em pontos específicos
    aplicarHabilidadeCone(tabuleiro, 3, 3);
    aplicarHabilidadeCruz(tabuleiro, 5, 5);
    aplicarHabilidadeOctaedro(tabuleiro, 7, 7);

    // Exibindo o tabuleiro com as áreas afetadas
    printf("Nivel Mestre\n");
    printf("\nTabuleiro com Habilidades:\n");
    exibirTabuleiro(tabuleiro, 10);
}

int main() {
    int nivel;

    // Menu de seleção do nível
    printf("Escolha o nível:\n");
    printf("1 - Nivel Novato\n");
    printf("2 - Nivel Aventureiro\n");
    printf("3 - Nivel Mestre\n");
    printf("Digite o número do nível: ");
    scanf("%d", &nivel);

    // Chama a função correspondente ao nível escolhido
    switch(nivel) {
        case 1:
            nivelNovato();
            break;
        case 2:
            nivelAventureiro();
            break;
        case 3:
            nivelMestre();
            break;
        default:
            printf("Nível inválido! Por favor, escolha 1, 2 ou 3.\n");
    }

    return 0;
}
