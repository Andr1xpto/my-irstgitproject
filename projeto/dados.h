    #include <iostream>
    #include <ctime>
    #include <cstdlib>

    using namespace std;

    void primeironomes(){

        srand(time(0));

        string nome[] =  {"Joao", "Francisco", "Vasco", "Andre", "Rodrigo", "Guilherme", "Henrique", "Tadeu" };
        int tamanho = sizeof(nome) / sizeof(nome[0]);
        
        int indice = rand() % tamanho;
        string nomegerado = nome[indice];


        cout << "-----------------------------------------------" << endl;
        cout << "-------- Nome: " << nomegerado << " ";
    }

    void segundonomes(){
    srand(time(0));
    string nomesec[] = {"Almeida", "Sousa", "Medeiros", "Silva", "Franco"};
    int tamanho = sizeof(nomesec) / sizeof(nomesec[0]);

    int indice = rand() % tamanho;
    string nomesecgerado = nomesec[indice];

    
    cout << nomesecgerado << " " << "--------------------"<< endl;

    }

    void paisorigem(){
        srand(time(0));

        string pais[] = {"Portugal", "Franca", "Alemanha", "Italia", "Espanha", "Austria", "Suecia", "Finlandia"};
        int tamanho = sizeof(pais) / sizeof(pais[0]);

        int indice = rand()%tamanho;
        string paisorigemgerado = pais[indice];

        cout << paisorigemgerado << endl;
    }
    
    void idade(){
        srand(time(0));

        int idade = rand() % 70 + 18;

        cout << idade << endl;
    }

    void dataexpiracao(){

        srand(time(0));

        string dataexpiracao [] = {"2 Julho 2002", "25 Setembro 1982", "1 Fevereiro 1999", "3 Agosto 1981", "12 Dezembro 1981"};

        int tamanho = sizeof(dataexpiracao) / sizeof(dataexpiracao[0]);
        int indice = rand() % tamanho;

        string dataexpiracaogerada = dataexpiracao[indice];

        cout << dataexpiracaogerada << endl;
    }