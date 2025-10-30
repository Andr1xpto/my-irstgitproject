#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int Tamanhotab = 10;
const char AGUA = '~';
const char NAVIO = 'N';
const char TIRO_ACERTO = 'O';
const char TIRO_ERRO = 'X';

void inicializarTabuleiro(char tab[Tamanhotab][Tamanhotab]) {
    for (int i = 0; i < Tamanhotab; i++) {
        for (int j = 0; j < Tamanhotab; j++) {
            tab[i][j] = AGUA;
        }
    }
}

void mostrarTabuleiro(char tab[Tamanhotab][Tamanhotab], bool mostrarNavios) {
    cout << "   ";
    for (int j = 0; j < Tamanhotab; j++) cout << j << " ";
    cout << endl;

    for (int i = 0; i < Tamanhotab; i++) {
        cout << setw(2) << i << " ";
        for (int j = 0; j < Tamanhotab; j++) {
            if (!mostrarNavios && tab[i][j] == NAVIO)
                cout << AGUA << " ";
            else
                cout << tab[i][j] << " ";
        }
        cout << endl;
    }
}

void posicionarNavios(char tab[Tamanhotab][Tamanhotab], int numNavios) {
    int linha, coluna;
    for (int n = 0; n < numNavios; n++) {
        bool posicaoValida = false;
        while (!posicaoValida) {
            cout << "\n-.-.-.-.-.-.-.-.Posicione o navio #" << n + 1 << " (linha e coluna)-.-.-.-.-.-.-.-.\n";
            cin >> linha >> coluna;
            if (linha >= 0 && linha < Tamanhotab && coluna >= 0 && coluna < Tamanhotab && tab[linha][coluna] == AGUA) {
                tab[linha][coluna] = NAVIO;
                posicaoValida = true;
            } else {
                cout << "-.-.-.-.Posicao invalida! Tente novamente.-.-.-.-.-.\n";
            }
        }
        mostrarTabuleiro(tab, true);
    }
}

bool aindaHaNavios(char tab[Tamanhotab][Tamanhotab]) {
    for (int i = 0; i < Tamanhotab; i++)
        for (int j = 0; j < Tamanhotab; j++)
            if (tab[i][j] == NAVIO)
                return true;
    return false;
}

void atacar(char tab[Tamanhotab][Tamanhotab], int linha, int coluna) {
    if (tab[linha][coluna] == NAVIO) {
        cout << "-.-.-.-.Acertaste um navio!-.-.-.-.\n";
        tab[linha][coluna] = TIRO_ACERTO;
    } else if (tab[linha][coluna] == AGUA) {
        cout << "-.-.-.-.Erraste o tiro.-.-.-.-.\n";
        tab[linha][coluna] = TIRO_ERRO;
    } else {
        cout << "-.-.-.-.Ja atiraste aqui!-.-.-.-.\n";
    }
}

int main() {
    char tab1[Tamanhotab][Tamanhotab], tab2[Tamanhotab][Tamanhotab];
    int numNavios = 1;
    int linha, coluna;
    bool jogoAtivo = true;

    inicializarTabuleiro(tab1);
    inicializarTabuleiro(tab2);

    cout << "-.-.-.-.-.-.-.-.-.BATALHA NAVAL-.-.-.-.-.-.-.-.-.-.-.-.\n";
    cout << "-.Tamanho do tabuleiro: 10x10 -.-.-.-.-.-.-.-.-.-.-.-.\n";
    cout << "-.Cada jogador pode posicinar " << numNavios << " navios-.-.-.-.-.-.-.\n";
    cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.\n\n";

    cout << "-.-.-.-.-.Jogador 1-.-.-.-.-.\n";
    mostrarTabuleiro(tab1, true);
    posicionarNavios(tab1, numNavios);
    system("clear||cls");

    cout << "-.-.-.-.-.Jogador 2-.-.-.-.-.\n";
    mostrarTabuleiro(tab2, true);
    posicionarNavios(tab2, numNavios);
    system("clear||cls");

    int jogador = 1;
    while (jogoAtivo) {
        cout << "-.-.-.-.-.Vez do Jogador " << jogador << "-.-.-.-.-.\n";

        if (jogador == 1) {
            mostrarTabuleiro(tab2, false);
            cout << "-.-.-.-.Digite linha e coluna para atacar-.-.-.-.";
            cin >> linha >> coluna;
            atacar(tab2, linha, coluna);

            if (!aindaHaNavios(tab2)) {
                system("clear||cls"); 
                cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.\n";
                cout << "-.-.-.-.-.Jogador 1 venceu!-.-.-.-.-.\n";
                cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.\n";
                break;
            }
            jogador = 2;
        } else {
            mostrarTabuleiro(tab1, false);
            cout << "-.-.-.-.Digite linha e coluna para atacar-.-.-.-.";
            cin >> linha >> coluna;
            atacar(tab1, linha, coluna);

            if (!aindaHaNavios(tab1)) {
                system("clear||cls"); 
                cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.\n";
                cout << "-.-.-.-.-.Jogador 2 venceu!-.-.-.-.-.\n";
                cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.\n";
                break;
            }
            jogador = 1;
        }

        system("pause");
        system("clear||cls");
    }

    cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.\n";
    cout << "-.-.-.-.-.FIM DE JOGO-.-.-.-.-.\n";
    cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.\n";

    return 0;
}
