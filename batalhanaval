#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int TAM = 10;
const char AGUA = '~';
const char NAVIO = 'N';
const char TIRO_ACERTO = 'X';
const char TIRO_ERRO = 'O';


void inicializarTabuleiro(char tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tab[i][j] = AGUA;
        }
    }
}


void mostrarTabuleiro(char tab[TAM][TAM], bool mostrarNavios) {
    cout << "   ";
    for (int j = 0; j < TAM; j++) cout << j << " ";
    cout << endl;

    for (int i = 0; i < TAM; i++) {
        cout << setw(2) << i << " ";
        for (int j = 0; j < TAM; j++) {
            if (!mostrarNavios && tab[i][j] == NAVIO)
                cout << AGUA << " ";
            else
                cout << tab[i][j] << " ";
        }
        cout << endl;
    }
}


void posicionarNavios(char tab[TAM][TAM], int numNavios) {
    int linha, coluna;
    for (int n = 0; n < numNavios; n++) {
        bool posicaoValida = false;
        while (!posicaoValida) {
            cout << "Posicione o navio #" << n + 1 << " (linha e coluna): ";
            cin >> linha >> coluna;
            if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM && tab[linha][coluna] == AGUA) {
                tab[linha][coluna] = NAVIO;
                posicaoValida = true;
            } else {
                cout << "Posicao invalida! Tente novamente.\n";
            }
        }
        mostrarTabuleiro(tab, true);
    }
}


bool aindaHaNavios(char tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            if (tab[i][j] == NAVIO)
                return true;
    return false;
}


void atacar(char tab[TAM][TAM], int linha, int coluna) {
    if (tab[linha][coluna] == NAVIO) {
        cout << "ACERTOU um navio!\n";
        tab[linha][coluna] = TIRO_ACERTO;
    } else if (tab[linha][coluna] == AGUA) {
        cout << "Errou o tiro.\n";
        tab[linha][coluna] = TIRO_ERRO;
    } else {
        cout << "Ja atirou aqui!\n";
    }
}


int main() {
    //Feito por: André Medeiros e Felipe Baptista

    char tab1[TAM][TAM], tab2[TAM][TAM];
    int numNavios = 5;
    int linha, coluna;
    bool jogoAtivo = true;

    inicializarTabuleiro(tab1);
    inicializarTabuleiro(tab2);

    cout << "===== BATALHA NAVAL =====\n";
    cout << "Tamanho do tabuleiro: 10x10\n";
    cout << "Cada jogador posiciona " << numNavios << " navios.\n\n";

    cout << "--- Jogador 1 ---\n";
    mostrarTabuleiro(tab1, true);
    posicionarNavios(tab1, numNavios);
    system("clear||cls");

    cout << "--- Jogador 2 ---\n";
    mostrarTabuleiro(tab2, true);
    posicionarNavios(tab2, numNavios);
    system("clear||cls");

    int jogador = 1;
    while (jogoAtivo) {
        cout << "===== Vez do Jogador " << jogador << " =====\n";

        if (jogador == 1) {
            mostrarTabuleiro(tab2, false);
            cout << "Digite linha e coluna para atacar: ";
            cin >> linha >> coluna;
            atacar(tab2, linha, coluna);

            if (!aindaHaNavios(tab2)) {
                cout << "\nJogador 1 venceu!\n";
                break;
            }
            jogador = 2;
        } else {
            mostrarTabuleiro(tab1, false);
            cout << "Digite linha e coluna para atacar: ";
            cin >> linha >> coluna;
            atacar(tab1, linha, coluna);

            if (!aindaHaNavios(tab1)) {
                cout << "\nJogador 2 venceu!\n";
                break;
            }
            jogador = 1;
        }

        system("pause"); 
        system("clear||cls"); 
    }

    cout << "===== FIM DE JOGO =====\n";
    return 0;
}
