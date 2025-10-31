#include <iostream>

using namespace std;


struct ferramentas{
    int PenUSB;
    int Pastaterminca;
    int Spraydelimpeza;
};

void opcaoferramenta (){
    int escolha;

    cout << "1 - PenUSB | Utilizada para instalar sistemas operativos e software nos computadores dos clientes." << endl;
    cout << "2 - Pasta Termica | Substância que melhora a transferência de calor entre o processador e o dissipador." << endl;
    cout << "3 - Sray de Limpeza | Spray de ar comprimido usado para remover o pó dos componentes internos." << endl;
    cin >> escolha;

}