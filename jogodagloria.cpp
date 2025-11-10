//Feito por André Medeiros

#include <iostream>
#include <cstdlib>
#include <ctime>
#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

using namespace std;

// tabuleiro
void mostrarTabuleiro(int pos1, int pos2) {
    for (int i = 1; i <= 30; i++) {
        if (i == pos1 && i == pos2) {
            cout << "[1|2]";
        } else if (i == pos1) {
            cout << "[1]";
        } else if (i == pos2) {
            cout << "[2]";
        } else if (i == 7 || i == 10 || i == 19 || i == 22 || i == 27) {
            cout << "[*]";
        } else {
            cout << "[" << i << "]";
        }

        if (i % 10 == 0)
            cout << endl;
        else
            cout << " ";
    }
    cout << endl;
}

// verifica casa especial
int verificarCasaEspecial(int posicao, bool &perdeVez, bool &jogaNovamente, bool &espera) {
    switch (posicao) {
        case 7:
            cout << "Casa 7: Perde a vez de jogar!" << endl;
            perdeVez = true;
            break;
        case 10:
            cout << "Casa 10: Retorna 3 casas!" << endl;
            posicao -= 3;
            break;
        case 19:
            cout << "Casa 19: Avança 3 casas!" << endl;
            posicao += 3;
            break;
        case 22:
            cout << "Casa 22: Joga novamente!" << endl;
            jogaNovamente = true;
            break;
        case 27:
            cout << "Casa 27: Espera pela passagem dos outros jogadores!" << endl;
            espera = true;
            break;
        default:
            break;
    }

    if (posicao < 1) posicao = 1;
    if (posicao > 30) posicao = 30;
    return posicao;
}


int main() {
    srand(time(0)); 

    const int NUM_JOGADORES = 2;
    int pos[NUM_JOGADORES] = {1, 1};
    char simbolo[NUM_JOGADORES] = {'1', '2'};
    bool perdeVez[NUM_JOGADORES] = {false, false};
    bool jogaNovamente[NUM_JOGADORES] = {false, false};
    bool espera[NUM_JOGADORES] = {false, false};

    int turno = 0; // começa com o jogador 1
    bool fimDeJogo = false;

    cout << "-.-.-.-.-. JOGO DA GLÓRIA -.-.-.-.-." << endl;
    cout << "Pressione ENTER para começar...";
    cin.ignore();

    while (!fimDeJogo) {
        system(CLEAR);
        cout << "-.-.-.-.-. JOGO DA GLÓRIA -.-.-.-.-." << endl;
        cout << "\nJogador " << simbolo[turno] << endl;
        cout << "------------------------------------" << endl;

        mostrarTabuleiro(pos[0], pos[1]);

        // Verifica se o jogador está à espera
        if (espera[turno]) {
            bool ultrapassado = true;
            for (int j = 0; j < NUM_JOGADORES; j++) {
                if (j != turno && pos[j] <= pos[turno]) {
                    ultrapassado = false;
                    break;
                }
            }
            if (!ultrapassado) {
                cout << "O jogador " << simbolo[turno] << " ainda está à espera de ser ultrapassado.\n";
                turno = (turno + 1) % NUM_JOGADORES;
                cout << "Pressione ENTER para continuar...";
                cin.ignore();
                continue;
            } else {
                cout << "O jogador " << simbolo[turno] << " já foi ultrapassado e pode jogar novamente!\n";
                espera[turno] = false;
            }
        }

        // perda da vez
        if (perdeVez[turno]) {
            cout << "O jogador " << simbolo[turno] << " perdeu a vez!\n";
            perdeVez[turno] = false;
            turno = (turno + 1) % NUM_JOGADORES;
            cout << "Pressione ENTER para continuar...";
            cin.ignore();
            continue;
        }

        // joga normal
        cout << "Pressione ENTER para rolar o dado...";
        cin.ignore();

        int dado = rand() % 6 + 1;
        cout << "Jogador " << simbolo[turno] << " tirou " << dado << " no dado!" << endl;

        pos[turno] += dado;
        if (pos[turno] > 30) pos[turno] = 30;

        cout << "Jogador " << simbolo[turno] << " moveu-se para a casa " << pos[turno] << endl;

        pos[turno] = verificarCasaEspecial(pos[turno], perdeVez[turno], jogaNovamente[turno], espera[turno]);

        if (pos[turno] >= 30) {
            cout << "\nO jogador " << simbolo[turno] << " chegou à casa 30 e venceu o jogo!\n";
            fimDeJogo = true;
            break;
        }

        // joga novamente
        if (jogaNovamente[turno]) {
            cout << "O jogador " << simbolo[turno] << " joga novamente!\n";
            jogaNovamente[turno] = false;
            cout << "Pressione ENTER para continuar...";
            cin.ignore();
            continue;
        }

        // passsa turno
        turno = (turno + 1) % NUM_JOGADORES;
        cout << "Pressione ENTER para continuar...";
        cin.ignore();
    }

    return 0;
}
