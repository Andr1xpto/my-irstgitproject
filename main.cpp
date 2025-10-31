#include <iostream>

using namespace std;

void introducao(){
  int escolha;
  bool ativo = false;

  while(ativo){
  cout << "-.-.-.-.-.-.-.-.PC BUILDING SIMULATOR-.-.-.-.-.-.-.-.\n\n";
  cout << "1 - Jogar\n";
  cout << "2 - Créditos\n";
  cout << "3 - Definições\n";
  cin >> escolha;

    
    switch (escolha)
    {
    case 1:
        system("clear");
        cout << "A iniciar o jogo...\n";
        break;
    case 2:
        system("clear");
        cout << "Desenvolviemento: André Medeiros\n";
        break;
    case 3:
        system("clear");
        cout << "Ainda não disponível.\n";
        break;
    default:
        system("clear");
        cout << "Opção inválida, tente novamente!\n";
        break;
    }
  }

}


int main(){

}