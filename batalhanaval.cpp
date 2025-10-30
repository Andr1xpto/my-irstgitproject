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

struct Barco {
    string nome;
    int tamanho;
};


const Barco frotas[] = {
    {"Porta-avioes", 5},
    {"Couracado", 4},
    {"Cruzador", 3},
    {"Submarino", 3},
    {"Destroyer", 2}
};
const int numBarcos = sizeof(frotas) / sizeof(frotas[0]);

void inicializarTabuleiro(char tab[Tamanhotab][Tamanhotab]) {
    for (int i = 0; i < Tamanhotab; i++)
        for (int j = 0; j < Tamanhotab; j++)
            tab[i][j] = AGUA;
}

void mostrarTabuleiro(char tab[Tamanhotab][Tamanhotab], bool mostrarNavios) {
    cout << "     ";
    for (int j = 0; j < Tamanhotab; j++) cout << j << " ";
    cout << "\n";

    cout << "   +";
    for (int j = 0; j < Tamanhotab; j++) cout << "--";
    cout << "+\n";

    for (int i = 0; i < Tamanhotab; i++) {
        cout << setw(2) << i << " | ";
        for (int j = 0; j < Tamanhotab; j++) {
            if (!mostrarNavios && tab[i][j] == NAVIO)
                cout << AGUA << " ";
            else
                cout << tab[i][j] << " ";
        }
        cout << "|\n";
    }

    cout << "   +";
    for (int j = 0; j < Tamanhotab; j++) cout << "--";
    cout << "+\n";
}


bool posicaoValida(char tab[Tamanhotab][Tamanhotab], int linha, int coluna, int tamanho, char orientacao) {
    if (orientacao == 'H') {
        if (coluna + tamanho > Tamanhotab) return false;
        for (int j = coluna; j < coluna + tamanho; j++)
            if (tab[linha][j] != AGUA) return false;
    } else if (orientacao == 'V') {
        if (linha + tamanho > Tamanhotab) return false;
        for (int i = linha; i < linha + tamanho; i++)
            if (tab[i][coluna] != AGUA) return false;
    } else {
        return false;
    }
    return true;
}


void colocarBarco(char tab[Tamanhotab][Tamanhotab], int linha, int coluna, int tamanho, char orientacao) {
    if (orientacao == 'H') {
        for (int j = coluna; j < coluna + tamanho; j++)
            tab[linha][j] = NAVIO;
    } else {
        for (int i = linha; i < linha + tamanho; i++)
            tab[i][coluna] = NAVIO;
    }
}


void posicionarFrota(char tab[Tamanhotab][Tamanhotab]) {
    for (int b = 0; b < numBarcos; b++) {
        bool colocado = false;
        while (!colocado) {
            cout << "\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.\n";
            cout << "Posicione o " << frotas[b].nome << " (" << frotas[b].tamanho << " quadrados)\n";
            cout << "Digite linha, coluna inicial e orientacao (H/V): ";

            int linha, coluna;
            char orientacao;
            cin >> linha >> coluna >> orientacao;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "-.-.-.-.Entrada invalida! Tente novamente.-.-.-.-.\n";
                continue;
            }

            orientacao = toupper(orientacao);

            if (linha < 0 || linha >= Tamanhotab || coluna < 0 || coluna >= Tamanhotab) {
                cout << "-.-.-.-.Coordenadas fora do tabuleiro!.-.-.-.-.\n";
                continue;
            }

            if (orientacao != 'H' && orientacao != 'V') {
                cout << "-.-.-.-.Orientacao invalida! Digite H ou V.-.-.-.-.\n";
                continue;
            }

            if (posicaoValida(tab, linha, coluna, frotas[b].tamanho, orientacao)) {
                colocarBarco(tab, linha, coluna, frotas[b].tamanho, orientacao);
                mostrarTabuleiro(tab, true);
                colocado = true;
            } else {
                cout << "-.-.-.-.Posicao invalida! O navio nao cabe ou colide.-.-.-.-.\n";
            }
        }
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
    if (linha < 0 || linha >= Tamanhotab || coluna < 0 || coluna >= Tamanhotab) {
        cout << "-.-.-.-.Tiro fora do tabuleiro!.-.-.-.-.\n";
        return;
    }

    if (tab[linha][coluna] == NAVIO) {
        cout << "-.-.-.-.Acertaste um navio!.-.-.-.-.\n";
        tab[linha][coluna] = TIRO_ACERTO;
    } else if (tab[linha][coluna] == AGUA) {
        cout << "-.-.-.-.Erraste o tiro.-.-.-.-.\n";
        tab[linha][coluna] = TIRO_ERRO;
    } else {
        cout << "-.-.-.-.Ja atiraste aqui!.-.-.-.-.\n";
    }
}

int main() {
    char tab1[Tamanhotab][Tamanhotab], tab2[Tamanhotab][Tamanhotab];
    int linha, coluna;
    bool jogoAtivo = true;

    inicializarTabuleiro(tab1);
    inicializarTabuleiro(tab2);

    cout << "\n-.-.-.-.-.-.-.-.-.BATALHA NAVAL-.-.-.-.-.-.-.-.-.-.-.-.\n";
    cout << "-.Tamanho do tabuleiro: 10x10-.-.-.-.-.-.-.-.-.-.-.\n";
    cout << "-.Cada jogador deve posicionar 5 navios:.-.-.-.-.-.-.-.\n";
    cout << "  Porta-avioes (5), Couracado (4), Cruzador (3), Submarino (3), Destroyer (2)\n";
    cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.\n\n";

    cout << "-.-.-.-.-.Jogador 1-.-.-.-.-.\n";
    mostrarTabuleiro(tab1, true);
    posicionarFrota(tab1);
    system("clear||cls");

    cout << "-.-.-.-.-.Jogador 2-.-.-.-.-.\n";
    mostrarTabuleiro(tab2, true);
    posicionarFrota(tab2);
    system("clear||cls");

    int jogador = 1;
    while (jogoAtivo) {
        cout << "-.-.-.-.-.Vez do Jogador " << jogador << "-.-.-.-.-.\n";

        if (jogador == 1) {
            mostrarTabuleiro(tab2, false);
            cout << "Digite linha e coluna para atacar: ";
            cin >> linha >> coluna;
            atacar(tab2, linha, coluna);

            if (!aindaHaNavios(tab2)) {
                system("clear||cls");
                cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.\n";
                cout << "-.-.-.-.-.Jogador 1 venceu!-.-.-.-.-.\n";
                cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.\n";
                break;
            }
            jogador = 2;
        } else {
            mostrarTabuleiro(tab1, false);
            cout << "Digite linha e coluna para atacar: ";
            cin >> linha >> coluna;
            atacar(tab1, linha, coluna);

            if (!aindaHaNavios(tab1)) {
                system("clear||cls");
                cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.\n";
                cout << "-.-.-.-.-.Jogador 2 venceu!-.-.-.-.-.\n";
                cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.\n";
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
