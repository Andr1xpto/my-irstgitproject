#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void nomes (){
    srand(time(0));


    string nomes [] = {"Paulo", "Gabriela", "Alberto", "Joana"};
    int tamanho = sizeof(nomes)/sizeof(nomes[0]);
    int indice = rand() % tamanho;

    string nomegerado = nomes[indice];


    cout << "Nome: " << nomegerado << endl;
}

void pedidos(){
    srand(time(0));

    string pedidos [] = {"Meu computador anda fazendo um barulho estranho ultimamente. Achei que fosse o ventilador do quarto, mas parece vir de dentro do gabinete...",
                         "Ele estava funcionando normal ontem, mas hoje simplesmente não liga. As luzes acendem por um segundo e depois apagam",
                         "Depois de uns minutos jogando, a tela congela e o PC reinicia. Será que é vírus?",
                         "Tentei colocar umas luzes novas no gabinete, e desde então nada aparece na tela. Acho que desconectei algo sem querer.",
                         "O computador está muito lento pra abrir qualquer coisa. Demora até pra ligar! Achei que era minha internet, mas nem o explorador de arquivos abre direito.",
                         "Do nada, o PC começou a desligar sozinho. Às vezes fica horas ligado, às vezes desliga logo que entro em um jogo."
    };

    int tamanho = sizeof(pedidos)/sizeof(pedidos[0]);
    int indice = rand() % tamanho;

    string pedidogerado = pedidos[indice];

    cout << "Pedido: " << pedidogerado << endl;

}

